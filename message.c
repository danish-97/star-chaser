/**
 * @file message.c
 * @author Kaishun Yang kya31 79448199
 * @author Danish Khursheed dkj23 28134926
 * @brief This module contains all functions that is pertinent 
 * to intro screen and gameover screen.
 * @version 0.1
 * @date 2021-10-17
 * @copyright Copyright (c) 2021
 */


#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "button.h"
#include "chaser_move.h"
#include <stdio.h>
#include <message.h>
#include "../fonts/font3x5_1.h"


#define PACER_RATE 500 
#define MESSAGE_RATE 20 // set up message rate to be 20 Hz

/**
 * @brief Set up and display game intro message.
 */
void intro_message (void)
{
    system_init();
    button_init();

    tinygl_init (PACER_RATE);
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
    tinygl_text(" STAR-CHASER ");

    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait();
        button_update ();
        /* If button S2 is pushed, game will starts. */
        if (button_push_event_p (0)) { 
            break;
        }
        tinygl_update();   
    }
}

/**
 * @brief Set up and display game over message.
 * @param chaser is the player.
 */
void gameover_message (chaser_t chaser)
{
    system_init();
    char gameover[18] = "GAME-OVER MARK:";
    char mark[5];
    sprintf(mark, "%u", chaser.mark);
    char string[25];
    sprintf(string, "%s%s", gameover, mark);

    tinygl_init (PACER_RATE);
    tinygl_font_set (&font3x5_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text_dir_set (TINYGL_TEXT_DIR_ROTATE);
    tinygl_text(string);

    pacer_init (PACER_RATE);

    while(1)
    {
        pacer_wait();
        tinygl_update(); 
    }
}
