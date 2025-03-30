#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
const int rows=50, cols=200;
const int xborder1=30, xborder2=160; //marginilie tablei pe axa Ox
const int yborder1=10, yborder2=49;  //mariginile tablei pe axa Oy
void draw_table(char tabla[rows][cols]);
void draw_palet(char paleta[rows][cols], int posy);
void move_palet(char paleta[rows][cols], int &posy);
int main()
{
    system("CLS");
    int posy = ((yborder1 + yborder2) / 2) - 1;
    char tabla[rows][cols];  
    char paleta[rows][cols];   
    draw_table(tabla);  // Desenează tabla
    draw_palet(paleta, posy);  // Desenează paleta
    cout<<"Press any key to start the game.\n Press 1 to quit.";
    move_palet(paleta, posy);  // Mișcă paleta
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
void draw_palet(char paleta[rows][cols], int posy)
{
    // Curăță paleta veche
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (paleta[i][j] == '#') 
                paleta[i][j] = ' ';
    // Desenează paleta în poziția corectă
    for (int i = posy; i < posy + 5; i++) { // lungimea paletei este de 5
        paleta[i][xborder1 + 3] = '#';
        paleta[i][xborder1 + 5] = '#';
    }
    for (int j = xborder1 + 3; j < xborder1 + 6; j++) { // lățimea paletei de 3
        paleta[(yborder1 + yborder2) / 2 - 1][j] = '#';
        paleta[(yborder1 + yborder2) / 2 + 4][j] = '#';
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++)
            cout << paleta[i][j];
        cout << '\r' << flush;  // afisez tabla
    }
}
void delete_palet(char paleta[rows][cols], int posy){
    for (int i = posy; i < posy + 5; i++) { 
        paleta[i][xborder1+3] = ' ';
        paleta[i][xborder1+5] = ' ';
    }
    for (int j = xborder1+3; j < xborder1+6; j++) { 
        paleta[(yborder1+yborder2)/2-1][j] = ' ';
        paleta[(yborder1+yborder2)/2 + 4][j] = ' ';
    }
}
void update_palet(char paleta[rows][cols], int posy){
    draw_table(paleta); // Desenează tabla
    draw_palet(paleta, posy); // Desenează paleta
    
}

void move_palet(char paleta[rows][cols], int &posy) {
    while(true){
        if (_kbhit()){
            system("CLS");  // Curăță ecranul la începutul fiecărei actualizări
            char n=_getch();
            if(n=='w' && posy >= yborder1){ //sa nu iasa din masa
                delete_palet(paleta,posy);
                posy--;
                update_palet(paleta,posy);
           }
            if(n=='1') break;  
        }
    }
}
