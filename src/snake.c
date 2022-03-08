/*

Create the snake [array of coords]
Max length of snake = area of board

Create a length variable
Increment length every time the snake grows

Pick an empty space for food every time the snake grows

Every frame:
    check the last key press
    move snake in direction of keypress
    wait



  0 1 2 3 4 5 6 7 8 9
0
1
2
3
4
5
6
7
8
9

{{5,5},{5,4}}

*/

#include <stdio.h>
#include <stdlib.h>
#include <winuser.h>

#define ROWS 10
#define COLS 50

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
  printf("+");
  for (int x = 0; x < COLS; x++)
    printf("-");

  printf("+\n");

  // Print Board
  for (int i = 0; i < ROWS; i++) {
    
    printf("|");

    for (int j = 0; j < COLS; j++)
      printf("%c", frame[i][j]);
  
    printf("|\n");
  
  }

  // Print bottom border
  printf("+");
  for (int x = 0; x < COLS; x++)
    printf("-");

  printf("+\n");

}


int main() {

    // Initialize variables
    char grid[ROWS][COLS];
    int snake[ROWS*COLS][2];
    char keyPress;
    char key = 'd';

    // Initialize board
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++){
        grid[i][j] = ' ';
      }
    }

    // Initialize snake
    for (int i = 0; i < ROWS*COLS; i++) {
        snake[i][0] = -1;
        snake[i][1] = -1;
    }

    snake[0][0] = 5;
    snake[0][1] = 5;

    snake[1][0] = 5;
    snake[1][1] = 4;

    snake[2][0] = 5;
    snake[2][1] = 3;

    //while (1) {

      //keyPress = checkKb();

      //if (keyPress != '\0') 
        //key = keyPress;

      for (int i = 0; i < ROWS*COLS; i++)
        grid[snake[i][0]][snake[i][1]] = 178;

      drawFrame(grid);

    //}

    return 0;

}