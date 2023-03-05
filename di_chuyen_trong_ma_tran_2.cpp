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

ll adj[1001][1001], d[1001][1001];
ll n, m;

ll BFS()
{
    queue<pair<int, int>> q;
    q.push({1,1});
    d[1][1] = 0;
    while(!q.empty()){
        pair<ll, ll> top = q.front(); q.pop();
    
        ll a = top.first;
        ll b = top.second;

        if(a == n && b == m){
            return d[a][b];
        }

        int x = a + adj[a][b];
        int y = b + adj[a][b];

        if(d[a][y] == -1){
            q.push({a,y});
            d[a][y] = d[a][b]+1;
        }

        if(d[x][b] == -1){
            q.push({x,b});
            d[x][b] = d[a][b] + 1;
        }
    }

    return -1;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(i,1,n,1) FOR(j,1,m,1)
        {
            cin >> adj[i][j];
            d[i][j] = -1;
        }
        cout << BFS() << endl;
    }
}