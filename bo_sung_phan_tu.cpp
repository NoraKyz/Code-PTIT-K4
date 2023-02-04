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

ll t, n, x;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll l = 1e9, r = -1e9;
        ll a[1000001] = {0};

        cin >> n;
        FOR(i,1,n,1) 
        {
            cin >> x;
            a[x] = 1;
            l = min(l,x);
            r = max(r,x);
        }
        ll res = 0;
        FOR(i,l,r,1) if(a[i] == 0) res++;
        cout << res << '\n';
    }
    
    return 0;
}