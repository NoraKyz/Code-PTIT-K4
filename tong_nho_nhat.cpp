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
        ll a[n+1];
        FOR(i,1,n,1) cin >> a[i];
        sort(a+1,a+1+n);

        ll d = 0, b = 0, c = 1;
        FOR(i,1,n,2) 
        {
            d = d*10 + a[i];
            if(a[i] != 0) c*=10;
        }

        c = 1;
        FOR(i,2,n,2) 
        {
            b = b*10 + a[i];
            if(a[i] != 0) c*=10;
        }

        cout << b + d << '\n';
    }
    
    return 0;
}