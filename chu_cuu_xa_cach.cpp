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

ll t, n, k, q, cnt, res;
ll a[105][105] = {0};
bool vs[105][105] = {0};
vector<pair<ll,ll>> m[105][105];
ll x[4] = {0, 0, 1, -1};
ll y[4] = {1, -1, 0, 0};

ll kt(ll u, ll v, ll c, ll d) 
{
    for(auto it : m[u][v]) 
    {
        if(it.fi == c && it.se == d) return 0;
    }

    return 1;
}

void dfs(ll u, ll v) 
{
    vs[u][v] = 1;
    cnt += a[u][v]; 

    FOR(i,0,3,1) 
    {
        ll c = u + x[i];
        ll d = v + y[i];

        if(c >= 1 && c <= n && d >= 1 && d <= n) 
        {
            if(!vs[c][d]) 
            {
                if(!kt(u,v,c,d)) continue;

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

        cin >> n >> q >> k;

        FOR(i,1,k,1) 
        {
            ll xa, xb, ya, yb;
            cin >> xa >> ya >> xb >> yb;

            m[xa][ya].push_back({xb,yb});
            m[xb][yb].push_back({xa,ya});
        }

        FOR(i,1,q,1) 
        {
            ll xa, ya;
            cin >> xa >> ya;
            a[xa][ya] = 1; 
        }

        FOR(i,1,n,1) 
        {
            FOR(j,1,n,1) if(vs[i][j] == 0) 
            {
                cnt = 0;
                dfs(i,j);
                res += cnt * (cnt - 1) / 2;
            }
        }

        cout << q*(q-1)/2 - res;
    }
    
    return 0;
}