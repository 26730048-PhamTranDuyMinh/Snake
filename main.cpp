#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

#define MINX 2
#define MINY 2
#define MAXX 35
#define MAXY 20

struct Point {
    int x;
    int y;
};

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

class Ran {
public:
    Point A[200];  
    int DoDai;

    Ran() {
        DoDai = 3;
        for (int i = 0; i < DoDai; i++) {
            A[i].x = 10 - i;
            A[i].y = 10;
        }
    }

    void Ve() {
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
    }

    void DiChuyen(int Huong) {
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];

        if (Huong == 0) A[0].x = A[0].x + 1;
        if (Huong == 1) A[0].y = A[0].y + 1;
        if (Huong == 2) A[0].x = A[0].x - 1;
        if (Huong == 3) A[0].y = A[0].y - 1;
    }
};

int main() {
    Ran r;
    int Huong = 0;
    char t;

    while (1) {
        if (kbhit()) {
            t = getch();
            if (t == 'd') Huong = 0;
            if (t == 's') Huong = 1;
            if (t == 'a') Huong = 2;
            if (t == 'w') Huong = 3;
        }
        system("cls");
        r.Ve();
        r.DiChuyen(Huong);
        Sleep(300);
    }
    return 0;
}
