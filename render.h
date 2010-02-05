#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void clear_screen( SDL_Surface* screen);

void draw_box( int x, int y,
	       int w, int h,
	       SDL_Surface* screen);

void init_sdl( SDL_Surface** screen);

void quit_sdl();
