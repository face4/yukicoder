// 二分探索。境界条件(?)というか、端っこの処理がイマイチ良く分かっていない。
#include<iostream>
using namespace std;

typedef unsigned long long ll;
ll a, b, c;

ll binarySearch(ll left, ll right){
    while(left+1 < right){
        ll mid = (left+right)/2;
        ll get = (mid-mid/a) + mid/a*b;
        if(get >= c)   right = mid;
        else           left = mid;
    }

    return right;
}

int main(){
    cin >> a >> b >> c;
    //cout << binarySearch(0, c) << endl;
    cout << c/(a+b-1)*a + min(a, c%(a+b-1));
    return 0;
}