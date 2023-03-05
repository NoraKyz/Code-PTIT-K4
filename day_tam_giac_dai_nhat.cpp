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
ll a[100001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) cin >> a[i];

        ll res = 0, id = -1e9;
        FOR(i,1,n,1) 
        {
            ll j = i;

            if(i != 1 && i != n) 
            {
                if((a[i] < a[i+1] && a[i-1] < a[i]) || (a[i] > a[i+1] && a[i-1] > a[i])) continue;
            }

            while(a[j] < a[j+1] && j < n) j++;
            while(a[j] > a[j+1] && j < n) j++;

            res = max(res,j-i+1);
        }

        cout << res << '\n';
    }
    
    return 0;
}