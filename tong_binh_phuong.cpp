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
ll dp[10001] = {0};
    
int main()
{   
    fast_cin

    /*
        dp[i] 
        so so hang it nhat trong tong binh phuong tao thanh i
    */
    dp[1] = 1;
    FOR(i,1,10000,1) 
    {
        ll tmp = 1e9;
        FOR(j,1,sqrt(i),1) 
        {
            tmp = min(tmp, dp[i-j*j]);
        }

        dp[i] = 1 + tmp;
    }

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[n] << '\n';
    }
    
    return 0;
}