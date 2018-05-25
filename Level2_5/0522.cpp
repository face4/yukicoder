#include<iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n-2; i++){
        for(int j = i; j*2 <= n; j++){
            int k = n-i-j;
            if(k >= j)  printf("%d %d %d\n", i, j, k);
        }
    }

    return 0;
}