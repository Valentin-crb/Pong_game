#include <iostream>
#include <conio.h>
using namespace std;
const int rows=50, cols=200;
const int xborder1=30, xborder2=160; //marginilie tablei pe axa Ox
const int yborder1=10, yborder2=49;  //mariginile tablei pe axa Oy
void draw_table(char tabla[rows][cols]);
void draw_palet(char paleta[rows][cols]);
void move_palet(char paleta[rows][cols], int posY);
int main()
{
    int posy = (yborder1 + yborder2) / 2;
    char tabla[rows][cols];  
    char paleta[rows][cols];   
    draw_table(tabla);
    draw_palet(tabla);
    move_palet(tabla, posy);
    return 0;
}
void draw_table(char tabla[rows][cols])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            tabla[i][j] = ' ';
    for (int j = xborder1; j <= xborder2; j++)
    {
        tabla[yborder1][j] = '-';
        tabla[yborder2][j] = '-';
    }
    for (int i = yborder1; i <= yborder2; i++)
    {
        tabla[i][xborder1] = '|';
        tabla[i][xborder2] = '|';
        tabla[i][(xborder1+xborder2)/2] = '|'; // mijlocul tablei
    }
}
void draw_palet(char paleta[rows][cols])
{
    for (int i = (yborder1+yborder2)/2; i < (yborder1+yborder2)/2 + 5; i++) { //lungimea paletei este de 5
        paleta[i][xborder1+3] = '#';
        paleta[i][xborder1+5] = '#';
    }
    for (int j = xborder1+3; j < xborder1+6; j++) { //latimea paletei de 3
        paleta[(yborder1+yborder2)/2-1][j] = '#';
        paleta[(yborder1+yborder2)/2 + 4][j] = '#';
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            cout << paleta[i][j];
        cout << '\r' << flush;  // afisez tabla
    }
}
void move_palet(char paleta[rows][cols], int posY) {
    if (_kbhit()) {  // Verifică dacă o tastă a fost apăsată
        char n = _getch();  // Obține tasta apăsată
        if (n == 'w' && posY > 10)
            posY--;
        else if (n == 's' && posY < 40 - 5)  // rows este înălțimea paletei
            posY++;
        }
}
