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

ll t, n, c;
ll a[105], dp[101][25001];
    
int main()
{   
    fast_cin

    cin >> c >> n;
    FOR(i,1,n,1) cin >> a[i];

    dp[0][c] = 0;

    FOR(i,1,n,1) 
    {
        FOR(j,1,c,1) 
        {
            dp[i][j] = 0;
            if(j >= a[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + a[i]);
            else dp[i][j] = dp[i-1][j];
        } 
    }

    cout << dp[n][c];

    return 0;
}