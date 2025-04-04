#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int ROWS=30;
const int COLS=70;
const int XBORDER1=10;
const int XBORDER2=60;
const int YBORDER1=5;
const int YBORDER2=25;
char board[ROWS][COLS];
int balldirx = 1; //+1 in dreapta -1 in stanga
int balldiry = 1; //+1 in sus -1 in jos
int posy = (YBORDER1 + YBORDER2) / 2;
int ypos = (YBORDER1 + YBORDER2) / 2;

void start();
void draw_table(int posy, int ypos);
void print_board();
void move_palet(int &posy, int &ypos);
void draw_ball(int ballx, int bally);
void move_ball(int &bposx, int &bposy, int &bdirx, int &bdiry, int posy, int ypos);
void setConsoleSettings();
void hideCursor();

int main() {
    cout << "\nPress any key to start.\nUse W/S or I/K to move, press 1 to quit.";
    start();
    return 0;
}

void start(){
    setConsoleSettings();
    _getch();
    move_palet(posy, ypos);
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

void draw_table(int posy, int ypos) {
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

void print_board() {
    string output;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            output += board[i][j];
        output += "\n";
    }
    system("cls"); // Clear screen
    cout << output; // Print entire frame at once
}

void move_palet(int &posy, int &ypos) {
    int ballX = (XBORDER1 + XBORDER2) / 2;
    int ballY = (YBORDER1 + YBORDER2) / 2;
    int ballDirX = 1, ballDirY = 1;
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if ((key == 'w' || key == 'W') && posy > YBORDER1+1) posy--;
            if ((key == 's' || key == 'S') && posy + 5 < YBORDER2) posy++;
            if ((key == 'i' || key == 'I') && ypos > YBORDER1+1) ypos--;
            if ((key == 'k' || key == 'K') && ypos + 5 < YBORDER2) ypos++;
            if (key == '1') break;
        }
        draw_table(posy, ypos);
        move_ball(ballX, ballY, ballDirX, ballDirY, posy, ypos);
        print_board();
        Sleep(15);
    }
}

void draw_ball(int ballx, int bally){
    board[bally][ballx]='@';
}

void move_ball(int &bposx, int &bposy, int &bdirx, int &bdiry, int posy, int ypos) {
    // Șterge mingea din poziția curentă
    board[bposy][bposx] = ' ';

    // Actualizează poziția mingii
    bposx += bdirx;
    bposy += bdiry;

    // Coliziune cu marginea de sus sau jos
    if (bposy <= YBORDER1 + 1 || bposy >= YBORDER2 - 1) {
        bdiry *= -1; // Schimbă direcția pe axa Y
    }

    // Coliziune cu paleta din stânga
    if (bposx == XBORDER1 + 4 && (bposy >= posy && bposy <= posy + 5)) {
        bdirx *= -1; // Schimbă direcția pe axa X
    }

    // Coliziune cu paleta din dreapta
    if (bposx == XBORDER2 - 4 && (bposy >= ypos && bposy <= ypos + 5)) {
        bdirx *= -1; // Schimbă direcția pe axa X
    }
    if (bposx <= XBORDER1 || bposx >= XBORDER2) {
        bposx = (XBORDER1 + XBORDER2) / 2;
        bposy = (YBORDER1 + YBORDER2) / 2;
        bdirx = -bdirx; // Schimbă direcția la cineva care a pierdut
    }
    draw_ball(bposx, bposy);
}


