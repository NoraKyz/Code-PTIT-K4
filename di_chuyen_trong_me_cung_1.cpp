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

void Display(ll k)
{
    kt = 1;
    FOR(i,1,k,1) cout << x[i];
    cout << " ";
}

void Solve(ll u, ll v, ll k) 
{
    FOR(i,0,1,1)
    {
        if(i == 0) 
        {
            ll c = u + 1, d = v + 0;
            if(c >= 1 && c <= n && d >= 1 && d <= n) 
            {   
                if(a[c][d] == 1) 
                {
                    x[k] = 'D';
                    if(c != n || d != n) Solve(c,d,k+1);
                    else Display(k);
                }
            }
        }
        else 
        {
            ll c = u + 0, d = v + 1;
            if(c >= 1 && c <= n && d >= 1 && d <= n) 
            {   
                if(a[c][d] == 1) 
                {
                    x[k] = 'R';
                    if(c != n || d != n) Solve(c,d,k+1);
                    else Display(k);
                }
            }
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        kt = 0;
        FOR(i,1,n,1) FOR(j,1,n,1) cin >> a[i][j];
        if(a[1][1] == 1) Solve(1,1,1);
        if(kt == 0) cout << -1;
        cout << '\n';
    }
    
    return 0;
}