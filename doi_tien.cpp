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
ll a[] = {0, 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

ll Solve(ll n)
{
    ll c = 10, cnt = 0;
    while(n > 0) 
    {
        if(n < a[c]) 
        {
            c--;
        }
        else 
        {
            cnt += n/a[c];
            n = n%a[c];
        }
    }
    return cnt;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << Solve(n) << '\n';
    }
    
    return 0;
}