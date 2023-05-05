#include<bits/stdc++.h>
#define FOR(i,a,b,k) for (ll i=a;i<=b;i+=k)
#define FORD(i,a,b,k) for (ll i=a;i>=b;i-=k)
#define pb(i) push_back(i)
#define ll long long int
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define me(a,x) memset(a,x,sizeof(a))
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll MOD=1e9+7;

ll t, n, m, st;
vector<ll> d;
vector<pair<int, int>> adj[1005];

void Dijkstra(int s){
    d.assign(n+1, 1e9);// gan tat ca phan tu trong d = 1e9
    d[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({0, s});
    while(!q.empty()){
        // lấy phần tử ở đỉnh hàng đợi
        pair<int, int> top = q.top(); q.pop();
        ll u = top.second; // đỉnh u
        ll len = top.first;//khoảng cách từ đỉnh s đến đỉnh u

        if(len > d[u]) continue;

        for(auto it : adj[u])
        {
            ll v = it.first;
            ll w = it.second;

            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }

    FOR(i,1,n,1) cout << d[i] << " ";

    cout << '\n';
}
   
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> st;

        FOR(i,1,m,1) 
        {
            ll x, y, w;
            cin >> x >> y >> w;

            adj[x].push_back({y,w});
            adj[y].push_back({x,w});      
        }

        Dijkstra(st);

        FOR(i,1,n,1) adj[i].clear();    
    }
    return 0;
}