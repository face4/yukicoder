#include<iostream>
using namespace std;

int main(){
    int g, c, p, fg = 0, fc = 0, fp = 0;
    cin >> g >> c >> p;
    string s;
    cin >> s;

    for(char c : s){
        if(c == 'G')        fg++;
        else if(c == 'C')   fc++;
        else if(c == 'P')   fp++;
    }

    int score = 0;
    int gwin = min(g, fc);  g -= gwin; fc -= gwin;
    int cwin = min(c, fp);  c -= cwin; fp -= cwin;
    int pwin = min(p, fg);  p -= pwin; fg -= pwin;
    int gtie = min(g, fg);
    int ctie = min(c, fc);
    int ptie = min(p, fp);

    cout << 3*(gwin+cwin+pwin)+(gtie+ctie+ptie) << endl;

    return 0;
}