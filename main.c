#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void scc(int code){
    if (code < 0){
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }
}

void *scp(void *ptr){
    if (ptr == NULL){
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }
    return ptr;
}

int main(void){
    scc(SDL_Init(SDL_INIT_VIDEO));

    SDL_Quit();
    return 0;
}
