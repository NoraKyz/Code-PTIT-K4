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
char a[105][105];
bool vs[105][105] = {0};
ll x[8] = {0, 0, 1, 1, 1, -1, -1, -1};
ll y[8] = {1, -1, 0, -1, 1, 0, -1, 1};

void dfs(ll u, ll v) 
{
    vs[u][v] = 1;

    FOR(i,0,7,1) 
    {
        ll c = u + x[i];
        ll d = v + y[i];

        if(c >= 1 && c <= n && d >= 1 && d <= m) 
        {
            if(!vs[c][d] && a[c][d] == '.') 
            {
                dfs(c,d);
            }
        }
    }
}

int main()
{   
    fast_cin

    {   
        res = 0;

        cin >> n >> m;

        FOR(i,1,n,1) 
        {
            FOR(j,1,m,1) cin >> a[i][j];
        }

        FOR(i,1,n,1) 
        {
            FOR(j,1,m,1) if(vs[i][j] == 0 && a[i][j] == '.') 
            {
                res++;
                dfs(i,j);
            }
        }

        cout << res;
    }
    
    return 0;
}