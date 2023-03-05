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

ll t, n = 8, res;
ll x[10][10];
ll a[100] = {0}, b[100] = {0}, c[100] = {0}, d[100] = {0};

void Solve(ll i, ll sum)
{
    FOR(j,1,n,1) 
    {
        if(a[j] == 0 && b[i+j] == 0 && ((i-j < 0 && c[abs(i-j)] == 0) || (i-j >= 0 && d[i-j] == 0)))
        {
            ll tmp = sum + x[i][j];
            if(i == n) res = max(res, tmp);
            else 
            {
                a[j] = 1; b[i+j] = 1; 
                if(i-j < 0) c[abs(i-j)] = 1;
                else d[i-j] = 1;

                Solve(i+1, tmp);
                
                a[j] = 0; b[i+j] = 0; 
                if(i-j < 0) c[abs(i-j)] = 0;
                else d[i-j] = 0;
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
        FOR(i,1,n,1) 
        {
            FOR(j,1,n,1) cin >> x[i][j];
        }
        res = -1e9;
        Solve(1,0);
        cout << res << '\n';
    }
    
    return 0;
}