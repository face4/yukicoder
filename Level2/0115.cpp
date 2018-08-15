#include<iostream>
#include<vector>
using namespace std;

#define inRange(x, a, b) a <= x && x <= b

int main(){
    
    int n, d, k;
    cin >> n >> d >> k;

    int minimum = k * (k+1) / 2;
    int maximum = (n-k+1 + n) * k / 2;

    if(d < minimum || maximum < d){
        cout << -1 << endl;
        return 0;
    }

    vector<int> v;
    for(int i = 1; k != 0 && i <= n; i++){
        int tmp = d-i;
        if(tmp == 0){
            v.push_back(i);
            k--;
            break;
        }

        if(inRange(tmp, (2*i+k)*(k-1)/2, (n-k+2 + n) * (k-1) / 2)){
            v.push_back(i);
            k--;
            d -= i;
        }
    }

    for(int i = 0; i < v.size(); i++)   cout << v[i] << " \n"[i == v.size()-1];

    return 0;
}