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
ll dpdown[1001] = {0}, dpup[1001] = {0}, a[1001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll res = -1;
        cin >> n;
        FOR(i,1,n,1) cin >> a[i];

        FOR(i,1,n,1) 
        {
            dpup[i] = a[i];
            FORD(j,i-1,1,1) 
            {
                if(a[i] > a[j]) dpup[i] = max(dpup[i], dpup[j] + a[i]);
            }
        }

        FORD(i,n,1,1) 
        {
            dpdown[i] = a[i];
            FOR(j,i+1,n,1) 
            {
                if(a[i] > a[j]) dpdown[i] = max(dpdown[i], dpdown[j] + a[i]);
            }
        }

        FOR(i,1,n,1) res = max(res,dpup[i]+dpdown[i]-a[i]);

        cout << res << '\n';
    }
    
    return 0;
}