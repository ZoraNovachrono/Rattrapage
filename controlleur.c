#include <SDL.h>
#include <stdio.h>

#include "controlleur.h"

#define TAILLE  50


//interpreter les inputs du joueur
void action(SDL_Event evenement, int* player1_up, int* player1_down,
    int* player1_right, int* player1_left, int valeur) {
    switch (evenement.key.keysym.sym) {
    case SDLK_z:
        *player1_up = valeur;
        break;
    case SDLK_s:
        *player1_down = valeur;
        break;
    case SDLK_d:
        *player1_right = valeur;
        break;
    case SDLK_q:
        *player1_left = valeur;
        break;
    }
}



//récupère les inputs du joueur
void controller(int* continuer, int* player1_up, int* player1_down,
    int* player1_left, int* player1_right) {
    // Gestion des événements
    SDL_Event event;

    // Récupération de tous les événements en attente
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            *continuer = 0;
        }
        else if (event.type == SDL_KEYDOWN) {
            action(event, player1_up, player1_down, player1_right,
                player1_left, 1);
        }
        else if (event.type == SDL_KEYUP) {
            action(event, player1_up, player1_down, player1_right,
                player1_left, 0);
        }
    }
}


void deplacement(int* dy, int* dx, int player1_up
    , int player1_left, int player1_down, int player1_right) {

    if (player1_up) {
        *dx = 0;
        *dy = -5;
        //printf("up");
    }
    else if (player1_down) {
        *dx = 0;
        *dy = 5;
        //printf("down");
    }
    else if (player1_left) {
        *dx = -5;
        *dy = 0;
        //printf("left");
    }
    else if (player1_right) {
        *dx = +5;
        *dy = 0;
        //printf("right");
    }
}


void deathZone(int x, int y, int* continuer) {
    if (x <= 0 || x + TAILLE >= 1920 || y <= 0 || y + TAILLE >= 1080)
    {
        printf("mort");
        *continuer = 0;
    }
}