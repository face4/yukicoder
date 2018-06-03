// dpでも解ける、やれ
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int total = 0, win = 0;
    for(int i = 0; i < 500000; i++){
        int taro = 0, ziro = 0;

        for(int j = 0; j < n-k; j++)    taro += rand()%6 + 1;
        for(int j = 0; j < n; j++)      ziro += rand()%6 + 1;
        for(int j = 0; j < k; j++)      taro += rand()%3 + 4;        

        if(taro > ziro) win++;
        total++;
    }

    cout << fixed << setprecision(9) << (double)win / total << endl;
    return 0;
}