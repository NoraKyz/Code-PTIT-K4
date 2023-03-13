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

ll t, n, m, ans;
vector<ll> adj[2001];
bool visited[2001] = {0};

void DFS(ll u, ll x)
{
    visited[u] = 1;
    for(ll v : adj[u])
    {
        if(!visited[v] && v != x) 
        {
            DFS(v,x);
        }
    }
}
   
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        vector<ll> res;
        ans = 0;

        cin >> n >> m;
        FOR(i,1,m,1) 
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        memset(visited,0,sizeof(visited));
        
        FOR(i,1,n,1) 
        {
            if(visited[i] == 0) 
            {
                ans++;
                DFS(i,0);
            }
        }

        ll tmp = ans;

        FOR(i,1,n,1) 
        {        
            memset(visited,0,sizeof(visited));

            ans = 0;
            FOR(j,1,n,1) 
            {
                if(visited[j] == 0) 
                {
                    if(j != i)
                    {
                        ans++;
                        DFS(j,i);
                    }                
                }
            }

            if(ans > tmp) res.pb(i);
        }

        for(auto it : res) cout << it << " ";
        cout << '\n';

        FOR(i,1,n,1) adj[i].clear();  
    }
    return 0;
}