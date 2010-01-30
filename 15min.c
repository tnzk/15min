#include <SDL.h>
#include <stdio.h>

void draw_box( int x, int y,
	       int w, int h,
	       SDL_Surface* screen)
{
  SDL_Rect box;
  box.x = x;
  box.y = y;
  box.w = w;
  box.h = h;
  SDL_FillRect(screen, &box, SDL_MapRGB( screen->format, 0x66, 0x00, 0xcc));
  SDL_UpdateRect(screen, 0, 0, 0, 0);
}

void init_sdl( SDL_Surface** screen)
{
  printf("Initialize SDL...");   
  if( (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == -1)) { 
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

int main( int argc, char** argv)
{
  SDL_Surface* screen;
  SDL_Event event;
  int done = 0;
  int i;

  init_sdl( &screen);
  draw_box( 0, 0, 320, 240, screen);

  while( !done){
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
