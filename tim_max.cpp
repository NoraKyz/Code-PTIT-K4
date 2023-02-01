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
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll a[n];
        FOR(i,0,n-1,1) cin >> a[i];
        sort(a,a+n);

        ll sum = 0;
        FOR(i,0,n-1,1) sum = (sum%MOD + a[i]*i%MOD)%MOD;

        cout << sum << '\n';
    }
    
    return 0;
}