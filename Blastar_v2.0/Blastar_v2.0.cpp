
/*
    ----CODE FOR THE GAME BLASTAR v2.0
        Programmed By Samip Gyawali
        CODE BEGINS BELOW------
*/
//header files
#include <iostream>
#include<conio.h>
#include<Windows.h>
#include<string.h>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75

//global variables declarations;
bool gameOver, bullFire,eneDeath, noKill;

int gunX, gunY, eneX, eneY, height, width, bullX, bullY, life, score;


void initialize() {
    life = 69;
    bullFire = false;
    gameOver = false;
    eneDeath = false;
    noKill = false;
    height = 25;
    width = 100;
    eneX = rand() % (width-1);
    eneY = 0;
    gunY = height - 1;
    gunX = (width-5) / 2;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            gunX -= 2;
            break;
        case 'd':
            gunX+=2;
            break;
        case 'f':
            bullFire = true;
            break;
        }
    }
}

void gameLogic() {
    
    if (gunX < 0) {
        gunX = width - 1;
    }
    if (gunX > width) {
        gunX = 0;
    }
    eneY+=1;

    if (bullFire==true) {
        bullX = gunX;
        bullY = gunY;
        
    }
    bullY-=1;
   

    if (eneY > height) {
        noKill = true;
   }

    if (noKill) {
        eneX = rand() % width;
        eneY = 0;
        life -= 1;
        /*if (score > 0) {
            score -= 10;
        }*/
        noKill = false;
    }

    if (eneDeath) {
        eneX = rand() % width;
        eneY = 0;
        score += 10;
        eneDeath = false;
    }

    if (life == 0) {
        gameOver = true;
    }
    
    
    
}

void disPlay() {
    
    system("CLS");
    for (int i = 1; i <= width; i++) {
        cout << "*";
    }
    cout << endl;

    for (int i = 1; i < height; i++) {
        for (int j = 1; j <= width; j++) {
            if (j == 1 || j==width) {
                cout << "*";
            }


            else if (i == gunY && j == gunX) {
                cout << "F";
            }

            else if (i == eneY && j == eneX) {
                cout << "!";
               
            }

            else if (i == bullY && j == bullX) {
                cout << "O";
            }
            else {
                cout << " ";
            }

            if (eneY == bullY && eneX == bullX) {
                eneDeath = true;
                bullX = 0;
                bullY = height + 1;
            }
            if (eneY == gunY && eneX == gunX) {
                gameOver = true;
            }

        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= width; i++) {
        cout << "*";
    }
    bullFire = false;
}



int main(){
    string check;
    cout << "                                               Welcome to Blastar v2.0";
    cout << "\n                                             Programmed By: Samip Gyawali"; 

    cout << "\n\n" << "                                                     Controls:";
    cout << "\n\n" << "                                                     A:Left";
    cout << "\n\n" << "                                                     D:Right";
    cout << "\n\n" << "                                                     F:Fire";
    cout << "\n    1.Your are last line of defence.\n    2.Its a losing battle. \n    3.If spaceship hits you you die. \n    3.If more than 69 spaceships cross you you lose. ";
    cout << "\n Begin?(Y/N)";
    cin >> check;
    
    if (check == "Y" || check == "y") {



        initialize();
        while (!gameOver) {
            input();
            gameLogic();
            disPlay();

            cout << "\nLife remaining: " << life;
            cout << "\nScore: " << score;
            Sleep(30);
        }
        cout << "\nGame Over";
    }
    else {
        system("CLS");
        cout << "You quitted the game";
    }
    return 0;
}

