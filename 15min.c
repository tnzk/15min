#include <SDL.h>
#include <stdio.h>

void init_sdl()
{
  puts("Initialize SDL...");   
  if( (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == -1)) { 
    printf("Failed to initialize SDL: %s.\n", SDL_GetError());
    exit(-1);
  }
  puts("SDL initialization was successful.");
}

void quit_sdl()
{
  printf("Quit sdl...");
  SDL_Quit();
  puts("done");
}

int main()
{
  init_sdl();

  quit_sdl();
  return 0;
}
