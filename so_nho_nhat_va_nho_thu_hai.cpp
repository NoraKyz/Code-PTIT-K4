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
    cin >> t;
    while(t--)
    {
        ll m1 = 1e9, m2 = 1e9;  
        cin >> n;      
        vector<ll> v;
        FOR(i,1,n,1) 
        {
            cin >> x;
            v.pb(x);
            m1 = min(m1,x);
        }

        for(auto it : v) 
        {
            if(it != m1) m2 = min(m2,it);
        }

        if(m2 == 1e9) cout << -1;
        else cout << m1 << " " << m2;
        cout << '\n';
    }
    
    return 0;
}