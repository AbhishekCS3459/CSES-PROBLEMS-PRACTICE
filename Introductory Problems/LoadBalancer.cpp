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
class node
{
public:
    int A_T;
    int C_T;
    int serv_idx;
    node(int A_T, int C_T, int serv_idx)
    {
        this->A_T = A_T;
        this->C_T = C_T;
        this->serv_idx = serv_idx;
    }
};
struct compare
{
    bool operator()(node *a, node *b)
    {
        return a->C_T > b->C_T;
    }
};

vector<int> getServerIndex(int NO_OF_REQUESTS, vector<int> A_T, vector<int> C_T, int NO_of_Servers)
{

    map<int, int> A_T_to_C_T;
    for (int i = 0; i < A_T.size(); i++)
    {
        A_T_to_C_T[A_T[i]] = C_T[i];
    }
    sort(A_T.begin(), A_T.end());

    priority_queue<node *, vector<node *>, compare> pq;

    vector<int> server_assignments(A_T.size(), -1);

    int server_idx = 1;
    server_assignments[0] = server_idx;

    pq.push(new node(A_T[0], A_T_to_C_T[A_T[0]], 1));

    for (int i = 1; i < A_T.size(); i++)
    {
        int Curr_AT = A_T[i];
        int Least_CT = pq.top()->C_T;
        int Least_ass_Serv = pq.top()->serv_idx;
        if (Least_ass_Serv > NO_of_Servers)
            continue;

        if (Curr_AT >= Least_CT)
        {
            pq.pop();
            pq.push(new node(Curr_AT, A_T_to_C_T[Curr_AT], Least_ass_Serv));
            server_assignments[i] = Least_ass_Serv;
        }
        else
        {
            server_idx++;
            pq.push(new node(Curr_AT, A_T_to_C_T[Curr_AT], server_idx));
            server_assignments[i] = server_idx;
        }
    }

    return server_assignments;
}

int main()
{
    fastio;
#ifndef ONLINE_JUDGE
    freopen("debug.txt", "w", stderr);
    auto start = high_resolution_clock::now();
#endif
    int NO_OF_REQUESTS=5;
    int NO_OF_SERVERS=3;
    vector<int> A_T = {2, 4, 1, 8, 9};
    
    vector<int> C_T = {9, 13, 3, 12, 14};
    vector<int> server_assignments = getServerIndex(NO_OF_SERVERS, A_T, C_T, NO_OF_REQUESTS);

    for (int i = 0; i < server_assignments.size(); i++)
    {
        cout << server_assignments[i] << " ";
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cerr << "Time:" << duration.count() << " microseconds" << endl;
#endif
    return 0;
}
