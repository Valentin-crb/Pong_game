#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int ROWS=30, COLS=70;
const int XBORDER1=10, XBORDER2=60;
const int YBORDER1=5, YBORDER2=29;
int ballx= (XBORDER1 + XBORDER2) / 2;
int bally= (YBORDER1 + YBORDER2) / 2;
int balldirx = 1; //+1 in dreapta -1 in stanga
int balldiry = 1; //+1 in sus -1 in jos
void draw_table(char board[][COLS], int posy, int ypos);
void print_board(char board[][COLS]);
void move_palet(char board[][COLS], int &posy, int &ypos);
void draw_ball(char board[ROWS][COLS], int &bpos);
void setConsoleSettings();
void hideCursor();

int main() {
    setConsoleSettings();
    
    int posy = (YBORDER1 + YBORDER2) / 2;
    int ypos = (YBORDER1 + YBORDER2) / 2;
    char board[ROWS][COLS];

    draw_table(board, posy, ypos);
    print_board(board);

    cout << "\nUse W/S or I/K to move, press 1 to quit.";
    
    move_palet(board, posy, ypos);

    return 0;
}

void setConsoleSettings() {
    // Hide cursor for better performance
    hideCursor();

    // Maximize console window
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);
}

void hideCursor() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(console, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // Hide cursor
    SetConsoleCursorInfo(console, &cursorInfo);
}

void draw_table(char board[][COLS], int posy, int ypos) {
    // Fill board with empty spaces
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = ' ';

    // Draw borders
    for (int j = XBORDER1; j <= XBORDER2; j++) {
        board[YBORDER1][j] = '-';
        board[YBORDER2][j] = '-';
    }
    for (int i = YBORDER1; i <= YBORDER2; i++) {
        board[i][XBORDER1] = '|';
        board[i][XBORDER2] = '|';
    }

    // Draw paddle
    for (int i = posy; i < posy + 5; i++) {
        board[i][XBORDER1 + 3] = '#';
    }

    // Draw 2nd paddle
    for (int i = ypos; i < ypos + 5; i++) {
        board[i][XBORDER2 - 3] = '#';
    }
}

void print_board(char board[][COLS]) {
    string output;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            output += board[i][j];
        output += "\n";
    }
    system("cls"); // Clear screen
    cout << output; // Print entire frame at once
}

void move_palet(char board[][COLS], int &posy, int &ypos) {
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if ((key == 'w' || key == 'W') && posy > YBORDER1+1) {
                posy--;
            } 
            if ((key == 's' || key == 'S') && posy + 5 < YBORDER2) {
                posy++;
            }
            if ((key == 'i' || key == 'I') && ypos > YBORDER1+1) {
                ypos--;
            }
            if ((key == 'k' || key == 'K') && ypos + 5 < YBORDER2) {
                ypos++;
            }
            if (key == '1') break;

            draw_table(board, posy, ypos);
            print_board(board);
        }
    }
}
void draw_ball(char board[ROWS][COLS], int &bposx, int &bposy){
    string ball = "@";
    int i=bposx;
    int j=bposy;
    while((i>XBORDER1 && i<XBORDER2) && (j>YBORDER1 && j<YBORDER2)){

    }
}
