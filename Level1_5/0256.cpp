#include<iostream>
using namespace std;

int main(){
    int nums[10] = {};
    string s;
    cin >> s;
    char c;
    for(int i = 0; i < s.length(); i++){
        c = s[i];
        nums[(int)(c-'0')]++;
    }

    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < nums[i]; j++){
            printf("%d", i);
        }
    }

    printf("\n");
    return 0;
}