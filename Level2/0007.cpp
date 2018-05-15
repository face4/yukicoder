// どうやらbool配列をグローバルで宣言するかローカル(関数内)で宣言するか
// によって初期値が変わるらしい。グローバルで宣言しないと初期値がfalseじゃない
#include<iostream>
#include<vector>
#define MAX 10005
using namespace std;

bool nonPrime[MAX];

vector<int> makePrime(){
    vector<int> prime;
    
    for(int i = 2; i <= MAX; i++){
        if(nonPrime[i]) continue;

        prime.push_back(i);
        for(int j = i+i; j <= MAX; j += i){
            nonPrime[j] = true;
        }
    }

    return prime;
}

bool win[MAX];

int main(){
    int n;
    cin >> n;

    vector<int> p = makePrime();

    win[0] = true;
    win[1] = true;
    for(int i = 2; i <= n; i++){
        for(int j : p){
            if(i-j < 0) break;
            win[i] |= !win[i-j];
        }
    }

    if(win[n])  cout << "Win" << endl;
    else        cout << "Lose" << endl;
    return 0;

}