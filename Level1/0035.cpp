#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n, ok = 0, ng = 0, len, tk;
    char str[101];
    scanf("%d" , &n);
    while(n-- > 0){
        scanf("%d %s" , &tk, str);
        len = strlen(str);
        int suc = min(len, (tk*12/1000));
        ok += suc;
        ng += (len-suc);
    }

    printf("%d %d\n" , ok, ng);
    return 0;
}