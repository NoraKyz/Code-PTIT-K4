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
ll a[100][100];
char x[10001];
bool kt = 0;
pair<ll,ll> tele[4] = {{1,0}, {0,-1}, {0,1}, {-1,0}};
char road[4] = {'D','L','R','U'};
bool visited[100][100] = {0};

void Display(ll k)
{
    kt = 1;
    FOR(i,1,k,1) cout << x[i];
    cout << " ";
}

void Solve(ll u, ll v, ll k) 
{
    FOR(i,0,3,1)
    {   
        ll c = u + tele[i].first, d = v + tele[i].second;
        if(c >= 1 && c <= n && d >= 1 && d <= n) 
        {   
            if(a[c][d] == 1 && visited[c][d] == 0) 
            {
                x[k] = road[i];
                if(c != n || d != n) 
                {
                    visited[c][d] = 1;
                    Solve(c,d,k+1);
                    visited[c][d] = 0;
                }
                else Display(k);
            }
        }  
    }
}
    
int main()
{   
    fast_cin
    visited[1][1] = 1;

    cin >> t;
    while(t--)
    {
        cin >> n;  
        FOR(i,1,n,1) FOR(j,1,n,1) cin >> a[i][j];

        kt = 0;
        if(a[1][1] == 1) Solve(1,1,1);
        if(kt == 0) cout << -1;

        cout << '\n';
    }
    
    return 0;
}