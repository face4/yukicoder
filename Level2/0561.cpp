//スマホコーディング
#include <iostream>
using namespace std;

int tokyo[101] = {};
int kyoto[101] = {};

int main()
{
    int n, d, t, k;
    cin >> n >> d >> t >> k;
    tokyo[1] = t;
    kyoto[1] = k - d;
    for (int i = 2; i <= n; i++)
    {
        cin >> t >> k;
        tokyo[i] = max(tokyo[i - 1] + t, kyoto[i - 1] + t - d);
        kyoto[i] = max(tokyo[i - 1] + k - d, kyoto[i - 1] + k);
    }

    cout << max(tokyo[n], kyoto[n]) << endl;
    return 0;
}