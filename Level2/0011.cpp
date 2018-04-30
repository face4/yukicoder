#include<iostream>
#include<set>
using namespace std;

typedef long long ll;

int main(){
    ll W, H;
    int n, w, h;
    set<int> ws, hs;
    cin >> W >> H >> n;
    for(int i = 0; i < n; i++){
        cin >> w >> h;
        ws.insert(w);
        hs.insert(h);
    }

    ll ans = W * H - (W - ws.size()) * (H - hs.size()) - n;
    // 補集合を考えるイメージ.第一項はカード全体の枚数、第二項は
    // 全くマッチしないマークの種類×数字の種類、第三項は自分の手
    // 持ち(当然カウントしない)。
    cout << ans << endl; 
    return 0;
}