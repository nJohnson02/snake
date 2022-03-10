#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winuser.h>


#define ROWS 25
#define COLS 100

char checkKb() {
  
  if (GetKeyState(0x57) < 0) return 'w';
  if (GetKeyState(0x41) < 0) return 'a';
  if (GetKeyState(0x53) < 0) return 's';
  if (GetKeyState(0x44) < 0) return 'd';
  
  return '\0';

}

void drawFrame(char frame[ROWS][COLS]) {
  
  system("cls");

  // Print top border
  for (int i = 0; i < COLS+4; i++)
    printf("%c", 219);

  printf("\n");

  // Print Board
  for (int i = 0; i < ROWS; i++) {
    
    printf("%c%c", 219, 219);
    printf("\033[1;32m");

    for (int j = 0; j < COLS; j++)
      printf("%c", frame[i][j]);

    printf("\033[0m");
    printf("%c%c\n", 219, 219);
  
  }

  // Print bottom border
  for (int i = 0; i < COLS+4; i++)
    printf("%c", 219);

  printf("\n");

}
int main() {

    // Initialize variables
    char grid[ROWS][COLS];
    int snake[ROWS*COLS][2];
    char keyPress;
    char key = 'd';
    int score = 1;

    // Initialize snake
    for (int i = 0; i < ROWS*COLS; i++) {
      snake[i][0] = -1;
      snake[i][1] = -1;
    }

    // Set starting position
    snake[0][0] = ROWS/2;
    snake[0][1] = COLS/2;

    // Game loop
    while (1) {
      
      //sleep(0.2);

      // Check keyboard
      keyPress = checkKb();
      if (keyPress != '\0') 
        key = keyPress;

      // Move
      for (int i = 0; i < ROWS*COLS; i++) {
        switch (key) {
          case 'w':
            snake[i][0]--;
            break;
          case 'a':
            snake[i][1]--;
            break;
          case 's':
            snake[i][0]++;
            break;
          case 'd':
            snake[i][1]++;
            break;
        }
      }
      
      // Reset grid
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++){
          grid[i][j] = ' ';
        }
      }

      // Update grid
      for (int i = 0; i < ROWS*COLS; i++)
        if (snake[i][0] > 0 && snake[i][1] > 0)
          grid[snake[i][0]][snake[i][1]] = 178;

      drawFrame(grid);

    }

    return 0;

}

