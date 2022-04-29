/**
 * @file message.h
 * @author Kaishun Yang kya31 79448199
 * @author Danish Khursheed dkj23 28134926
 * @brief This module contains all functions that is pertinent 
 * to intro screen and gameover screen.
 * @version 0.1
 * @date 2021-10-17
 * @copyright Copyright (c) 2021
 */

#ifndef MESSAGE_H
#define MESSAGE_H

#include "system.h"
#include "pacer.h"
#include "tinygl.h"
#include "chaser_move.h"
#include "../fonts/font3x5_1.h"
#include <stdio.h> 

void intro_message (void);
void gameover_message (chaser_t chaser);

#endif
