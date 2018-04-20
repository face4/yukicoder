#include<iostream>
using namespace std;

int main(){
    int a1,b1,c1,a2,b2,c2;
    scanf("%d.%d.%d" , &a1, &b1, &c1);
    scanf("%d.%d.%d" , &a2, &b2, &c2);

    if(a1 == a2){
        if(b1 == b2){
            if(c1 >= c2) cout << "YES";
            else         cout << "NO";
        }else if(b1 > b2){
            cout << "YES";
        }else if(b1 < b2){
            cout << "NO";
        }
    }else if(a1 > a2){
        cout << "YES";
    }else if(a1 < a2){
        cout << "NO";
    }
    cout << endl;
    return 0;
}