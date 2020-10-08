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
int in[2 * N], out[2 * N];
void dfs1(int u, int p)
{
    for (int v : G[u])
    {
        if (v != p)
        {
            dfs1(v, u);
            in[u] = max(in[u], 1 + in[v]);
        }
    }
}
void dfs2(int u, int p)
{
    int mx1 = -1, mx2 = -1;
    for (int v : G[u])
    {
        if (v != p)
        {
            if (in[v] >= mx1)
                mx2 = mx1, mx1 = in[v];
            else if (in[v] > mx2)
                mx2 = in[v];
        }
    }
    for (int v : G[u])
    {
        if (v != p)
        {
            int maxi = mx1;
            if (mx1 == in[v])
                maxi = mx2;
            out[v] = max(out[u], 1 + maxi) + 1;
            dfs2(v, u);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << max(in[i], out[i]) << " ";
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
