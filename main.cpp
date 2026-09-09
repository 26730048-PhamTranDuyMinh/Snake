// ##########################################################
// ###  FILE NAY LA CUA:  SV2                             ###
// ##########################################################
//
//  Phan viec cua SV2: VE KHUNG SAN CHOI
//
//  SV2 lam gi voi file nay:
//    1. TAO BRANCH TRUOC DA:  Ve-Khung   (tao tu branch main)
//       Chua tao branch ma da chep file la SAI.
//    2. Doi ten file thanh:  main.cpp
//    3. Chep DE LEN file main.cpp cu trong thu muc:  E:\Code\Snake2
//    4. Chay thu: phai thay khung dau '+' bao quanh, ran chay ben trong.
//    5. Commit -> Push origin -> Create Pull Request
//
//  So voi ban goc cua SV1, file nay chi them 11 dong o 2 cho:
//    - Them nguyen ham VeKhung()  (dat ngay truoc  class Ran)
//    - Them 1 dong  VeKhung();    (trong main, ngay sau system("cls"))
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

// --- SV2 them: ve khung san choi bang dau '+' ---
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
    Point A[200];   // A[0] la dau ran
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
        // Doi cho: than theo duoi dau
        for (int i = DoDai - 1; i > 0; i--)
            A[i] = A[i - 1];

        if (Huong == 0) A[0].x = A[0].x + 1;   // sang phai
        if (Huong == 1) A[0].y = A[0].y + 1;   // xuong
        if (Huong == 2) A[0].x = A[0].x - 1;   // sang trai
        if (Huong == 3) A[0].y = A[0].y - 1;   // len
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
        VeKhung();
        r.Ve();
        r.DiChuyen(Huong);
        Sleep(300);
    }
    return 0;
}
