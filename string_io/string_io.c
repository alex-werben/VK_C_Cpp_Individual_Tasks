// Copyright 2022 alex_werben
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string_io.h"

#define BUFF_SIZE 16

char* read_string_from_stdin() {
  char* str = malloc(BUFF_SIZE * sizeof(char));
  if (!str) {
    return NULL;
  }

  char block[BUFF_SIZE];
  size_t block_count = 1;
  size_t str_size = 0;
  size_t block_size = 0;
  char* block_p = NULL;
  int space_check = 0;

  char c = '\0';

  while (c != '\n') {
    c = getchar();
    if (c == '\n' && !space_check && str_size == 0) {
      space_check = 1;
      c = getchar();
    }
    block[block_size++] = c;
    ++str_size;

    // Reallocate memory
    if (block_size == BUFF_SIZE) {
      block_size = 0;
      ++block_count;

      char* tmp = malloc(block_count * BUFF_SIZE * sizeof(char));
      if (!tmp) {
        if (!str) {
          free(str);
        }
        return NULL;
      }
      if (str) {
        strlcpy(tmp, str, str_size);
        free(str);
      }
      str = tmp;

      block_p = str + ((block_count - 2) * BUFF_SIZE);

      memcpy(block_p, block, BUFF_SIZE);

      str[str_size] = '\0';
    }
  }
  memcpy(str + ((block_count - 1) * BUFF_SIZE), block, block_size);
  str[str_size - 1] = '\0';

  return str;
}

char* read_string_from_file(FILE* fp) {
  char* str = malloc(BUFF_SIZE * sizeof(char));
  if (!str) {
    return NULL;
  }

  char block[BUFF_SIZE];
  size_t block_count = 1;
  size_t str_size = 0;
  size_t block_size = 0;
  char* block_p = NULL;
  int quote_count = 0;

  char c = '\0';
  while (quote_count != 3) {
    if ((c = fgetc(fp)) == EOF) {
      if (str) {
        free(str);
      }
      return NULL;
    }
    if (c == '\"') {
      ++quote_count;
    }
  }

  while (quote_count != 4) {
    c = fgetc(fp);
    if (c == '\"') {
      ++quote_count;
    }
    block[block_size++] = c;
    ++str_size;

    // Reallocate memory
    if (block_size == BUFF_SIZE) {
      block_size = 0;
      ++block_count;

      char* tmp = malloc(block_count * BUFF_SIZE * sizeof(char));
      if (!tmp) {
        if (!str) {
          free(str);
        }
        return NULL;
      }
      if (str) {
        strlcpy(tmp, str, str_size);
        free(str);
      }
      str = tmp;

      block_p = str + ((block_count - 2) * BUFF_SIZE);

      memcpy(block_p, block, BUFF_SIZE);

      str[str_size] = '\0';
    }
  }
  memcpy(str + ((block_count - 1) * BUFF_SIZE), block, block_size);
  str[str_size - 1] = '\0';

  return str;
}

int check_end_file(FILE* fp) {
  char c = fgetc(fp);
  if (c == '{') {
    return 0;
  } else {
    while (fgetc(fp) != '}') continue;
    c = fgetc(fp);
    if (c == ',') {
      return 0;
    } else {
      return 1;
    }
  }
}

int check_for_compositions(FILE* fp) {
  fseek(fp, 0, SEEK_SET);
  char c = fgetc(fp);
  if (c == '[') {             // File is not empty, there's 1+ composition
    fseek(fp, 0, SEEK_END);
    return 0;
  } else {                      // File is empty
    fseek(fp, 0, SEEK_END);
    return 1;
  }
}
