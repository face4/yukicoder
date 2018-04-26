#include<iostream>
using namespace std;

bool isKadomatu(int a1, int a2, int a3){
    return (a1 != a3) && (a2-a1)*(a2-a3) > 0;
}

int main(){
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if(isKadomatu(a1,a2,a3)){
        cout << "INF" << endl;        
    }else{
        int p = 0;
        int i = max(a1, max(a2,a3));
        for(; i >= 1; i--){
            int b1 = a1%i;
            int b2 = a2%i;
            int b3 = a3%i;
            if(isKadomatu(b1,b2,b3))    p++;
        }
        cout << p << endl;
    }

    return 0;
}