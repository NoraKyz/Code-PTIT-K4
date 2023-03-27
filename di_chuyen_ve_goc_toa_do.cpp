#include<bits/stdc++.h>
#define FOR(i,a,b,k) for (ll i=a;i<=b;i+=k)
#define FORD(i,a,b,k) for (ll i=a;i>=b;i-=k)
#define pb(i) push_back(i)
#define ll long long int
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll MOD=1e9+7;

ll t, n, m;
ll dp[50][50] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));

        cin >> n >> m;

        dp[n][m] = 1;

        FORD(i,n,0,1) 
        {
            FORD(j,m,0,1) 
            {
                if(i+1 <= n) dp[i][j] += dp[i+1][j];
                if(j+1 <= m) dp[i][j] += dp[i][j+1];
            }
        }

        // ll res = 0;
        // FOR(i,1,n,1) res += dp[i][0];
        // FOR(i,1,m,1) res += dp[0][i];

        cout << dp[0][0] << '\n';
    }
    
    return 0;
}