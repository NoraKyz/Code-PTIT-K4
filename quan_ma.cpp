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

ll t, n;
string s;
ll dp[10][10];
ll x[] = {-2,-2,-1,1,2,2,1,-1};
ll y[] = {-1,1,2,2,1,-1,-2,-2};

ll BFS(pair<ll,ll> st, pair<ll,ll> en)
{
    queue<pair<ll,ll>> q;
    q.push(st);

    dp[st.first][st.second] = 0;

    while(!q.empty())
    {
        pair<ll,ll> v = q.front();
        q.pop();

        if(v == en) return dp[v.first][v.second];
        
        FOR(i,0,7,1) 
        {
            ll a = v.first + x[i];
            ll b = v.second + y[i];

            if(a >= 1 && a <= 8 && b >= 1 && b <= 8 && dp[a][b] == -1) 
            {
                dp[a][b] = dp[v.fi][v.se] + 1;
                q.push({a,b});
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
        memset(dp,-1,sizeof(dp));

        cin >> s;
        pair<ll,ll> st = {s[1] - '0', s[0] - 'a' + 1};
        cin >> s;
        pair<ll,ll> en = {s[1] - '0', s[0] - 'a' + 1};

        cout << BFS(st,en) << '\n';
    }
    
    return 0;
}