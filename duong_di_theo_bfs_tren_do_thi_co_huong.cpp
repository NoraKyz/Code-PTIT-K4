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
vector<ll> adj[10001];
bool visited[10001] = {0};
ll parent[10001] = {0};

void BFS(ll u)
{
    queue<ll> q;
    q.push(u);
    visited[u] = 1;

    while(!q.empty())
    {       
        ll v = q.front();
        q.pop();
        for(ll x : adj[v])
        {
            if(!visited[x]) 
            {
                q.push(x);
                visited[x] = 1;
                parent[x] = v;
            }
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll v, e, start, end;
        cin >> v >> e >> start >> end;
        FOR(i,1,e,1) 
        {
            ll a, b;
            cin >> a >> b;
            adj[a].pb(b);
        }

        BFS(start);
        if(!visited[end]) cout << -1;
        else 
        {
            vector<ll> path;
            while(end != start) 
            {
                path.pb(end);
                end = parent[end];
            }

            path.pb(start);
            reverse(all(path));

            for(auto it : path) cout << it << " ";
        }
        cout << '\n';

        FOR(i,1,v,1) adj[i].clear();
        memset(visited,0,sizeof(visited));
    }
    
    return 0;
}