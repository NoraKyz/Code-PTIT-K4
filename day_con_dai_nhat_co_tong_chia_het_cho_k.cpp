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

ll t, n, k;
ll a[1005], dp[1005][55] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--) 
    {
        /*
            dp[i][j] la day con dai nhat ket thuc tai i thoa man tong chia k du j
        */
       memset(dp,0,sizeof(dp));

        cin >> n >> k;
        FOR(i,1,n,1) 
        {
            cin >> a[i];
            a[i]%=k;
        }

        FOR(i,1,k-1,1) dp[1][i] = -1e9;

        dp[1][a[1]] = 1;

        FOR(i,2,n,1) 
        {
            FOR(j,0,k-1,1)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][(j-a[i]+k)%k] + 1);
            }           
        }

        cout << dp[n][0] << '\n';
    }
    
    return 0;
}