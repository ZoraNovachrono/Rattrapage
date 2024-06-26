#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL_image.h>

#include "init.h"
#include "affichage.h"
#include "controlleur.h"
#include "item.h"

//variables
int x = 50;
int y = 50;
int itemX = 500;
int itemY = 500;
int taille = 50;
int continuer = 1;
int player_up = 0;
int player_down = 0;
int player_right = 0;
int player_left = 0;
int dx = 5;
int dy = 0;
int nbreItem = 1;





int main(int argc, char* argv[]) {
    //initialisation
    initSDL();
    SDL_Window* window = initWindow();
    SDL_Renderer* renderer = initRender(window);
    SDL_Texture* texture = loadTexture("../Image/imageBMP.bmp", renderer);
    SDL_Event evenement;
    //randomisation
    srand(time(NULL));

    //boulce du jeu
    while (continuer) {
        //affichage
        clearRendu(renderer);
        renderImage(renderer, texture, 0, 0, 800, 600);

        draw(renderer, x, y, taille, taille, 0, 255, 0);
        spawnItem(renderer, &nbreItem, &itemX, &itemY, x, y);

        controller(&continuer, &player_up, &player_down,
            &player_left, &player_right);
        deplacement(&dy, &dx, player_up, player_left,
            player_down, player_right);

        x += dx; y += dy;

        deathZone(x, y, &continuer);

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }
    //optimisation de la consommation
    void freeAll(renderer, window);
    return 0;
}