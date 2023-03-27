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
ll a[550][550];
ll x[] = {0,0,-1,1};
ll y[] = {1,-1,0,0};

ll BFS() 
{
    ll cnt = 0, res = 0;
    queue<pair<ll,ll>> q;

    FOR(i,1,n,1) 
    {
        FOR(j,1,m,1) 
        {
            if(a[i][j] == 2) 
            {
                q.push({i,j});
            }
            
            if(a[i][j] == 1) 
            {
                cnt++;
            }
        }
    }

    if(cnt == 0) return res;

    while(!q.empty()) 
    {
        res ++;

        vector<pair<ll,ll>> v;
        
        while(!q.empty())
        {
            pair<ll,ll> it = q.front();
            v.pb(it);
            q.pop();
        }

        for(auto it : v) 
        {
            FOR(i,0,3,1) 
            {
                ll c = it.first + x[i];
                ll d = it.second + y[i];

                if(c < 1 || c > n || d < 1 || d > m) continue;

                if(a[c][d] == 1) 
                {
                    cnt--;

                    if(cnt == 0) return res;

                    a[c][d] = 2;
                    q.push({c,d});
                } 
            }
        }
    }

    return -1;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(i,1,n,1) FOR(j,1,m,1) cin >> a[i][j];

        cout << BFS() << '\n';
    }
    
    return 0;
}