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
unordered_map<ll,string> m;
vector<ll> adj[100001];

void Solve(ll x, string currentLine) 
{
    if(adj[x].empty()) m[x] = currentLine;

    for(auto it : adj[x]) 
    {
        Solve(it, currentLine + to_string(it) + " ");
    }
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

        Solve(1, "1 ");

        vector<pair<ll,string>> v(all(m));
        sort(all(v));

        for(auto it : v) cout << it.second << '\n';

        m.clear();
        FOR(i,1,n,1) adj[i].clear();
    }
    
    return 0;
}