/**
 * @file chaser_move.c
 * @author Kaishun Yang kya31 79448199
 * @author Danish Khursheed dkj23 28134926
 * @brief Contains all functions that is related to chaser movement.
 * @version 0.1
 * @date 2021-10-17
 * @copyright Copyright (c) 2021
 */

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include <stdint.h>
#include <stdbool.h>
#include "navswitch.h"
#include "chaser_move.h"

#define SIZE 4 /* Size of the array "faster" */

int faster[4] = {3, 5, 7, 10}; /* Speed increment array */


/**
 * @brief Each time run this function, chaser will move one bit based on the direction
 * @param chaser is the dot the player controls.
 * @return chaser_t gives the chaser as a moving dot.
 */
chaser_t chaser_move(chaser_t chaser)
{
    switch (chaser.dir)
    {
        case DIR_N:
            if (chaser.pos.y >= 0) {
                chaser.pos.y = chaser.pos.y - 1;
            } else {
                chaser.game_on = false;
                break;
            }
            break;

        case DIR_E:
            if (chaser.pos.x <= 4) {
                chaser.pos.x = chaser.pos.x + 1;
            } else {
                chaser.game_on = false;
                break;
            }
            break;

        case DIR_S:
            if (chaser.pos.y <= 6) {
                chaser.pos.y = chaser.pos.y + 1;
            } else {
                chaser.game_on = false;
                break;
            }
            break;

        case DIR_W:
            if (chaser.pos.x >= 0) {
                chaser.pos.x = chaser.pos.x - 1;
            } else {
                chaser.game_on = false;
                break;
            }
            break;
    }
    return chaser;
}

/**
 * @brief Each time the navswitch is pushed (except push-down), the chaser changes it's direction
 * based on the direction navswitch has been pushed. 
 * @param chaser is the dot the player controls.
 * @return chaser_t gives the direction of the chaser.
 */
chaser_t chaser_make_a_turn (chaser_t chaser)
{
    if ((chaser.dir == DIR_N)||(chaser.dir == DIR_S)) {
        if (navswitch_push_event_p (NAVSWITCH_EAST)) {
            chaser.dir = DIR_E;
        }
        if (navswitch_push_event_p (NAVSWITCH_WEST)) {
            chaser.dir = DIR_W;
        }
    }
    if ((chaser.dir == DIR_E)||(chaser.dir == DIR_W)) {
        if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
            chaser.dir = DIR_N;
        }
        if (navswitch_push_event_p (NAVSWITCH_SOUTH)) {
            chaser.dir = DIR_S;
        }
    }
    return chaser;
}

/**
 * @brief Chaser will get one mark if it catches a star, and it will increase in speed 
 * if the star it collected is in the speed increment array.
 * @param chaser is the dot the player controls.
 * @return chaser_t gives the speed and mark of the chaser.
 */
chaser_t chaser_get_a_star (chaser_t chaser)
{
    chaser.mark += 1;
    for (int i = 0; i < SIZE; i++) {
        if (chaser.mark == faster[i]) {
            chaser.speed+=1;
        }
    }
    return chaser;
}

