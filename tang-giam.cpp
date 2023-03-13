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
double a[1001], b[1001];
ll dp[1001] = {0};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll res = -1;
        cin >> n;
        FOR(i,1,n,1) cin >> a[i] >> b[i];

        FOR(i,1,n,1) 
        {
            dp[i] = 1;
            FORD(j,i-1,1,1)
            {
                if(a[j] < a[i] && b[j] > b[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }

        cout << res << '\n';
    }
    
    return 0;
}