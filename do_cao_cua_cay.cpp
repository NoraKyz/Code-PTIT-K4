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

ll t, n, u, v;
vector<ll> adj[100001];

ll maxDepth(ll x) 
{
    ll res = 0;

    for(auto it : adj[x]) res = max(res, maxDepth(it) + 1);

    return res;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n-1,1) 
        {
            cin >> u >> v;
            adj[u].pb(v);
        }

        cout << maxDepth(1) << '\n';

        FOR(i,1,n,1) adj[i].clear();
    }
    
    return 0;
}