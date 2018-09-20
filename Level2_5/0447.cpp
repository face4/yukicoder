#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int n;

struct data{
public:
    string name;
    int lastsub, sum;
    vector<int> score;
    data() {};
    data(string na, int ls, int s){
        name = na;
        lastsub = ls;
        sum = s;
        score.resize(26, 0);
    };

    bool operator<(const data other) const{
        if(sum != other.sum)    return sum > other.sum;
        else                    return lastsub < other.lastsub;
    }

    void print(){
        cout << name;
        for(int i = 0; i < n; i++)  cout << " " << score[i];
        cout << " " << sum << endl;
    }
};

int main(){
    cin >> n;

    int l[n];
    for(int i = 0; i < n; i++)  cin >> l[i];

    int t;
    cin >> t;

    map<string, data> res;
    string name;
    char p;
    int ac[26] = {};

    for(int i = 0; i < t; i++){
        cin >> name >> p;
        int problem = p-'A';
        int getsc = 50*l[problem] + 250*l[problem]/(4 + ac[problem]+1);
        ac[problem]++;
        if(res.count(name)){
            res[name].lastsub = i;
            res[name].score[problem] = getsc;
            res[name].sum += getsc;
        }else{
            res[name] = data(name, i, getsc);
            res[name].score[problem] = getsc;
        }
    }

    vector<data> v;
    for(auto x : res)   v.push_back(x.second);
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << i+1 << " ";
        v[i].print();
    }

    return 0;
}