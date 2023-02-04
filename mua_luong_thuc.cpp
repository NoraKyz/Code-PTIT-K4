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

ll t, n, s, m;

ll Solve(ll n, ll s, ll m)
{
    ll cnt = n, res = 1, day = 1;

    if(cnt < m) return -1;

    while(cnt < m*s) 
    {
        day++;

        if(day%7 == 0) 
        {
            if(cnt < day*m) return -1;
        }
        else 
        {
            res++;
            cnt += n;
        }
    }

    return res;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> s >> m;
        cout << Solve(n,s,m) << '\n';
    }
    
    return 0;
}