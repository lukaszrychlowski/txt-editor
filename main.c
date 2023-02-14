
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>

#include "/Users/ryszard/txt-editor/font.h"

void scc(int code){
    if (code < 0){
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }
}

void *scp(void *ptr){                        //sdl check pointer
    if (ptr == NULL){
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }
    return ptr;
}

int main(void){
    scc(SDL_Init(SDL_INIT_VIDEO));
    SDL_Window *window = scp(SDL_CreateWindow(
                            "txt-editor",
                            0, 0, 800, 600,
                            SDL_WINDOW_RESIZABLE));

    SDL_Renderer *renderer = 
        scp(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));

    SDL_Surface *surface = 
        scp(SDL_CreateRGBSurfaceFrom(
            FONT, FONT_WIDTH, FONT_HEIGHT,
            8, FONT_WIDTH,
            255, 255, 255, 255));

    SDL_Texture *texture =
        scp(SDL_CreateTexture(
                renderer,
                SDL_PIXELFORMAT_INDEX8,
                SDL_TEXTUREACCESS_STATIC, 
                FONT_WIDTH, FONT_HEIGHT));

    bool quit = false;
    while (!quit){
        SDL_Event event = {0}; 
        while (SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT: {
                    quit = true;
                } 
                break;
                } 
            }
            scc(SDL_SetRenderDrawColor(renderer, 10, 10, 0, 0));
            scc(SDL_RenderClear(renderer));
            SDL_RenderPresent(renderer);
    }
    SDL_Quit();
    return 0;
}
