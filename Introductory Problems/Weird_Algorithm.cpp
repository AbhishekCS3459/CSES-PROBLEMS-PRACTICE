#include <bits/stdc++.h>
using namespace std;
void solve(long long n)
{
    if (n <= 1)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    if (n % 2 == 0)
    {

        solve(n / 2);
    }
    else
    {
        solve(n * 3 + 1);
    }
}
signed main()
{
    long long n;
    cin >> n;
    solve(n);
}
