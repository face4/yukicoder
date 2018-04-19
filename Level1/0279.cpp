#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    char c;
    int tre[3] = {0};
    for(;scanf("%c", &c) != EOF;){
        if(c == 't')  tre[0]++;
        else if(c == 'r') tre[1]++;
        else if(c == 'e') tre[2]++;
    }

    tre[2] /= 2;
    int res = *min_element(tre, tre+3);
    
    printf("%d\n" , res);
    return 0;
}