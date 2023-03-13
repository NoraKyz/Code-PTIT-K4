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

ll t, n, x;
    
int main()
{   
    fast_cin
    ll res = 0;
    cin >> n;
    FOR(i,1,n,1) 
    {
        cin >> x;
        if(x > 0) res += x;
    }

    cout << res * 2;
    
    return 0;
}