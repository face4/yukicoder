#include<iostream>
using namespace std;

int main(){
    int A[26] = {};
    int pairs = 0;
    char c;
    for(; cin >> c;){
        int index = (int)(c - 'a');
        A[index]++;
        if(A[index] == 2){
            pairs++;
        }else if (A[index] > 2){
            cout << "Impossible" << endl;
            return 0;
        }
    }

    if(pairs == 6){
        for(int i = 0; i < 26; i++){
            if(A[i] == 1){
                cout << (char)('a' + i) << endl;
                return 0;
                // 雑な実装だが与えられた入力制限下では問題ない
            }
        }
    }else{
        cout << "Impossible" << endl;
        return 0;
    }
   return 0;
}