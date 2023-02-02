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

ll ModulePow(ll a, ll b)
{
    if(b == 0) return 1;
    
    ll k = ModulePow(a,b/2)%MOD;

    if(b%2 == 0) return k*k%MOD;
    else return ((k*k%MOD)*a)%MOD;
}
    
int main()
{   
    fast_cin
    //cin >> t;
    while(1)
    {
        cin >> n >> k;
        if(n == k && n == 0) break;
        cout << ModulePow(n,k) << '\n';
    }
    
    return 0;
}