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

ll t, n, u, v, p;
vector<ll> adj[1001];
bool visited[1001] = {0};

ll BFS(ll u, ll v)
{
    memset(visited, 0, sizeof(visited));

    ll res = 0;

    queue<ll> q;
    q.push(u);
    visited[u] = 1;

    while(!q.empty())
    {
        vector<ll> vc;
        while(!q.empty()) 
        {
            if(q.front() == v) return res;

            vc.pb(q.front());
            q.pop();
        }

        for(auto it : vc) 
        {
            for(ll x : adj[it])
            {
                if(!visited[x]) 
                {
                    q.push(x);
                    visited[x] = 1;
                }
            }
        } 

        res ++;     
    }

    return -1;
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
            adj[v].pb(u);
        }

        cin >> p;
        while(p--) 
        {
            cin >> u >> v;
            cout << BFS(u,v) << '\n';
        }


        FOR(i,1,n,1) adj[i].clear();
    }
    
    return 0;
}