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

struct Node
{
    ll u, v, w;
};

struct cmp{
    bool operator() (Node a, Node b) {
        return a.w > b.w;
    }
};

ll d[505][505], a[505][505];

void dijkstra(int s, int t) 
{
    FOR(i,1,n,1) FOR(j,1,m,1) d[i][j] = 300000;

    bool vs[505][505] = {0};

    d[s][t] = a[s][t];

    priority_queue<Node, vector<Node>, cmp> pq;

    pq.push({s,t,d[s][t]});
    
    while(!pq.empty()) 
    {
        Node x = pq.top();
        pq.pop();

        int u = x.u;
        int v = x.v; // tìm đỉnh u,v chưa dùng, có khoảng cách nhỏ nhất

        if(vs[u][v]) continue; // đã xét rồi thì bỏ qua (không cần thiết
        
        // cải tiến các đường đi qua u
        vs[u][v] = 1;

        if(u-1 >= 1) 
        {
            d[u-1][v] = min(d[u-1][v], d[u][v] + a[u-1][v]);
            pq.push({u-1,v,d[u-1][v]});
        }
        if(u+1 <= n) 
        {
            d[u+1][v] = min(d[u+1][v], d[u][v] + a[u+1][v]);
            pq.push({u+1,v,d[u+1][v]});
        }
        if(v-1 >= 1) 
        {
            d[u][v-1] = min(d[u][v-1], d[u][v] + a[u][v-1]);
            pq.push({u,v-1,d[u][v-1]});
        }
        if(v+1 <= m) 
        {
            d[u][v+1] = min(d[u][v+1], d[u][v] + a[u][v+1]);
            pq.push({u,v+1,d[u][v+1]});
        }
    }

    cout << d[n][m] << '\n';
}
   
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(i,1,n,1)
        {
            FOR(j,1,m,1)
            {
                cin >> a[i][j];
            }
        }

        dijkstra(1,1);
    }
    return 0;
}