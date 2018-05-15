//スマホコーディング
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, x;
    ll A[101] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        A[x]++;
    }

    long long ans = 0;
    for (int i = 1; i <= 98; i++)
        for (int j = i + 1; j <= 99; j++)
            for (int k = j + 1; k <= 100; k++)
                ans += A[i] * A[j] * A[k];

    ans %= 1000000007;
    cout << ans << endl;
    return 0;
}