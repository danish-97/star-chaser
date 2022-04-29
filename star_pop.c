/**
 * @file star_pop.c
 * @author Kaishun Yang kya31 79448199
 * @author Danish Khursheed dkj23 28134926
 * @brief This module contains the star generation function.
 * @version 0.1
 * @date 2021-10-17
 * @copyright Copyright (c) 2021
 */

#include <stdlib.h>
#include <stdbool.h>
#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "chaser_move.h"
#include "star_pop.h"
#include <time.h>
#include <avr/io.h>

/**
 * @brief Generates a random star which will not be on the same position
 * as of chaser.
 * @param chaser is the dot the player controls.
 * @return star_t the position and state of the star.
 */
star_t generate_a_star(chaser_t chaser)
{
    star_t star;
    star.state = INIT_STATE;
    srand(TCNT1);
    do {
        star.pos.x = rand()%5;
        star.pos.y = rand()%7;
    } while ((chaser.pos.x == star.pos.x) && (chaser.pos.y == star.pos.y));
    return star;
}
