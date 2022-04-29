/**
 * @file game.h
 * @author Kaishun Yang kya31 79448199
 * @author Danish Khursheed dkj23 28134926
 * @brief Single player game ucfk4 microcontroller.
 * Initilizes the star chaser game and set up initial state of chaser and stars.
 * @version 0.1
 * @date 2021-10-17
 * @copyright Copyright (c) 2021
 */

#ifndef GAME_H
#define GAME_H

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "navswitch.h"
#include "message.h"
#include "button.h"
#include "chaser_move.h"
#include "star_pop.h"


#define LOOP_RATE 1000 /* Sets the loop rate to 1000 */
#define INIT_SPEED 3 /* Chaser initial speed is 3 Hz */
#define INIT_MARK 0 /* Set up player mark at 0 */
#define INIT_COL 2 /* Chaser initial x coordiniate */
#define INIT_ROW 6 /* Chaser initial y coordiniate */
#define DRAW_A_POINT 1 /* The number of pixel each time draw the point */
#define COUNT 0 /* Set up an integer for chaser in pacer loop */
#define COUNT2 0 /* Set up an integer for star in pacer loop */
#define MINIMUM_RATE 2 /* the minimum rate for flashing is 2 Hz, otherwise it will disappears.*/

int main (void);

#endif //GAME_H