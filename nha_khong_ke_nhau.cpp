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

ll t, n;
ll a[1000001], dp[1000001] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) cin >> a[i];

        dp[1] = a[1];
        if(n >= 2) dp[2] = max(a[1],a[2]);

        FOR(i,3,n,1) 
        {
            dp[i] = max(dp[i-2] + a[i], dp[i-1]);
        }

        cout << dp[n] << '\n';

        /*
            dp[i] = max(dp[i-2] + a[i], dp[i-1]);
        */
    }
    
    return 0;
}