/**
 * @file star_pop.h
 * @author Kaishun Yang kya31 79448199
 * @author Danish Khursheed dkj23 28134926
 * @brief This module contains the star generation function.
 * @version 0.1
 * @date 2021-10-17
 * @copyright Copyright (c) 2021
 */


#ifndef STAR_POP_H
#define STAR_POP_H

#include <stdlib.h>
#include <stdbool.h>
#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include "chaser_move.h"

#define INIT_STATE 0 /* The initial state of star is 0, this is only for implementing flashing */

typedef struct star {
    tinygl_point_t pos; /* Position of the star */
    int state; /* State of the star */
} star_t;

star_t generate_a_star(chaser_t chaser);

#endif
