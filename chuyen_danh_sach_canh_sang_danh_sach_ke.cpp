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

ll t, n, m, a, b;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        vector<ll> adj[1001];
        cin >> n >> m;
        FOR(i,1,m,1) 
        {
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        FOR(i,1,n,1) 
        {
            cout << i << ": ";
            for(auto it : adj[i]) cout << it << " ";
            cout << '\n';
        }  
    }

    
    return 0;
}