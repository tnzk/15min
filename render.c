#include <stdio.h>
#include <SDL.h>

void clear_screen( SDL_Surface* screen)
{
  SDL_FillRect(screen, NULL, 0);
}

void draw_box( int x, int y,
	       int w, int h,
	       SDL_Surface* screen)
{
  SDL_Rect box = { x, y, w, h};
  SDL_FillRect(screen, &box, SDL_MapRGB( screen->format, 0x66, 0x00, 0xcc));
}

void init_sdl( SDL_Surface** screen)
{
  printf("Initialize SDL...");   
  if( ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)) { 
    printf("Failed to initialize SDL: %s.\n", SDL_GetError());
    exit(-1);
  }
  printf("done.\n");

  printf("Initialize a video mode...");   
  *screen = SDL_SetVideoMode( 640, 480, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
  if( (*screen) == NULL){
    SDL_Quit();
    exit(-1);
  }
  printf("done.\n");
}

void quit_sdl()
{
  printf("Quit sdl...");
  SDL_Quit();
  printf("done.\n");
}
