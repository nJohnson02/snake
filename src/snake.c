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
#include <winuser.h>

#define ROWS 10
#define COLS 10


char checkKb() {
  
  if (GetKeyState(0x57) < 0) return 'w';
  if (GetKeyState(0x41) < 0) return 'a';
  if (GetKeyState(0x53) < 0) return 's';
  if (GetKeyState(0x44) < 0) return 'd';

  return '\0';

}


void drawFrame(int grid) {
  for (int x = 0; )
}


int main() {

    int snake[ROWS*COLS][2] = { {5,5}, {5,4}, {5,3} };
    
    char grid[ROWS][COLS];

    char keyPress;
    char key = 'd';


    //while (1) {

      //keyPress = checkKb();

      //if (keyPress != '\0') 
        //key = keyPress;

      for (int i = 0; i < ROWS*COLS; i++)
        grid[ snake[i][0] ][ snake[i][1] ] = 178;

      drawFrame(grid);

    //}

    return 0;

}