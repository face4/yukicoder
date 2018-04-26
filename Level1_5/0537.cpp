#include<iostream>
#include<cmath>
#include<set>

using namespace std;

int main(){
    long long  n;
    cin >> n;
    set<string> data;
    double x = sqrt(n);
    for(long long  i = 1; i <= x; i++){
        if(n%i == 0){
            string s = to_string(i) + to_string(n/i);
            string t = to_string(n/i) + to_string(i);
            data.insert(s);
            data.insert(t);
        }
    }

    cout << data.size() << endl;
    return 0;
}