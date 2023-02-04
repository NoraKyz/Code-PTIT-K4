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

ll t, n, v;
ll a[1005], b[1005], dp[1001][1001] = {0};
    
int main()
{   
    fast_cin

    cin >> t;
    while(t--)
    {
        cin >> n >> v;
        FOR(i,1,n,1) cin >> a[i];
        FOR(i,1,n,1) cin >> b[i];   

        FOR(i,1,n,1) 
        {
            FOR(j,1,v,1) 
            {
                dp[i][j] = 0;
                if(j >= a[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + b[i]);
                else dp[i][j] = dp[i-1][j];
            } 
        }

        cout << dp[n][v] << '\n';
    }
    

    return 0;
}