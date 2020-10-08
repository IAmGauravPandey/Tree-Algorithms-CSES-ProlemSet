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
    Euler[x] = val[u];
    in[u] = x;
    for (int v : G[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
    x = ++timer;
    Euler[x] = val[u];
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    // compress the values of color
    map<int, int> compress;
    for (int i = 1; i <= n; i++)
        compress[val[i]] = 1;
    int col = 1;
    for (auto it : compress)
    {
        compress[it.first] = col++;
    }
    for (int i = 1; i <= n; i++)
        val[i] = compress[val[i]];
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        //v = i;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1, 0);
    // now the question is finding distict elements in Euler array
    // between out[i] and in[i] for each node i.
    vector<vector<int>> Query;
    for (int i = 1; i <= n; i++)
    {
        Query.pb({in[i], out[i], i});
    }
    sort(all(Query), [&](vi a, vi b) {
        return a[1] < b[1];
    });
    int vis[n + 1];
    memset(vis, -1, sizeof(vis));
    int ans[n + 1];
    int q = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (vis[Euler[i]] != -1)
            add(vis[Euler[i]], -1);
        vis[Euler[i]] = i;
        add(i, 1);
        while (q < Query.size() and Query[q][1] == i)
        {
            ans[Query[q][2]] = get(Query[q][1]) - get(Query[q][0] - 1);
            q++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
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
