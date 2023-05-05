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

ll t, n, m, cntv, cnte;
vector<ll> adj[100001];
bool visited[100001] = {0};

void DFS(ll u)
{
    cntv++;
    cnte += adj[u].size();
    visited[u] = 1;
    for(ll v : adj[u])
    {
        if(!visited[v]) DFS(v);
    }
}

// Moi tplt phai co n*(n-1)/2 canh noi giua cac dinh
// Or so dinh ke moi dinh la nhu nhau
   
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        bool kt = 1;

        cin >> n >> m;
        FOR(i,1,m,1) 
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        FOR(i,1,n,1) 
        {
            if(!visited[i]) 
            {
                cnte = 0;
                cntv = 0;
                DFS(i);

                if(cnte != cntv*(cntv-1)) 
                {
                    kt = 0;
                    break;
                }
            }
        }

        cout << (kt ? "YES" : "NO") << '\n';

        FOR(i,1,n,1) 
        {
            adj[i].clear(); 
            visited[i] = 0;
        }   
    }
    return 0;
}