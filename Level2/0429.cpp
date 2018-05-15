//スマホコーディング
#include <iostream>
#include <stack>
using namespace std;

int before[100005];
int after[100005];
int n, k, x;

int main()
{
    cin >> n >> k >> x;
    stack<pair<int, int>> shuf;
    for (int i = 1; i <= n; i++)
    {
        before[i] = i;
    }

    int l, r;
    for (int i = 1; i < x; i++)
    {
        cin >> l >> r;
        swap(before[l], before[r]);
    }

    char tmpa, tmpb;
    cin >> tmpa >> tmpb;

    for (int i = x + 1; i <= k; i++)
    {
        cin >> l >> r;
        shuf.push(make_pair(l, r));
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> after[i];
    }

    pair<int, int> box;
    while (!shuf.empty())
    {
        box = shuf.top();
        shuf.pop();
        swap(after[box.first], after[box.second]);
    }

    int A[2];
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        if (after[i] != before[i])
            A[pos++] = i;
    }

    cout << A[0] << " " << A[1] << endl;
    return 0;
}