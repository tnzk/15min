#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "render.h"

void clear_screen( SDL_Surface* screen)
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void draw_box( int x, int y,
	       int w, int h,
	       SDL_Surface* screen)
{
  glBegin(GL_QUADS);
    glColor3f(1.0, 1.0f, 1.0);
    glVertex3f( x,     y,     0);
    glVertex3f( x + w, y,     0);
    glVertex3f( x + w, y + h, 0);
    glVertex3f( x,     y + h, 0);
  glEnd();
  SDL_GL_SwapBuffers();
}

void sampledraw( Game15min* game)
{
  draw_box( game->x, 0, 32, 240, game->screen);
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
  *screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_OPENGL);
  if( (*screen) == NULL){
    SDL_Quit();
    exit(-1);
  }
  fputs("done.\n", stdout);

  fputs("Initialize OpenGL...", stdout);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, -1.0, 1.0);
  fputs("done.\n", stdout);

}

void quit_sdl()
{
  fputs("Quit sdl...", stdout);
  SDL_Quit();
  fputs("done.\n", stdout);
}
