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
ll a[100001];
    
int main()
{   
    fast_cin
    cin >> n;
    FOR(i,1,n,1) cin >> a[i];

    vector<ll> c, l;

    FOR(i,1,n,1) if(i%2) l.pb(a[i]); else c.pb(a[i]);

    sort(all(l));
    sort(all(c),greater<ll>());

    ll id = 1;
    for(auto it : l) 
    {
        a[id] = it;
        id += 2;
    }

    id = 2;
    for(auto it : c) 
    {
        a[id] = it;
        id += 2;
    }

    FOR(i,1,n,1) cout << a[i] << " ";
    
    return 0;
}