#include<iostream>
using namespace std;

int main(){
    int d1,d2,d3,s1;
    scanf("%d %d %d %d", &d1, &d2, &d3, &s1);
    if(s1){
        printf("SURVIVED");
    }else{
        if(d1+d2+d3 >= 2){
            printf("DEAD");
        }else{
            printf("SURVIVED");
        }
    }
    printf("\n");
}