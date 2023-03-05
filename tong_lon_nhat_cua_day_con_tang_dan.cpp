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
ll a[10001], dp[10001] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) cin >> a[i];

        FOR(i,1,n,1) 
        {
            dp[i] = a[i];
            FORD(j,i-1,1,1) 
            {
                if(a[i] > a[j]) 
                {
                    dp[i] = max(dp[i], dp[j] + a[i]);
                }
            }
        }

        ll d = max_element(dp+1,dp+1+n)-dp;
        cout << dp[d] << '\n';
    }
    
    return 0;
}