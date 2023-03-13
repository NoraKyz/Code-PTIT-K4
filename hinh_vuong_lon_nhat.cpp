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
ll a[505][505], dp[505][505] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll res = 0;
        cin >> n >> m;
        FOR(i,1,n,1) FOR(j,1,m,1) cin >> a[i][j];

        FOR(i,1,n,1) 
        {
            FOR(j,1,m,1) 
            {
                if(a[i][j])
                {
                    dp[i][j] = a[i][j];
                    
                    if(a[i-1][j-1] && a[i-1][j] && a[i][j-1]) 
                    {
                        dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
                    }

                    res = max(res, dp[i][j]);
                }
            }
        }

        cout << res << '\n';
    }
    
    return 0;
}