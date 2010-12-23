#define MINUE_NUM_STATUSES 1
#define MINUTE_STAT_MAIN 0

typedef struct _Game15min{
  SDL_Surface* screen;
  int status;
  int mode;
  int x;
  void (*ctrl[MINUE_NUM_STATUSES])(struct _Game15min* game);
  void (*draw[MINUE_NUM_STATUSES])(struct _Game15min* game);
} Game15min;

#define MINUTE_DEFINED 1


