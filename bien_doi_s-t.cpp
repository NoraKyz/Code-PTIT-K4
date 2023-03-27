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

ll n, t;
ll x, y;
ll dp[30001] = {0};

ll BFS()
{
    queue<ll> q;
    q.push(x);
    dp[x] = 0;

    while(!q.empty())
    {
        ll v = q.front();
        q.pop();

        if(v == y) return dp[y];

        if(dp[v*2] == -1 && v*2 < 15000) 
        {
            q.push(v*2);
            dp[v*2] = dp[v] + 1;
        }

        if(dp[v-1] == -1) 
        {
            q.push(v-1);
            dp[v-1] = dp[v] + 1;
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
        memset(dp,-1,sizeof(dp));
        cin >> x >> y;
        cout << BFS() << '\n';
    }
    
    return 0;
}