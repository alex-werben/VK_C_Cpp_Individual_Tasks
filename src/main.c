// Copyright 2022 alex_werben
#include <stdio.h>
#include <stdlib.h>
#include "add_composition.h"
#include "view_composition.h"

enum action_type { ADD = 1, VIEW, EXIT };

char char_input()
{
  char c = '\0';
  int prev = 0;
  int d = 0;

  while (d != '\n') {
    
    d = getchar();
    break;
  }
  printf("%d\n", d);
  // d = c;


  return c;
}

int main(int argc, char* argv[]) {
  int c = 0;

  while (c != EXIT) {
    printf("Choose action:\n");
    printf("\t1 - Add composition\n");
    printf("\t2 - View information about compositions\n");
    printf("\t3 - Exit\n");
    printf("Action: ");

    if (scanf("%d", &c) == 0) {
      printf("Error: number must be written.\n");
      return 1;
    }
    // char s = char_input();

    switch (c) {
      case ADD: add_composition(); break;
      case VIEW: view_composition(); break;
      case EXIT: break;
      default: printf("Wrong action\n"); break;
    }
  }

  return 0;
}
