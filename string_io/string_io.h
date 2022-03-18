#ifndef STRING_IO
#define STRING_IO

char* read_string_from_stdin(void);
char* read_string_from_file(FILE*);
int check_end_file(FILE* fp);
int check_for_compositions(FILE* fp);

#endif