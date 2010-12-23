#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "render.h"

void clear_screen( SDL_Surface* screen)
{

  SDL_Rect dest;
  unsigned int color = 0x00000000;
  dest.x = 0;
  dest.y = 0;
  dest.w = 640;
  dest.h = 480;
  SDL_FillRect( screen, &dest, color );
}

void draw_box( int x, int y,
	       int w, int h,
	       SDL_Surface* screen)
{
  SDL_Rect dest;
  unsigned int color = 0xff9900;
  dest.x = x;
  dest.y = y;
  dest.w = w;
  dest.h = h;
  SDL_FillRect( screen, &dest, color ); 
}

void sampledraw( Game15min* game)
{
  draw_box( game->x, 0, 32, 240, game->screen);
  SDL_Flip(game->screen);
}

void init_sdl( SDL_Surface** screen)
{
  fputs("Initialize SDL...", stdout);
  if( ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)) { 
    printf("Failed to initialize SDL: %s.\n", SDL_GetError());
    exit(-1);
  }
  fputs("done.\n", stdout);

  SDL_WM_SetCaption("15min", NULL);

  fputs("Initialize a video mode...", stdout);
  *screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
  if( (*screen) == NULL){
    SDL_Quit();
    exit(-1);
  }
  fputs("done.\n", stdout);

}

void quit_sdl()
{
  fputs("Quit sdl...", stdout);
  SDL_Quit();
  fputs("done.\n", stdout);
}
