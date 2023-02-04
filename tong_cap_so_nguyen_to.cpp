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
ll prime[1000001] = {0};
vector<ll> v;
void Sieve(ll n)
{
    prime[2] = 1;
    v.pb(2);
    FOR(i,3,n,2) prime[i] = 1;
    FOR(i,3,n,2)
    {
        if(prime[i]) 
        {
            v.pb(i);
            FOR(j,i*3,n,i*2) prime[j] = 0;
        }
    }
}
    
int main()
{   
    fast_cin
    Sieve(1000000);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll kt = 0;

        for(auto it : v) 
        {
            if(n-it <= 0) break;
            else 
            {
                if(prime[n-it]) 
                {
                    kt = 1;
                    cout << it << " " << n-it;
                    break;
                }
            }
        }

        if(kt == 0) cout << -1;

        cout << '\n';
    }
    
    return 0;
}