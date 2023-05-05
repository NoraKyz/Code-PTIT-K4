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
vector<ll> adj[2001];
bool visited[2001] = {0};

bool kt(ll i, ll u) 
{
    for(auto it : adj[u])
    {
        if(!visited[it])
        {
            if(i == n) return 1;

            visited[it] = 1;
            if(kt(i+1, it))  return 1; 
            visited[it] = 0;
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
        bool res = 0;
        memset(visited, 0, sizeof(visited));

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
            FOR(i,1,n,1) visited[i] = 0;
            
            visited[i] = 1;
            if(kt(2, i)) 
            {
                res = 1;
                break;
            }
        }

        cout << res << '\n';

        FOR(i,1,n,1) adj[i].clear();    
    }
    return 0;
}