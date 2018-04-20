#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int S[6], sum = 0;
    for(int i = 0; i < 6; i++)  cin >> S[i];
    sort(S, S+6);
    for(int i = 1; i <= 4; i++) sum += S[i];

    cout << fixed; // 小数点以下を必ず指定した桁数で表示する(0詰めする)
    cout << setprecision(2) << (sum / 4.0) << endl;
    return 0;
}