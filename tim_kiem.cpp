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

ll t, n, k, x;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<ll> v;
        FOR(i,1,n,1) 
        {
            cin >> x;
            v.pb(x);
        }

        if(binary_search(all(v),k)) cout << 1;
        else cout << -1;

        cout << '\n';
    }
    
    return 0;
}