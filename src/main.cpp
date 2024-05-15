#include <SDL2/SDL.h>
#include <iostream>

int main() 
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            680, 480,
            0);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    if(!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Event e;
    bool quit = false;

    while (!quit){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_KEYDOWN){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }

        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


        SDL_RenderPresent(renderer);
    }

    SDL_Quit();

    return 0;
}
