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

ll t, n, m, x;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        ll a = -1e9, b = 1e9;

        cin >> n >> m;
        FOR(i,1,n,1) 
        {
            cin >> x;
            a = max(a,x);
        }
        FOR(i,1,m,1) 
        {
            cin >> x;
            b = min(b,x);
        }

        cout << a*b << '\n';
    }
    
    return 0;
}