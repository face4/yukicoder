#include<iostream>
using namespace std;

int main(){
    int n, a0, ak, grade = 1;
    scanf("%d", &n);
    scanf("%d", &a0);

    printf("1\n");
    n--;

    while(n-- > 0){
        scanf("%d" , &ak);
        if(ak > a0) grade++;
        printf("%d\n", grade);
    }
    return 0;
}