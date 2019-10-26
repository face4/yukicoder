#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)
typedef pair<int,int> pii;
const int INF = 1e9+1;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, b;
    cin >> n >> b;
    vector<pair<pii,int>> vp;
    vector<int> ax, ay;
    for(int i = 0; i < n; i++){
        int x, y, p;
        cin >> x >> y >> p;
        vp.push_back({{x,y},p});
        ax.push_back(x);
        ay.push_back(y);
    }
    ax.push_back(INF); ax.push_back(-INF);
    ay.push_back(INF); ay.push_back(-INF);

    sort(ax.begin(),ax.end());
    ax.erase(unique(ax.begin(),ax.end()),ax.end());
    auto fx = [&](int val)->int{
        return lower_bound(ax.begin(),ax.end(),val)-ax.begin();
    };

    sort(ay.begin(),ay.end());
    ay.erase(unique(ay.begin(),ay.end()),ay.end());
    auto fy = [&](int val)->int{
        return lower_bound(ay.begin(),ay.end(),val)-ay.begin();
    };
    int nx = ax.size(), ny = ay.size();

    vector<vector<int>> cnt(nx, vector<int>(ny, 0)), sum(nx, vector<int>(ny, 0));
    for(int i = 0; i < n; i++){
        int ix = fx(vp[i].first.first), iy = fy(vp[i].first.second);
        cnt[ix][iy]++;
        sum[ix][iy] += vp[i].second;
    }
    for(int i = 0; i < nx; i++){
        for(int j = 1; j < ny; j++){
            cnt[i][j] += cnt[i][j-1];
            sum[i][j] += sum[i][j-1];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int low = fy(vp[i].first.second), high = fy(vp[j].first.second);
            if(low > high)  swap(low, high);
            int l = 0, r = 0, tmpsum = 0, tmpcnt = 0;
            while(l < nx){
                while(r < nx && sum[r][high]-sum[r][low-1]+tmpsum <= b){
                    tmpsum += sum[r][high]-sum[r][low-1];
                    tmpcnt += cnt[r][high]-cnt[r][low-1];
                    r++;
                }
                ans = max(ans, tmpcnt);
                if(l == r){
                    l = ++r;
                    tmpsum = 0, tmpcnt = 0;
                }else{
                    tmpsum -= sum[l][high]-sum[l][low-1];
                    tmpcnt -= cnt[l][high]-cnt[l][low-1];
                    l++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}