#include <iostream>
#include <conio.h>
using namespace std;
void draw_table(char tabla[50][200]);
void draw_palet(char paleta[8][3]);

int main()
{
    char tabla[50][200];  
    char paleta[8][3];   
    draw_table(tabla);

    return 0;
}
void draw_table(char tabla[50][200])
{
    for (int i = 0; i < 50; i++)
        for (int j = 0; j < 200; j++)
            tabla[i][j] = ' ';
    for (int j = 30; j <= 160; j++)
    {
        tabla[10][j] = '-';
        tabla[30][j] = '-';
    }
    for (int i = 10; i <= 30; i++)
    {
        tabla[i][30] = '|';
        tabla[i][160] = '|';
        tabla[i][100] = '|'; // mijlocul tablei
    }
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 200; j++)
            cout << tabla[i][j];
        cout << endl;  // Afișăm o linie nouă după fiecare linie a tablei
    }
}
void draw_palet(char paleta[8][3])
{
    for (int i = 0; i < 8; i++) {
        paleta[i][0] = '|';
        paleta[i][2] = '|';
    }
    for (int j = 0; j < 3; j++) {
        paleta[0][j] = '-';
        paleta[7][j] = '-';
    }
}
void move_palet(char paleta[8][3], int& posY) {
    if (_kbhit()) {  // Verifică dacă o tastă a fost apăsată
        char n = _getch();  // Obține tasta apăsată
        if (n == 'w' && posY > 10)
            posY--;
        else if (n == 's' && posY < 40 - 8)  // 8 este înălțimea paletei
            posY++;
        }
}
