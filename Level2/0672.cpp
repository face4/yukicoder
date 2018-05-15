#include<iostream>
#include<map>
using namespace std;

int main(){
    string s;
    cin >> s;
    map<int, int> left;
    left[0] = -1; // index0の位置から最長AB列が始まる場合のため
    
    int result = 0;
    int score = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'A')         score++;
        else if(s[i] == 'B')    score--;

        if(left.count(score))   result = max(result, i-left[score]);
        else                    left[score] = i;   
    }

    cout << result << endl;
    return 0;
}
