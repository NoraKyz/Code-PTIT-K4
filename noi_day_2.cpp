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
        priority_queue<ll,vector<ll>,greater<ll>> q;
        ll x, y, res = 0;
        
        cin >> n;
        FOR(i,1,n,1) 
        {
            cin >> x;
            q.push(x);
        }

        while(q.size() != 1)
        {
            x = q.top();
            q.pop();
            y = q.top();
            q.pop();

            res += (x + y);
            res = res%MOD;
            q.push((x%MOD+y%MOD)%MOD);
        }

        cout << res << '\n';
    }
    
    return 0;
}