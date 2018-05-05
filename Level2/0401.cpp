#include<iostream>
#include<iomanip>
using namespace std;

int n, posX, posY, now, nn, A[30][30];

void goRight();
void goLeft();
void goUp();
void goDown();

void init(){
    now = 1;
    nn = n*n;
    posX = -1;
    posY = 0;
    for(int i = 0; i < 30;i++){
        for(int j = 0; j < 30; j++){
            A[i][j] = 0;
        }
    }
}

void goRight(){
    if(now > nn)    return;
    while(++posX < n && A[posY][posX] == 0){
        A[posY][posX] = now++;
    }
    posX--;
    goDown();
}

void goLeft(){
    if(now > nn)    return;
    while(--posX >= 0 && A[posY][posX] == 0){
        A[posY][posX] = now++;
    }

    posX++;
    goUp();
}

void goUp(){
    if(now > nn)    return;
    while(--posY >= 0 && A[posY][posX] == 0){
        A[posY][posX] = now++;
    }
    posY++;
    goRight();
}

void goDown(){
    if(now > nn)    return;
    while(++posY < n && A[posY][posX] == 0){
        A[posY][posX] = now++;
    }
    posY--;
    goLeft();
}

int main(){
    cin >> n;

    init();
    goRight();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j != 0)  printf(" ");
            printf("%03d", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}