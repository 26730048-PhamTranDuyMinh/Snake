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

void VeKhung() {
    for (int i = MINX; i <= MAXX; i++)
        for (int j = MINY; j <= MAXY; j++)
            if ((i == MINX) || (i == MAXX) || (j == MINY) || (j == MAXY)) {
                gotoxy(i, j);
                printf("+");
            }
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

    void Ve(Point Qua) {
        for (int i = 0; i < DoDai; i++) {
            gotoxy(A[i].x, A[i].y);
            cout << "X";
        }
        gotoxy(Qua.x, Qua.y); cout << "*";
    }

    void DiChuyen(int Huong, Point& Qua) {
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];

        if (Huong == 0) A[0].x = A[0].x + 1;
        if (Huong == 1) A[0].y = A[0].y + 1;
        if (Huong == 2) A[0].x = A[0].x - 1;
        if (Huong == 3) A[0].y = A[0].y - 1;

        if ((A[0].x == Qua.x) && (A[0].y == Qua.y)) {
            DoDai++;
            Qua.x = rand() % (MAXX - MINX) + MINX;
            Qua.y = rand() % (MAXY - MINY) + MINY;
        }
    }
};

int main() {
    Ran r;
    int Huong = 0;
    char t;

    Point Qua;
    srand((int)time(0));
    Qua.x = rand() % (MAXX - MINX) + MINX;
    Qua.y = rand() % (MAXY - MINY) + MINY;

    while (1) {
        if (kbhit()) {
            t = getch();
            if (t == 'd') Huong = 0;
            if (t == 's') Huong = 1;
            if (t == 'a') Huong = 2;
            if (t == 'w') Huong = 3;
        }
        system("cls");
        VeKhung();
        r.Ve(Qua);
        r.DiChuyen(Huong, Qua);
        Sleep(300);
    }
    return 0;
}
