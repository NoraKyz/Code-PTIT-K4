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
ll a[1001][1001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(i,1,n,1) 
        {
            FOR(j,1,m,1) cin >> a[i][j];
        }

        ll dp[n+1][m+1] = {0};

        FOR(i,1,n,1) 
        {
            FOR(j,1,m,1) 
            {
                dp[i][j] = a[i][j];
                if(i != 1 || j != 1)
                {   
                    ll tmp = 1e9;
                    if(i-1 > 0 && j-1 > 0) tmp = min(tmp, dp[i-1][j-1]);
                    if(i-1 > 0 && j > 0) tmp = min(tmp, dp[i-1][j]);
                    if(i > 0 && j-1 > 0) tmp = min(tmp, dp[i][j-1]);

                    dp[i][j] += tmp;

                }
            }
        }

        cout << dp[n][m] << '\n';
    }
    
    return 0;
}