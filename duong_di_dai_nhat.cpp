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

ll t, n, m, res;
vector<ll> adj[200];
bool vs[200][200] = {0};

void Solve(ll i, ll lenOfNum) 
{
    bool kt = 0;

    for(auto it : adj[i]) 
    {
        if(vs[i][it] == 0) 
        {
            kt = 1;

            vs[i][it] = 1;
            vs[it][i] = 1;
            Solve(it, lenOfNum+1);
            vs[i][it] = 0; 
            vs[it][i] = 0; 
        } 
    }

    if(kt == 0) res = max(res, lenOfNum);
    
}
   
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        res = -1;

        cin >> n >> m;
        FOR(i,1,m,1) 
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        FOR(i,0,n-1,1) Solve(i,0);

        cout << res << '\n';
       
        FOR(i,0,n-1,1) adj[i].clear();    
    }
    return 0;
}