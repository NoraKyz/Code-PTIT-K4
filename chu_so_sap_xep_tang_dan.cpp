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
ll dp[101] = {0}, a[11] = {0};
    
int main()
{   
    fast_cin
    dp[1] = 10;
    FOR(i,1,9,1) a[i] = a[i-1] + 1;

    FOR(i,2,100,1) 
    {
        FOR(j,1,9,1) 
        {
            dp[i] = (dp[i]%MOD + a[j]%MOD)%MOD;
            a[j] = dp[i]%MOD;
        }
        dp[i] = (dp[i]%MOD + dp[i-1]%MOD)%MOD;
    }

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}