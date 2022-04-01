#include "main.h"

void drawFrame(unsigned char grid[ROWS][COLS]) {
  
  system("cls");

  // Print top border
  for (int i = 0; i < 2*COLS+4; i++)
    printf("%c", 219);

  printf("\n");

  // Print board
  for (int i = 0; i < ROWS; i++) {
    
    // Left border
    printf("%c%c", 219, 219);
    
    for (int j = 0; j < COLS; j++) {
      
      if (grid[i][j] == 219)
        colorRed();
      else
        colorGreen();

      printf("%c%c", grid[i][j], grid[i][j]);

    }

    colorDefault();

    // Right border
    printf("%c%c\n", 219, 219);
  
  }

  // Print bottom border
  for (int i = 0; i < 2*COLS+4; i++)
    printf("%c", 219);

  printf("\n");

}