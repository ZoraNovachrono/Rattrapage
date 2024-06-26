#pragma once
#ifndef INIT_H
#define INIT_H

void initSDL();

SDL_Window* initWindow();

SDL_Renderer* initRender(SDL_Window* window);

void clearRendu(SDL_Renderer* renderer);

void freeAll(SDL_Renderer* renderer, SDL_Window* window);

#endif