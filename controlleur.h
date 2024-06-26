#pragma once
#ifndef CONTROLLEUR_H
#define CONTROLLEUR_H

void controller(int* continuer, int* player1_up, int* player1_down,
    int* player1_left, int* player1_right);

void deplacement(int* dy, int* dx, int player1_up
    , int player1_left, int player1_down, int player1_right);

void deathZone(int x, int y, int* continuer);

#endif