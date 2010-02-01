#include <SDL.h>
#include <stdio.h>
#include "15min.h"
#include "render.h"

int main( int argc, char** argv)
{
  SDL_Surface* screen;
  SDL_Event event;
  int done = 0;
  int mode = 0;
  int x = 0;

  init_sdl( &screen);

  while( !done){
    clear_screen( screen);

    if(mode){
      x--;
      if(x < 20) mode = 0;
    }else{
      x++;
      if(x > 620) mode = 1;
    }

    draw_box( x, 0, 32, 240, screen);
    SDL_UpdateRect(screen, 0, 0, 0, 0);

    while( SDL_PollEvent(&event)){
      switch( event.type){
      case SDL_KEYDOWN:
	if( event.key.keysym.sym == SDLK_ESCAPE){
	  done = 1;
	}
	break;
      case SDL_QUIT:
	done = 1;
	break;
      }
    }
  }

  quit_sdl();
  return 0;
}
