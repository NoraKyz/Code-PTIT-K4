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

ll t, n, k;
ll f[100];
string s;

char Solve(ll f[], ll k, ll n) 
{

    if(n == 1) return s[k-1];

    if(k <= f[n-1]) return Solve(f,k,n-1);
    else 
    {
        ll x = k - f[n-1];
        if(x == 1) return Solve(f,f[n-1],n-1);
        else return Solve(f,x-1,n-1);
    } 
    
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s >> k;

        n = s.size();
        f[1] = n;

        FOR(i,2,100,1) 
        {
            f[i] = f[i-1] * 2;
            if(f[i] >= k) 
            {
                cout << Solve(f,k,i) << '\n';
                break;
            }
        }
    } 
    
    return 0;
}