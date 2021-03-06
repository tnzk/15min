#include <SDL.h>
#include <stdio.h>
#include "render.h"

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    Controllers
  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

void samplectrl(Game15min* game)
{
    if(game->mode){
      game->x--;
      if(game->x < 20) game->mode = 0;
    }else{
      game->x++;
      if(game->x > 620) game->mode = 1;
    }
}

int main( int argc, char** argv)
{
  Game15min game;
  SDL_Surface* screen;
  SDL_Event event;
  int done = 0;

  game.mode = 0;
  game.x = 0;
  game.status = MINUTE_STAT_MAIN;

  init_sdl( &screen);
  game.screen = screen;
  game.ctrl[0] = samplectrl;
  game.draw[0] = sampledraw;

  while( !done){
    clear_screen( screen);

    game.ctrl[game.status](&game);
    game.draw[game.status](&game);

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
