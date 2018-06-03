#include<iostream>
using namespace std;

int main(){
    int a, b, s, ans;
    cin >> a >> b >> s;

    if(s == 1){
        // 1階でエレベータを呼ぶと絶対にAが来る
        ans = a;
        if(a == 0)  ans = 2;
    }else{
        if(abs(a-s) <= abs(b-s)){
            // Aが来るのでそのまま地下1階まで
            ans = abs(a-s) + s;
        }else{
           // ここが問題、Bのエレベータが優先される場合
           // Aがある階まで行ってからAに乗るパターンと
           // 1階まで降りてからAを呼ぶパターン
           if(a == 0){
               ans = abs(s-b) + 2 + s-1;
           }else{
               ans = abs(s-b) + min(s-1 + a, abs(a-s)+a);
           }
        }
    }

    cout << ans << endl;
    return 0;
}