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

ll t, n, m;
ll d[1005][1005];
vector<ll> adj[1005];
bitset<10005> visited;
// Tính trọng số đường đi từ đỉnh u tới các đỉnh còn lại. Nếu tồn tại chu trình về u và trọng số đường đi đó < 0 => chu trình âm
bool BFS(ll u)
{
    queue<pair<ll, ll>> q;
    q.push({u, 0});
    visited[u] = 1;
    pair<ll, ll> top;
    while(!q.empty())
    {
        top = q.front();
        q.pop();
        for(ll &i : adj[top.fi])
        {
            if(!visited[i])
            {
                q.push({i, top.se + d[top.fi][i]}); // w đường đi từ u tới các đỉnh kia. Nếu nó tới nó mà < 0 => tồn tại chu trình âm
                visited[i] = 1;
            }
            else if(i == u and top.se + d[top.fi][i] < 0)
                return 1;
        }
    }

    return 0;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m;

        FOR(i,1,m,1)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            d[u][v] = w;
            adj[u].pb(v);
        }

        bool check = 0;
        for(int i = 1; i <= n; ++i)
        {
            check = BFS(i);
            if(check)
                goto End;
            visited.reset();
        }

        End:
        cout << check << endl;
        for(int i = 1; i <= n; ++i)
            adj[i].clear();
        visited.reset();
    }
    
    return 0;
}