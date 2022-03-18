// Copyright 2022 alex_werben
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view_composition.h"
#include "string_io.h"

void view_composition() {
  printf("Enter author name you're interested in: ");
  char* author = read_string_from_stdin();
  if (!author) {
    return;
  }
  printf("__________\n");
  printf("Author name - %s\n", author);
  printf("__________\n");

  if (read_data_from_file(author)) {
    free(author);
    return;
  }

  free(author);
}

int read_data_from_file(char * author) {
  music_composition* element = malloc(sizeof(music_composition));
  if (!element) {
    return 1;
  }
  element->author = NULL;
  element->performer = NULL;
  element->title = NULL;
  element->duration = 0;

  FILE* fp = fopen("data.json", "r");
  if (!fp) {
    delete_v(element);
    return -1;
  }

  char* str = NULL;

  while (!check_end_file(fp)) {  
    str = read_string_from_file(fp);
    if (str) {
      element->author = str;
    }

    str = read_string_from_file(fp);
    if (str) {
      element->performer = str;
    }

    str = read_string_from_file(fp);
    if (str) {
      element->title = str;
    }

    str = read_string_from_file(fp);
    if (str) {
      element->duration = atoi(str);
    }

    if (!strcmp(author, element->author)) {
      if (!strcmp(element->author, element->performer)) {
        printf("Song title: %s\n", element->title);
        printf("Duration: %d\n", element->duration);
        printf("__________\n");
      }
    }

    free(element->author);
    free(element->performer);
    free(element->title);
    free(str);

    element->author = NULL;
    element->performer = NULL;
    element->title = NULL;
  }

  delete_v(element);

  if (fclose(fp) != 0) {
    return -1;
  }

  return 0;
}

void delete_v(music_composition * el) {
  if (!el)
    return;

  if (el->author)
    free(el->author);
  if (el->performer)
    free(el->performer);
  if (el->title)
    free(el->title);

  free(el);

  return;
}
