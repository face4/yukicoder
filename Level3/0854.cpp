#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    bool nonp[2000] = {};
    vector<int> p;
    for(int i = 2; i < 2000; i++){
        if(nonp[i]) continue;
        p.push_back(i);
        for(int j = i+i; j < 2000; j += i)  nonp[j] = true;
    }
    int pnum = p.size();

    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for(int i = 0; i < n; i++)  scanf("%d", a.begin()+i);

    vector<vector<int>> sum(pnum, vector<int>(n, 0));
    for(int i = 0; i < pnum; i++){
        for(int j = 0; j < n; j++){
            if(a[j]){
                int tmp = a[j];
                while(tmp%p[i] == 0)    tmp /= p[i], sum[i][j]++;
            }
            if(j)   sum[i][j] += sum[i][j-1];
        }
    }

    vector<int> fuck(n, 0); fuck[0] = (a[0] == 0);
    for(int i = 1; i < n; i++)  fuck[i] = (fuck[i-1] + (a[i]==0));

    int q;
    scanf("%d", &q);

    while(q-- > 0){
        int x, l, r;
        scanf("%d %d %d", &x, &l, &r);
        l--, r--;
        
        if(fuck[r]-(l==0 ? 0 : fuck[l-1])){
            printf("Yes\n");
            continue;
        }

        bool ok = true;
        int tmp = x;
        for(int i = 0; i < pnum; i++){
            int need = 0;
            while(tmp%p[i]==0)  tmp /= p[i], need++;
            int exist = sum[i][r] - (l==0 ? 0 : sum[i][l-1]);
            if(need > exist)    ok = false;
        }
        ok &= (tmp == 1);

        if(ok)  printf("Yes\n");
        else    printf("NO\n");
    }

    return 0;
}