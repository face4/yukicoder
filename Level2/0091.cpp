// 二分探索で解を求める、賢い
// 参考:http://satanic0258.hatenablog.com/entry/2016/04/04/21065n
#include<iostream>
using namespace std;

int v[3];

bool check(int n){
    int R[3];
    long long changeable = 0;
    for(int i = 0; i < 3; i++){
        R[i] = v[i]-n;
        changeable += (R[i] > 0) ? R[i]/2 : R[i];
    }  

    return changeable >= 0;
}

int binarySearch(int low, int high){ // includes low, excludes high
    if(low == high-1)   return low;

    int mid = (low+high)/2;
    if(check(mid)){
        return binarySearch(mid, high);
    }else{
        return binarySearch(low, mid);
    }
}

int main(){
    cin >> v[0] >> v[1] >> v[2];
    cout << binarySearch(0, 1<<24) << endl;
    return 0;
}