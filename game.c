/**
 * @file game.c
 * @author Kaishun Yang kya31 79448199
 * @author Danish Khursheed dkj23 28134926
 * @brief Single player game ucfk4 microcontroller.
 * Initilizes the star chaser game and set up initial state of chaser and stars.
 * @version 0.1
 * @date 2021-10-17
 * @copyright Copyright (c) 2021
 */

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"
#include "message.h"
#include "button.h"
#include "chaser_move.h"
#include "star_pop.h"
#include "game.h"

/**
 * @brief Generate the position of the chaser
 * The logic here is each time chaser moves, we'll delete the previous chaser dot we generated
 * so that it looks like dot is moving.
 * @param chaser is the dot that's generated
 */
static void chaser_pos(chaser_t chaser)
{
    tinygl_clear();
    tinygl_draw_point (chaser.pos, DRAW_A_POINT);
}

/**
 * @brief Generate the position of star
 * The same logic from chaser but this time we toggle the star state to make it flash
 * @param star is the dot being generated 
 */
static void star_pos(star_t star) 
{
    if (star.state == 0) {
        tinygl_draw_point (star.pos, DRAW_A_POINT);    
    }    
    star.state = !star.state;
}

/**
 * @brief The main progam of the game.
 * Set up all chaser and star stats and initialize all required modules and integers.
 * @return int 
 */
int main (void)
{
    chaser_t chaser;
    star_t star;
    int count = COUNT;
    int count2 = COUNT2;
    int star_rate;

    system_init ();
    navswitch_init();
    
    chaser.dir = DIR_N;
    chaser.pos.x = INIT_COL;
    chaser.pos.y = INIT_ROW;
    chaser.game_on = true;
    chaser.speed = INIT_SPEED;
    chaser.mark = INIT_MARK;

    intro_message (); /* Show the intro screen */
    pacer_init(LOOP_RATE);
    tinygl_init(LOOP_RATE);
    star = generate_a_star(chaser); 
    chaser_pos(chaser); /* set up initial positon of chaser */
    star_pos(star); /* set up initial positon of star */
   
    while(1){
        pacer_wait();
        navswitch_update();
        count++;
        count2++;
        /* Set up the if statement to prevent star rate lower than 2 */
        if ((chaser.speed-MINIMUM_RATE) <= MINIMUM_RATE)
        {
            star_rate = MINIMUM_RATE;
        } else {
            star_rate = chaser.speed-MINIMUM_RATE;
        }
        /* Generate a star based on star rate */
        if (count2 > LOOP_RATE / star_rate)
        {
            count2 = 0;
            star_pos(star); 
        }
        /* Generate a chaser based on chaser rate */
        if (count > LOOP_RATE / chaser.speed)
        {
            count = 0;
            chaser = chaser_move (chaser);
            if (chaser.game_on == true) {
                chaser_pos(chaser);
            } else {
                break;
            }
        }
        /* Each time player pushes navswitch, chaser changes direction of movement
        based on the direction it is pushed. */
        if (navswitch_push_event_p (NAVSWITCH_WEST))
        {
            chaser = chaser_make_a_turn (chaser);
        }

        if (navswitch_push_event_p (NAVSWITCH_EAST))
        {
            chaser = chaser_make_a_turn (chaser);
        }
        if (navswitch_push_event_p (NAVSWITCH_NORTH))
        {
            chaser = chaser_make_a_turn (chaser);
        }

        if (navswitch_push_event_p (NAVSWITCH_SOUTH))
        {
            chaser = chaser_make_a_turn (chaser);
        }
        /* If star position overlaps with chasers, that means chaser caught a star so we need
        to generate another star at a random position and increase the mark and speed conditionally. */
        if ((star.pos.x == chaser.pos.x) && (star.pos.y == chaser.pos.y))
        {
            chaser = chaser_get_a_star (chaser);
            star = generate_a_star(chaser);
            chaser_pos(chaser);
            star_pos(star);
        }
        tinygl_update();
    }
    gameover_message (chaser); /* Show the game over screen */
    tinygl_clear();
}

