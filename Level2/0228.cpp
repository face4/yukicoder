// 参考 : http://sugarknri.hatenablog.com/entry/2016/05/18/235955
#include<iostream>
using namespace std;

int main(){
    int A[20], count = 0;

    for(int i = 0; i < 16; i++){
        cin >> A[i];
        A[i]--;

        // 空きマスでない
        if(A[i] != -1){
            int d = abs(i/4-A[i]/4) + abs(i%4-A[i]%4);

            // 正しい配置とのマンハッタン距離が2以上->成り立たない
            if(d > 1){
                cout << "No" << endl;
                return 0;
            }else if(d > 0){
                count++;
            }
        }
    }

    int target = -1, i;
    while(target != 15){
        for(i = 0; A[i] != target; i++);
        count--;
        target = i;
    }

    if(count == -1) cout << "Yes" << endl;
    else        cout << "No" << endl;

    return 0;
}