#include<iostream>
#include<set>
#include<random>
using namespace std;

uniform_real_distribution<> dist(0.0, 1.0);

int op(double p, set<int> &a, mt19937 &engine){
    int ret;
    if(a.size() == 1 || dist(engine) <= p){
        ret = *a.begin();
        a.erase(a.begin());
    }else{
        uniform_int_distribution<> tmp(1, a.size()-1);
        int pos = tmp(engine);
        auto it = a.begin();
        while(pos--)    it++;
        ret = *it;
        a.erase(it);
    }
    return ret;
}

int main(){
    int n;
    double pa, pb;
    cin >> n >> pa >> pb;
    set<int> ga, gb;
    int x;
    for(int i = 0; i < n; i++)  cin >> x, ga.insert(x);
    for(int i = 0; i < n; i++)  cin >> x, gb.insert(x);

    random_device rd;
    mt19937 engine(rd());

    double win = 0;
    for(int loop = 0; loop < 100000; loop++){
        set<int> a = ga, b = gb;
        int diff = 0;
        for(int i = 0; i < n; i++){
            int aval = op(pa, a, engine);
            int bval = op(pb, b, engine);
            if(aval > bval) diff += aval+bval;
            if(aval < bval) diff -= aval+bval;
        }
        if(diff > 0)    win++;
    }
    cout << win/100000 << endl;
    return 0;
}