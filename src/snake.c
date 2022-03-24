#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <winuser.h>


#define ROWS 20
#define COLS 20

//how to make colored text: https://www.theurbanpenguin.com/4184-2/
//ascii table https://www.keepandshare.com/userpics/r/o/b/e/rt/2019-12/sb/screen_shot_2019_12_01_at_3.26.20_pm-34867850.jpg?ts=1575242835

void colorRed() {
  printf("\033[0;31m");
}

void colorGreen() {
  printf("\033[1;32m");
}

void colorDefault() {
  printf("\033[0m");
}

char checkKb() {
  
  if (GetKeyState(0x57) < 0) return 'w';
  if (GetKeyState(0x41) < 0) return 'a';
  if (GetKeyState(0x53) < 0) return 's';
  if (GetKeyState(0x44) < 0) return 'd';
  
  return '\0';

}

void drawFrame(unsigned char frame[ROWS][COLS]) {
  
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
      
      if (frame[i][j] == 219)
        colorRed();
      else
        colorGreen();

      printf("%c%c", frame[i][j], frame[i][j]);

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
int main() {

    // Initialize variables
    unsigned char grid[ROWS][COLS];
    int snake[ROWS*COLS][2];
    char keyPress;
    char key = 'd';
    int score = 1;
    int apple[2];
    int alive = 1;

    srand(time(NULL));

    // Initialize snake
    for (int i = 0; i < ROWS*COLS; i++) {
      snake[i][0] = -1;
      snake[i][1] = -1;
    }

    // Set starting position
    snake[0][0] = ROWS/2-1;
    snake[0][1] = COLS/2-1;

    // Set Starting Apple
    apple[0] = rand()%ROWS;
    apple[1] = rand()%COLS;

    // Game loop
    while (alive) {
      
      Sleep(300);     


      // Move
      for (int i = score-1; i >= 1; i--) {
        snake[i][0] = snake[i-1][0];
        snake[i][1] = snake[i-1][1];
      }


      // Check keyboard
      keyPress = checkKb();
      
      if (keyPress != '\0') { 
        switch (keyPress) {
        case 'w':
          if (key!='s')
            key = keyPress;
          break;
        case 'a':
          if (key!='d')
            key = keyPress;
          break;
        case 's':
          if (key!='w')
            key = keyPress;
          break;
        case 'd':
          if (key!='a')
            key = keyPress;
          break;
        }
      }

      switch (key) {
        case 'w':
          snake[0][0]--;
          break;
        case 'a':
          snake[0][1]--;
          break;
        case 's':
          snake[0][0]++;
          break;
        case 'd':
          snake[0][1]++;
          break;
      }


      // Eat apple
      if (apple[0] == snake[0][0] && apple[1] == snake[0][1]) {
        apple[0] = rand()%ROWS;
        apple[1] = rand()%COLS;
        score++;
      }


      // Check for death
      for (int i = 1; i < ROWS*COLS; i++) {
        if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1])
          alive = 0;
        if (snake[0][0] >= COLS || snake[0][0] < 0)
          alive = 0;
        if (snake[0][1] >= ROWS || snake[0][1] < 0)
          alive = 0;
      }

      if (!alive) break;
      

      // Reset grid
      for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
          grid[i][j] = ' ';
        }
      }


      // Update grid
      for (int i = 0; i < ROWS*COLS; i++) {
        if (snake[i][0] >= 0 && snake[i][1] >= 0)
          grid[snake[i][0]][snake[i][1]] = 178;
      }

      grid[apple[0]][apple[1]] = 219;
      drawFrame(grid);


      //Print Score
      printf("Size: %d\n", score);


    }

    return 0;

}
