#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    char sc, tc;
    ll si, ti;
    cin >> sc >> si >> tc >> ti;
    ll ans = 1ll<<60;
    ll x, y, z, w;
    x = si, z = ti;
    if(sc == 'A')   y = a-si+1;
    if(sc == 'B')   y = b-si+1;
    if(sc == 'C')   y = c-si+1;
    if(tc == 'A')   w = a-ti+1;
    if(tc == 'B')   w = b-ti+1;
    if(tc == 'C')   w = c-ti+1;
    if(sc == tc)    ans = abs(ti-si);
    ans = min(ans, x + z-1);
    ans = min(ans, y + w-1);

    if(sc != 'A' && tc != 'A')  ans = min({ans, x+a+w-1, y+a+z-1});
    if(sc != 'B' && tc != 'B')  ans = min({ans, x+b+w-1, y+b+z-1});
    if(sc != 'C' && tc != 'C')  ans = min({ans, x+c+w-1, y+c+z-1});

    cout << ans << endl;    
    return 0;
}