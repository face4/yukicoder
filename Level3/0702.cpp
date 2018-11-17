#include<iostream>
#include<climits>
using namespace std;

uint32_t x = 0, y = 1, z = 2, w = 3;
int64_t seed;

void init(){
    x = 0, y = 1, z = 2, w = 3;
    x = seed;
}

uint32_t generate() { 
    uint32_t t = (x^(x<<11));
    x = y;
    y = z;
    z = w;
    w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)); 
    return w;
}

bool check(uint32_t mid){
    int cnt = 0;
    init();
    uint32_t tmp;

    for(int i = 0; i < 10000001; i++){
        tmp = generate();
        if(tmp <= mid)    cnt++;
    }

    return cnt >= 5000001;
}

typedef long long ll;

int main(){
    cin >> seed;

    uint32_t l = 0, r = UINT_MAX;

    while(r != l){
        uint32_t mid = l + (r-l)/2;
        if(check(mid))      r = mid;
        else                l = mid+1;
    }

    cout << l << endl;
    
    return 0;
}