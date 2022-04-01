//how to make colored text: https://www.theurbanpenguin.com/4184-2/

#include "main.h"

void colorRed() {
  printf("\033[0;31m");
}

void colorGreen() {
  printf("\033[1;32m");
}

void colorDefault() {
  printf("\033[0m");
}