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
ll dp[100001];
pair<ll,ll> a[100001];
    
int main()
{   
    fast_cin

    cin >> n;
    ll res = 0;

    FOR(i,1,n,1) 
    {
        dp[i] = 1;
        cin >> a[i].first >> a[i].second;
    }

    FOR(i,1,n,1) 
    {
        dp[i] = 1;
        FORD(j,i-1,1,1) 
        {
            if(a[i].first > a[j].first && a[i].second > a[j].second) 
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }

        res = max(res, dp[i]);
    }

    cout << res;
    
    return 0;
}