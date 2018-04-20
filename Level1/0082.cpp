#include<iostream>
using namespace std;

int main(){
    char c, A[2] = {'W', 'B'};
    int w, h, diff = 0;
    cin >> w >> h >> c;
    if(c == 'B') diff = 1;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            printf("%c", A[(i+j+diff)%2]);
        }
        printf("\n");
    }
    return 0;
}