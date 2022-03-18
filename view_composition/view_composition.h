#ifndef MUSIC_STRUCT
#define MUSIC_STRUCT

typedef struct music_composition
{
  char* author;
  char* performer;
  char* title;
  int duration;
} music_composition;

#endif

#ifndef VIEW_COMPOSITIONS
#define VIEW_COMPOSITIONS

void view_composition(void);
char* get_author_name();
int read_data_from_file(char*);
void delete_v(music_composition*);

#endif
