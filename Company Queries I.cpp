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
void dfs(int u, int p)
{
    up[u][0] = p;
    for (int v : G[u])
    {
        if (v != p)
            dfs(v, u);
    }
}
int query(int u, int k)
{
    for (int i = 19; ~i; i--)
    {
        if (k >= (1LL << i))
        {
            k -= (1LL << i);
            u = up[u][i];
            if (u == -1)
                return -1;
        }
    }
    return u;
}
void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u;
        v = i;
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
        int u, k;
        cin >> u >> k;
        cout << query(u, k) << "\n";
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
