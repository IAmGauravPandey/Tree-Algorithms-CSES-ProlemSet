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
int up[2 * N][20];
int depth[2 * N];
int ans[2 * N];
void dfs(int u, int p)
{
    up[u][0] = p;
    if (p)
        depth[u] = depth[p] + 1;
    for (int v : G[u])
    {
        if (v != p)
            dfs(v, u);
    }
}
int lca(int u, int v)
{
    if (depth[v] > depth[u])
        swap(u, v);
    for (int i = 19; ~i; i--)
    {
        if (depth[u] - (1LL << i) >= depth[v])
        {
            u = up[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = 19; ~i; i--)
    {
        if (up[v][i] != -1 and up[v][i] != up[u][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
void solve(int u, int p)
{
    for (int v : G[u])
    {
        if (v != p)
        {
            solve(v, u);
            ans[u] += ans[v];
        }
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        //v = i;
        G[u].pb(v);
        G[v].pb(u);
    }
    memset(up, -1, sizeof(up));
    dfs(1, -1);
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= n; i++)
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int l = lca(u, v);
        ans[u]++;
        ans[v]++;
        ans[l]--;
        int p_l = up[l][0];
        if (p_l != -1)
            ans[p_l]--;
    }
    solve(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
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
