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
ll a[505][505];
ll x[] = {0,0,1,1,-1,-1,-1,1};
ll y[] = {1,-1,1,-1,0,1,-1,0};

void DFS(ll u, ll v) 
{
    a[u][v] = 0;
    FOR(k,0,7,1) 
    {
        ll c = u + x[k];
        ll d = v + y[k];
        if(c >= 1 && c <= n && d >= 1 && d <= m) 
        {
            if(a[c][d]) DFS(c,d);
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll res = 0;

        cin >> n >> m;
        FOR(i,1,n,1) FOR(j,1,m,1) cin >> a[i][j];

        FOR(i,1,n,1) 
        {
            FOR(j,1,m,1) 
            {
                if(a[i][j]) 
                {
                    res++;
                    DFS(i,j);
                }
            }
        }

        cout << res << '\n';
    }
    
    return 0;
}