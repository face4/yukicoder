// AC後追記
// posの前準備をするのは頭が悪い
// 初期状態は全ての街に居ると仮定した方が簡潔でよい
// mapとvectorを組み合わせるよりa,b,cからなる構造体を作ってしまったほうが早い

#include<iostream>
#include<map>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    map<int, vector<pair<int,int>>> pay;

    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        pay[c].push_back(make_pair(a,b));
        pay[c].push_back(make_pair(b,a));
    }

    set<int> pos;
    cin >> a;
    for(pair<int,int> p : pay[a]){
        pos.insert(p.second);
    }

    for(int i = 1; i < k; i++){
        cin >> a;
        set<int> after;
        for(int j = 0; j < pay[a].size(); j++){
            pair<int,int> p = pay[a][j];
            if(pos.find(p.first)!=pos.end())    after.insert(p.second);
        }

        pos = after;

        // cout << "after " << a << endl;
        // for(auto p : pos){
        //     cout << p << endl;
        // }
    }

    set<int>::iterator it = pos.begin();
    cout << pos.size() << endl;
    for(int i = 0; i < pos.size(); i++){
        if(i)   cout << " ";
        cout << *it;
        it++;
    }
    cout << endl;

    return 0;
}