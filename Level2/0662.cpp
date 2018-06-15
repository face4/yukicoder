#include<iostream>
#include<map>
using namespace std;

int main(){
    string str[5];
    int coin[5], n[3];
    map<string, int> A[3];
    double a = 0;
    long long u[5];

    for(int i = 0; i < 5; i++){
        cin >> str[i] >> coin[i];
    }

    for(int i = 0; i < 3; i++){
        cin >> n[i];
        for(int j = 0; j < n[i]; j++){
            string s;
            cin >> s;
            A[i][s]++;
        }
    }    

    for(int i = 0; i < 5; i++){
        string s = str[i];
        u[i] = (long long)5 * A[0][s] * A[1][s] * A[2][s];
        a += u[i] * coin[i];
    }

    for(int i = 0; i < 3; i++){
        a /= n[i];
    }

    cout << a << endl;
    for(int i = 0; i < 5; i++){
        cout << u[i] << endl;
    }

    return 0;
}