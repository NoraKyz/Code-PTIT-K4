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
vector<ll> adj[1001], r_adj[1001];
bool visited[1001] = {0};
stack<ll> st;

void DFS1(ll u)
{
    visited[u] = 1;
    for(ll v : adj[u])
    {
        if(!visited[v]) DFS1(v);
    }
    st.push(u);
}

void DFS2(ll u)
{
    visited[u] = 1;
    for(ll v : r_adj[u])
    {
        if(!visited[v]) DFS2(v);
    }
}

void SCC()
{
    ll cnt = 0;
    
    memset(visited,0,sizeof(visited));

    FOR(i,1,n,1) 
    {
        if(!visited[i]) DFS1(i);
    }

    memset(visited,0,sizeof(visited));

    while(!st.empty())
    {
        ll u = st.top(); st.pop();

        if(!visited[u])
        {
            cnt++;
            DFS2(u);
        }
    }

    if(cnt == 1) cout << "YES";
    else cout << "NO";
}
    
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
            r_adj[y].pb(x);
        }

        SCC();

        FOR(i,1,n,1) 
        {
            adj[i].clear();
            r_adj[i].clear();
        }

        cout << '\n';
    }
    
    return 0;
}