#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int three = 0;
    int five = 0;

    for(int i = 0; i < s.size(); i++){
        int x = s[i] - '0';
        three = (three*4 + x)%3;
        five = (five*4 + x)%5;
    }

    if(three==0)    cout << "Fizz";
    if(five==0)     cout << "Buzz";
    if(three!=0 && five!=0) cout << s;

    cout << endl;

    return 0;
}