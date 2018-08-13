#include<iostream>
using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeap(int x){
    if(x%4 == 0 && x%100 != 0)  return true;
    if(x%400 == 0) return true;
    return false;
}

int main(){
    int y, m, d;
    scanf("%d/%d/%d", &y, &m, &d);
    d += 2;
    int maxd = days[m];
    if(m == 2 && isLeap(y)) maxd++;

    if(d > maxd){
        m++;
        if(m == 13){
            y++;
            m = 1;
        }
        d -= maxd;
    }
    printf("%d/%02d/%02d\n", y, m, d);
    return 0;
}