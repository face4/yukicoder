#include<iostream>
using namespace std;

int main(){
    string before, after;
    int n;
    bool result;
    cin >> before >> n >> after;

    int bo = 0, ao = 0, ax = 0, bx = 0;
    for(int i = 0; i < 3; i++){
        if(before[i] == 'o')    bo++;
        else                    bx++;
        if(after[i] == 'o')     ao++;
        else                    bx++;
    }

    if(bo != ao){
        result = true;
    }else if(bo == 3 || bx == 3){
        result = false;
    }else{
        if(bo != 2){
            for(int i = 0; i < 3; i++){
                if(before[i] == 'o')    before[i] = 'x';
                else                    before[i] = 'o';
                if(after[i] == 'o')     after[i] = 'x';
                else                    after[i] = 'o';
            }
        }
        if(n == 0){
            result = (before != after);
        }else if(n == 1){
            result = (before[1] == after[1] && before[1] == 'x') ||
                        (before[0] == after[2] && before[0] == 'x') ||
                            (before[2] == after[0] && before[2] == 'x');
        }else if(n >= 2){
            result = false;
        }
    }

    if(result)  cout << "SUCCESS" << endl;
    else        cout << "FAILURE" << endl;
    return 0;
}