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
int dp[2 * N][5];
int dfs(int u, int p, int p_c)
{
    if (dp[u][p_c] != -1)
        return dp[u][p_c];
    int ans = 0;
    if (p_c != 1)
    {
        for (int v : G[u])
        {
            if (v != p)
            {
                ans += max({dfs(v, u, 0), dfs(v, u, 1)});
            }
        }
    }
    if (p_c == 1)
    {
        int m = G[u].size();
        int pre[m] = {0};
        int suff[m + 1] = {0};
        for (int i = 0; i < m; i++)
        {
            if (i)
                pre[i] = pre[i - 1];
            int v = G[u][i];
            if (v != p)
            {
                pre[i] += max(dfs(v, u, 0), dfs(v, u, 1));
            }
        }
        for (int i = m - 1; ~i; i--)
        {
            suff[i] = suff[i + 1];
            int v = G[u][i];
            if (v != p)
            {
                suff[i] += max(dfs(v, u, 0), dfs(v, u, 1));
            }
        }
        for (int i = 0; i < m; i++)
        {
            int v = G[u][i];
            if (v != p)
            {
                int l = 0;
                if (i)
                    l = pre[i - 1];
                int r = suff[i + 1];
                ans = max(ans, l + r + 1 + dfs(v, u, 2));
            }
        }
    }
    return dp[u][p_c] = ans;
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
    memset(dp, -1, sizeof(dp));
    cout << max(dfs(1, 0, 0), dfs(1, 0, 1)) << "\n";
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
