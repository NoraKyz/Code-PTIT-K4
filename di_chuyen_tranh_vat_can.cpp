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

ll t, n, a, b, c, d;
char s[150][150];
ll x[] = {0,0,-1,1};
ll y[] = {1,-1,0,0};

ll BFS() 
{
    ll cnt = 0;
    queue<pair<ll,ll>> q;
    bool visited[150][150] = {0};

    q.push({a,b});
    visited[a][b] = 1;

    while(!q.empty()) 
    {
        vector<pair<ll,ll>> v;
        
        while(!q.empty())
        {
            pair<ll,ll> it = q.front();
            v.pb(it);
            q.pop();

            if(it.first == c && it.second == d) return cnt;
        }

        for(auto it : v) 
        {
            FOR(i,it.first+1,n,1) 
            {
                if(s[i][it.second] == 'X') break;              

                if(visited[i][it.second] == 0) 
                {
                    visited[i][it.second] = 1;
                    q.push({i,it.second});
                }
            }

            FORD(i,it.first-1,1,1) 
            {
                if(s[i][it.second] == 'X') break;              

                if(visited[i][it.second] == 0) 
                {
                    visited[i][it.second] = 1;
                    q.push({i,it.second});
                }
            }

            FOR(i,it.second+1,n,1) 
            {
                if(s[it.first][i] == 'X') break;              

                if(visited[it.first][i] == 0) 
                {
                    visited[it.first][i] = 1;
                    q.push({it.first,i});
                }
            }

            FORD(i,it.second-1,1,1) 
            {
                if(s[it.first][i] == 'X') break;              

                if(visited[it.first][i] == 0) 
                {
                    visited[it.first][i] = 1;
                    q.push({it.first,i});
                }
            }
        }

        cnt++;
    }

    return -1;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) FOR(j,1,n,1) cin >> s[i][j];
        cin >> a >> b >> c >> d;

        a++; 
        b++; 
        c++; 
        d++;

        cout << BFS() << '\n';
    }
    
    return 0;
}