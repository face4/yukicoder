#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    int n;
    cin >> n;
    int A[n+1] = {};
    
    string s;
    cin >> s;

    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(i+1);
        }else if(s[i] == ')'){
            int firstPos = st.top(); st.pop();
            A[i+1] = firstPos;
            A[firstPos] = i+1;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << A[i] << endl;
    }

    return 0;
}