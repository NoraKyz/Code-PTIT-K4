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
vector<ll> adj[2001];
bool visited[2001] = {0};

int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(i,1,m,1) 
        {
            ll x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        ll cnt = 0;

        FOR(i,1,n,1) 
        {
            if(adj[i].size() % 2) cnt++;
            adj[i].clear();
        }    

        if(cnt == 0) cout << 2;
        else if(cnt <= 2) cout << 1;
        else cout << 0;

        cout << '\n';
    }
    return 0;
}