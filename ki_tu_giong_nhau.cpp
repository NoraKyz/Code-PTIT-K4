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

ll t, n, x, y, z;
ll dp[105] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y >> z;

        dp[1] = x;
        dp[2] = min(x,z) + x;

        FOR(i,3,n,1) 
        {
            if(i%2 == 0) 
            {
                dp[i] = min(dp[i/2] + i/2 * x, dp[i/2] + z);
            }
            else 
            {
                dp[i] = min(dp[i-1] + x, dp[i/2 + 1] + y + z);
            }
        }

        cout << dp[n] << '\n';
    }
    
    return 0;
}