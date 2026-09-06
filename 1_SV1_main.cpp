// ##########################################################
// ###  FILE NAY LA CUA:  SV1  (TRUONG NHOM)              ###
// ##########################################################
//
//  DAY LA BAN GOC. SV2 va SV3 KHONG dung file nay.
//
//  SV1 lam gi voi file nay:
//    1. Doi ten file thanh:  main.cpp
//    2. Chep vao thu muc:    E:\Code\Snake
//    3. Dang o branch:       main
//    4. Chay thu: ran XXX chay sang phai, bam W A S D doi huong.
//       CHUA co khung, CHUA co moi -> DUNG ROI, do la viec cua SV2 va SV3.
//    5. Publish repository len GitHub.
//
// ##########################################################

// ============================================================
//  SNAKE - BAI TAP NHOM
//  Ban goc (base) do SV1 - Truong nhom tao va day len GitHub
// ============================================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;

// Kich thuoc khung san choi
#define MINX 2
#define MINY 2
#define MAXX 35
#define MAXY 20

struct Point {
    int x;
    int y;
};

// Dua con tro ve toa do (x, y) tren man hinh console
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

class Ran {
public:
    Point A[200];   // A[0] la dau ran
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
        // Doi cho: than theo duoi dau
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];

        if (Huong == 0) A[0].x = A[0].x + 1;   // sang phai
        if (Huong == 1) A[0].y = A[0].y + 1;   // xuong
        if (Huong == 2) A[0].x = A[0].x - 1;   // sang trai
        if (Huong == 3) A[0].y = A[0].y - 1;   // len
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
