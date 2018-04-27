#include<iostream>
using namespace std;

int main(){
    int A[13] = {};
    char c;
    bool isDouble = false;
    for(; cin >> c;){
        if(c < 'a' || 'm' < c){
            cout << "Impossible" << endl;
            return 0;
        }
        int index = (int)(c-'a');
        A[index]++;
        if(!isDouble && A[index] == 2){
            isDouble = true;
        }else if(isDouble && A[index] == 2){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    if(isDouble){
        int i;
        for(i = 0; i < 13; i++){
            if(A[i] == 0){
                cout << (char)('a' + i) << endl;
                return 0;
            }
        }
    }else{
        for(int i = 0; i < 13; i++){
            cout << (char)('a' + i) << endl;
        }
    }

    return 0;
}