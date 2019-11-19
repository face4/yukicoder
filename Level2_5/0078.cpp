#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){ // editorial
    int n, k;
    string s;
    cin >> n >> k >> s;
    auto rest = [=](int want, int stock)->int{
        int buy = 0;
        for(int i = 0; i < want; i++){
            if(stock)   stock--;
            else        buy++;
            stock += s[i]-'0';
        }
        return buy;
    };
    int buy = 0, stock = 0;
    for(int i = 0; i < n; i++){
        if(stock)   stock--;
        else        buy++;
        stock += s[i]-'0';
    }
    if(k < n)               cout << rest(k, 0) << endl;
    else if(buy <= stock)   cout << buy << endl;
    else                    cout << buy + rest(k%n, stock) + (k-n)/n*(buy-stock) << endl; 
    /* 最初の箱の中身をすべて入手するために買う必要のある個数　+　
    　最後の箱のk%n個を入手するために買う必要のある個数　+　
    　中間の箱(k-n)/n箱の中身をすべて入手するために買う必要のある個数　*/
    return 0;
}

int main2(){    // 自分の
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int,int>> vp;
    vector<bool> flag(n, 0);
    int pos = 0;
    while(!flag[pos]){
        flag[pos] = true;
        int stock = 1;
        int j = 0;
        while(stock != 0 && j <= n){
            stock--;
            stock += s[(pos+j)%n]-'0';
            j++;
        }
        if(j > n){
            vp.push_back({pos, k}); // 無限
            break;
        }else{
            vp.push_back({pos, j});
            pos = (pos + j)%n;
        }
    }
    vector<pair<int,int>> loop, first;
    int ind = vp.size()-1;
    int loopN = 0;
    do{
        loopN += vp[ind].second;
        loop.push_back(vp[ind]);
    }while(vp[ind--].first != pos);
    while(ind >= 0){
        first.push_back(vp[ind--]);
    }
    reverse(loop.begin(), loop.end());
    reverse(first.begin(), first.end());
    int ret = 0;
    for(int i = 0; i < first.size(); i++){
        k -= first[i].second;
        ret++;
        if(k <= 0)  break;
    }
    if(k <= 0){
        cout << ret << endl;
        return 0;
    }
    ret += k/loopN*(loop.size());
    k %= loopN;
    for(int i = 0; k > 0 && i < loop.size(); i++){
        ret++;
        k -= loop[i].second;
    }
    cout << ret << endl;
    return 0;
}
