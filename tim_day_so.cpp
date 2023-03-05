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
ll a[1001];
ll x[2002][2002] = {0};
    
int main()
{   
    fast_cin
    cin >> n;
    FOR(i,1,n,1) cin >> a[i];

    FOR(i,1,2000,1) 
    {
        FOR(j,1,i,1) 
        {
            if(x[i][i/j] == 0) x[i][i/j] = j;
        }
    }

    ll m = min_element(a+1,a+1+n)-a;
    m = a[m];

    ll res = 1e9;
    FOR(i,1,m,1) 
    {
        ll tmp = 0, kt = 1;
        FOR(j,1,n,1) 
        {
            if(x[a[j]][i] == 0) 
            {
                kt = 0;
                break;
            }
            else tmp += x[a[j]][i];
        }

        if(kt) res = min(res,tmp);
    }

    cout << res;
    
    return 0;
}