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

ll t, n, m, q;
ll d[105][105];
  
int main()
{   
    fast_cin
    
    {
        cin >> n >> m;

        memset(d, MOD, sizeof(d));

        FOR(i,1,n,1) d[i][i] = 0;
    
        FOR(i,1,m,1)
        {
            ll u, v, w;
            cin >> u >> v >> w;
            d[u][v] = w;
            d[v][u] = w;
        }

        FOR(k,1,n,1) 
        {
            FOR(i,1,n,1) 
            {
                FOR(j,1,n,1) 
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        cin >> q;
        FOR(i,1,q,1) 
        {
            ll u, v;
            cin >> u >> v;
            cout << d[u][v] << '\n';
        }
    }
    
    return 0;
}