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
ll dp[1001][1001] = {0};
    
int main()
{   
    fast_cin

    FOR(i,1,1000,1)
    {
        ll res = i;
        dp[i][0] = 1;
        FOR(j,1,i,1) 
        {
            dp[i][j] = res;
            res = (res%MOD * (i-j))%MOD;
        }
    }

    cin >> t;
    while(t--)
    {
       cin >> n >> k;

       if(k > n) cout << 0;
       else cout << dp[n][k];

       cout << '\n';
    }
    
    return 0;
}