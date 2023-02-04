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

ll t, n, m, x;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        vector<ll> v;
        cin >> n >> m;

        FOR(i,1,n,1)
        {
            cin >> x;
            v.pb(x);
        }
        FOR(i,1,m,1) 
        {
            cin >> x;
            v.pb(x);
        }

        sort(all(v));

        for(auto it : v) cout << it << " ";
        cout << '\n';
    }
    
    return 0;
}