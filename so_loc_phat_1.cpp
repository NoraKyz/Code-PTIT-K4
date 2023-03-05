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
ll a[100];
vector<ll> res;

ll Sinh(ll n)
{
    ll res = 0;
    FOR(i,1,n,1) res = res*10 + a[i];
    return res;
}

void Solve(ll i)
{
    FOR(j,0,1,1) 
    {
       if(j == 0) 
       {
            a[i] = 6;
            res.pb(Sinh(i));
            if(i < n) Solve(i+1);
       } 
       else 
       {
            a[i] = 8;
            res.pb(Sinh(i));
            if(i < n) Solve(i+1);
       }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {  
        res.clear();
        cin >> n;
        Solve(1);
        sort(all(res),greater<ll>());
        for(auto it : res) cout << it << " ";
        cout << '\n';
    }
    
    return 0;
}