
// NOTE: This program is only compatible with Windows because we couldn't figure out how to detect keyboard input in linux.

#include "main.h"

int main() {

    // Initialize variables
    unsigned char grid[ROWS][COLS];
    int snake[ROWS*COLS][2];
    char keyPress;
    char key = 'd';
    int score = 1;
    int apple[2];
    int alive = 1;
    char c;
    FILE* f;

    srand(time(NULL));


    // Initialize game
    for (int i = 0; i < ROWS*COLS; i++) {
      snake[i][0] = -1;
      snake[i][1] = -1;
    }

    snake[0][0] = ROWS/2-1;
    snake[0][1] = COLS/2-1;

    apple[0] = rand()%ROWS;
    apple[1] = rand()%COLS;
  
    while (apple[0] == snake[0][0] && apple[1] == snake[0][1]) {
      apple[0] = rand()%ROWS;
      apple[1] = rand()%COLS;
    }


    // Display title screen
    system("cls");

    printf("WELCOME TO\n");

    colorGreen();
    f = fopen("./assets/snek.txt", "r");
    while ((c = fgetc(f)) != EOF)
        printf ("%c", c);
    colorDefault();
    fclose(f);

    printf("\nPress space to start...\n");
    while (!(GetKeyState(0x20) < 0)) ;


    // Game loop
    while (alive) {
      
      Sleep(SPEED);     


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
        for (int i = 0; i < ROWS*COLS; i++) {
          while (apple[0] == snake[i][0] && apple[1] == snake[i][1]) {
            apple[0] = rand()%ROWS;
            apple[1] = rand()%COLS;
          }
        }
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
