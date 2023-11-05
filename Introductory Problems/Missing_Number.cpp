#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define ll long long
#define ld long double
#define fi(a, n) for (int i = a; i < n; i++)
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define prv(i) cout << "i" << i << endl
#define scv(i) cin >> i
#define YY cout << "YES" << endl
#define NN cout << "NO" << endl
#define vi(i) vector<int> i
#define vov(i) vector<vector<int>> i
void _print(int x)
{
    cerr << x << " ";
}
void _print(float x) { cerr << x << " "; }
void _print(double x) { cerr << x << " "; }
void _print(ll x) { cerr << x << " "; }
void _print(ld x) { cerr << x << " "; }
void _print(string x) { cerr << x << " "; }
template <class T, class V>
void _print(pair<T, V> x)
{
    cerr << "{";
    _print(x.first);
    cerr << ", ";
    _print(x.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> x)
{
    cerr << "[ ";
    for (T i : x)
        _print(i);
    cerr << "]";
}
template <class T>
void _print(vector<vector<T>> x)
{
    cerr << "[ ";
    for (vector<T> i : x)
        _print(i);
    cerr << "]";
}
template <class T>
void _print(set<T> x)
{
    cerr << "[ ";
    for (T i : x)
        _print(i);
    cerr << "]";
}
template <class T>
void _print(multiset<T> x)
{
    cerr << "[ ";
    for (T i : x)
        _print(i);
    cerr << "]";
}
template <class T>
void _print(unordered_set<T> x)
{
    cerr << "[ ";
    for (T i : x)
        _print(i);
    cerr << "]";
}
template <class T>
void _print(unordered_multiset<T> x)
{
    cerr << "[ ";
    for (T i : x)
        _print(i);
    cerr << "]";
}
template <class T>
void _print(stack<T> x)
{
    cerr << "[ ";
    while (!x.empty())
    {
        _print(x.top());
        x.pop();
    }
    cerr << "]";
}
template <class T>
void _print(queue<T> x)
{
    cerr << "[ ";
    while (!x.empty())
    {
        _print(x.front());
        x.pop();
    }
    cerr << "]";
}
template <class T>
void _print(deque<T> x)
{
    cerr << "[ ";
    while (!x.empty())
    {
        _print(x.front());
        x.pop_front();
    }
    cerr << "]";
}
template <class T>
void _print(priority_queue<T> x)
{
    cerr << "[ ";
    while (!x.empty())
    {
        _print(x.top());
        x.pop();
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);
#else
#define debug(x)
#endif
const int m = 1e9 + 7;
int bin_mul(long long a, long long b)
{
    int ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % m;
        }
        b = b >> 1;
        a = (a + a) % m;
    }
    return ans;
}
int bin_expo(long long a, long long b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1 == 1)
        {
            ans = bin_mul(ans, a);
        }
        a = bin_mul(a, a);
        b = b >> 1;
    }
    return ans;
}
void inpv(vector<int> &v, int &n)
{
    fi(0, n)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
}
int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("debug.txt", "w", stderr);
    auto start = high_resolution_clock::now();
#endif

    // write your code here
    int n;
    cin >> n;
    int XOR = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        XOR ^= x;
    }
    for (int i = 1; i <= n; i++)
    {
        XOR ^= i;
    }
    cout << XOR << endl;

#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cerr << "Time:" << duration.count() << " microseconds" << endl;
#endif
    return 0;
}
