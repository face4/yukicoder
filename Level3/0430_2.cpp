#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int nex[26];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[26];
    int acc = 0;
    bool done = false;
    Node(int p=-1, char ch='$') : p(p), pch(ch){
        fill(begin(nex), end(nex), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Node> t(1);

void add_string(const string &s){
    int v = 0;
    for(char c : s){
        int ind = c-'A';
        if(t[v].nex[ind] == -1){
            t[v].nex[ind] = t.size();
            t.emplace_back(v, c);
        }
        v = t[v].nex[ind];
    }
    t[v].leaf = true;
}

int go(int v, char ch);

int get_link(int v){
    if(t[v].link == -1){
        // rootのsuffix linkはroot,1文字のsuffix linkもroot
        if(v == 0 || t[v].p == 0){
            t[v].link = 0;
        }else{
            t[v].link = go(get_link(t[v].p), t[v].pch);
        }
    }
    return t[v].link;
}

int go(int v, char ch){
    int c = ch-'A';
    if(t[v].go[c] == -1){
        if(t[v].nex[c] != -1){
            t[v].go[c] = t[v].nex[c];
        }else{
            t[v].go[c] = v==0 ? 0 : go(get_link(v), ch);
        }
    }
    return t[v].go[c];
}

int calc(int v){
    if(t[v].done){
        return t[v].acc;
    }
    t[v].done = true;
    t[v].acc = t[v].leaf + calc(get_link(v));
    return t[v].acc;
}

int main(){
    string s;
    int m;
    cin >> s >> m;
    while(m--){
        string x;
        cin >> x;
        add_string(x);
    }
    int now = 0, ans = 0;
    for(char c : s){
        now = go(now, c);
        ans += calc(now);
    }
    cout << ans << endl;
    return 0;
}