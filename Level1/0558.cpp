#include<iostream>
#include<string>
using namespace std;

int main(){
    char A[101];
    scanf("%s" , A);
    string str(A);
    if(str.find("575") != string::npos){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}