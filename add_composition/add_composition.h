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

#ifndef ADD_COMPOSITION
#define ADD_COMPOSITION

void add_composition(void);
int write_data_to_file(music_composition*);
void delete_a(music_composition*);

#endif
