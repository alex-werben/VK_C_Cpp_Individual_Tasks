// Copyright 2022 alex_werben
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_composition.h"
#include "string_io.h"

void add_composition() {
  music_composition* element = malloc(sizeof(music_composition));
  if (!element) {
    return;
  }
  element->author = NULL;
  element->performer = NULL;
  element->title = NULL;
  element->duration = 0;

  printf("Enter author name: ");
  element->author = read_string_from_stdin();
  if (!element->author) {
    delete_a(element);
    return;
  }

  printf("Enter performer name: ");
  element->performer = read_string_from_stdin();
  if (!element->performer) {
    delete_a(element);
    return;
  }

  printf("Enter title name: ");
  element->title = read_string_from_stdin();
  if (!element->title) {
    delete_a(element);
    return;
  }

  printf("Enter song duration: ");
  if (!scanf("%d", &element->duration)) {
    delete_a(element);
    return;
  }

  if (write_data_to_file(element)) {
    return;
  }

  delete_a(element);

  return;
}

int write_data_to_file(music_composition* element) {
  FILE* fp = fopen("data.json", "r+t");
  if (!fp) {
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  if (!check_for_compositions(fp)) {
    fseek(fp, -2, SEEK_END);
    fprintf(fp, ",\n");
  } else {
    fseek(fp, 0, SEEK_SET);
    fprintf(fp, "[\n");
  }


  fprintf(fp, "\t{\n");
  if (fprintf(fp, "\t\t\"author\": \"%s\",\n", element->author) < 0) {
    fclose(fp);
    return 1;
  }

  if (fprintf(fp, "\t\t\"performer\": \"%s\",\n", element->performer) < 0) {
    fclose(fp);
    return 1;
  }

  if (fprintf(fp, "\t\t\"title\": \"%s\",\n", element->title) < 0) {
    fclose(fp);
    return 1;
  }

  if (fprintf(fp, "\t\t\"duration\": \"%d\"\n", element->duration) < 0) {
    fclose(fp);
    return 1;
  }
  fprintf(fp, "\t}\n]");

  if (fclose(fp) != 0) {
    return 1;
  }

  return 0;
}

void delete_a(music_composition * el) {
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
