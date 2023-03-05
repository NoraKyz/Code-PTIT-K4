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
vector<ll> v;
ll a[100] = {0,9};

ll Nap(ll n)
{
    ll res = 0;
    FOR(i,1,n,1) res = res*10 + a[i];
    return res; 
}

void Solve(ll i) 
{
    FOR(j,0,1,1) 
    {
        if(j == 0) a[i] = j;
        else a[i] = 9;

        if(i < 19) 
        {
            v.pb(Nap(i));
            Solve(i+1);
        }
    }
}

    
int main()
{   
    fast_cin
    v.pb(9);
    Solve(2);
    sort(all(v));
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 0) cout << 9 << '\n';
        else 
        {
            for(auto it : v) 
            {
                
                if(it%n == 0) 
                {
                    cout << it << '\n';
                    break;
                }
            }
        }

        //cout << v.size();
    }

    
    return 0;
}