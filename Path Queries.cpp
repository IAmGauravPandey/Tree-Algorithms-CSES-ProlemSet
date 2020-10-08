#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define AB_BHI_NI_DEGI                \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define pb push_back
#define N 100009
#define inf 1e18
const double PI = 3.141592653589793238462643383279;
int mod = 1e9 + 7;
//int mod = 998244353;
#define P pair<int, int>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define ld long double
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
 
vector<int> G[2 * N];
int val[2 * N];
int Euler[4 * N];
int BIT[4 * N];
int in[2 * N], out[2 * N];
int timer;
void dfs(int u, int p)
{
    int x = ++timer;
    Euler[x] = u;
    in[u] = x;
    for (int v : G[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
    x = ++timer;
    Euler[x] = u;
    out[u] = x;
}
void add(int i, int val)
{
    while (i < 4 * N)
    {
        BIT[i] += val;
        i += i & (-i);
    }
}
int get(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += BIT[i];
        i -= i & (-i);
    }
    return res;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        //v = i;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        add(in[i], val[i]);
        add(out[i], -val[i]);
    }
    while (q--)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            int s, x;
            cin >> s >> x;
            add(in[s], -val[s]);
            add(out[s], val[s]);
            val[s] = x;
            add(in[s], val[s]);
            add(out[s], -val[s]);
        }
        else
        {
            int s;
            cin >> s;
            int ans = get(in[s]);
            cout << ans << "\n";
        }
    }
}
int32_t main()
{
    AB_BHI_NI_DEGI
    int Test = 1;
    //cin >> Test;
    //init();
    int itr = 1;
    while (Test--)
    {
        //cout << "Case #" << itr++ << ": ";
        solve();
    }
    return 0;
}
