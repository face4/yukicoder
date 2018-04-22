#include<iostream>
using namespace std;

int main(){
    int h, n, grade = 1, x;
    cin >> h >> n;
    n--;
    while(n-- > 0){
        cin >> x;
        if(x > h)   grade++;
    }

    cout << grade;
    switch(grade%10){
        case 1:
        cout << "st" << endl;   break;
        case 2:
        cout << "nd" << endl;   break;
        case 3:
        cout << "rd" << endl;   break;
        default:
        cout << "th" << endl;   break;
    }
    return 0;
}