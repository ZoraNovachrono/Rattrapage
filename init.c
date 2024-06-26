#include <SDL.h>
#include <stdio.h>


#include "init.h"


//initialisation.c
void initSDL() {
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to load SDL\n");
        return -1;
    }

}

SDL_Window* initWindow() {
    // create SDL window
    SDL_Window* window = SDL_CreateWindow("SDL Project",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        800, 600, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Failed to create window\n");
        SDL_Quit();
        return -1;
    }
    return window;
}

SDL_Renderer* initRender(SDL_Window* window) {
    // create render 
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Failed to create renderer\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    return renderer;
}

void clearRendu(SDL_Renderer* renderer) {
    // Clear rendu + set white color 
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void freeAll(SDL_Renderer* renderer, SDL_Window* window) {
    // free all
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

