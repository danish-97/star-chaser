/**
 * @file chaser_move.h
 * @author Kaishun Yang kya31 79448199
 * @author Danish Khursheed dkj23 28134926
 * @brief Contains all functions that is related to chaser movement.
 * @version 0.1
 * @date 2021-10-17
 * @copyright Copyright (c) 2021
 */

#ifndef CHASER_MOVE_H
#define CHASER_MOVE_H

#include "system.h"
#include "tinygl.h"
#include "pacer.h"
#include <stdbool.h>
#include "navswitch.h"


typedef enum dir {DIR_N, DIR_E, DIR_S, DIR_W} dir_t; /* Sets up the direction of the chaser */

typedef struct chaser {
    tinygl_point_t pos; /* Chaser position */
    enum dir dir; /* Chaser direction */
    bool game_on; /* Chaser state. If state is false, game over */
    int speed; /* Chaser speed */
    int mark; /* Final score of player */
} chaser_t;

chaser_t chaser_move(chaser_t chaser);
chaser_t chaser_make_a_turn (chaser_t chaser);
chaser_t chaser_get_a_star (chaser_t chaser);

#endif //CHASER_MOVE_H
