#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n, A[4], B[4];
    cin >> n;
    for(int i = 0; i < n; i++)  cin >> A[i];
    for(int i = 0; i < n; i++)  cin >> B[i];
    sort(A, A+n);
    sort(B, B+n);
    
    int m = 0;
    int c = 0;
    do{
        do{
            m++;
            int wins = 0;
            for(int i = 0; i < n; i++){
                if(A[i] > B[i]) wins++;
            }
            if(wins > n-wins)   c++;
        }while(next_permutation(B, B+n));
    }while(next_permutation(A, A+n));

    cout << (double)c / m << endl;
    return 0;
}
/*
vector<string> va;
vector<string> vb;

bool check(string s , string t){
    int awin = 0, bwin = 0;
    for(int i = 0; i < s.length(); i++){
        int a = s[i]-'0';
        int b = t[i]-'0';
        if(a > b)   awin++;
        else if(a < b)  bwin++;
    }

    return awin>bwin;
}

void makePermA(string s, string t){
    if(s == "")     va.push_back(t);
    else{
        for(int i = 0; i < s.size(); i++){
            string tmps = s;
            string tmpt = t+tmps[i];
            tmps.erase(tmps.begin()+i);
            makePermA(tmps , tmpt);
        }
    }
}

void makePermB(string s, string t){
    if(s == "")     vb.push_back(t);
    else{
        for(int i = 0; i < s.size(); i++){
            string tmps = s;
            string tmpt = t+tmps[i];   
            tmps.erase(tmps.begin()+i);
            makePermB(tmps , tmpt);
        }
    }
}

int main(){
    int n;
    string a, b, c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c;
        a += c;
    }

    for(int i = 0; i < n; i++){
        cin >> c;
        b += c;
    }

    makePermA(a, "");
    makePermB(b, "");

    int sum = 0;
    int win = 0;
    for(vector<string>::iterator ita = va.begin(); ita != va.end(); ita++){
        string first = *ita;
        for(vector<string>::iterator itb = vb.begin(); itb != vb.end(); itb++){
            string second = *itb;
            if(check(first, second)) win++;
            sum++;
        }
    }

    cout << (double)win / sum << endl;
    return 0;
}
*/