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
ll f[1000001] = {0,1};
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> k;

        FOR(i,1,k,1) f[i] = 1;

        FOR(i,2,n,1) 
        {
            if(i > k) f[i] = 0;

            FOR(j,1,k,1) 
            {
                if(i-j <= 0) break;
                f[i] += f[i-j]%MOD;
            }

            f[i]%=MOD;
        }

        cout << f[n] << '\n';
    }
    
    return 0;
}