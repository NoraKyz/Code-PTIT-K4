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

        ll res[11] = {0};
        FOR(i,1,n,1) 
        {
            while(a[i] > 0) 
            {
                res[a[i]%10]++;
                a[i]/=10;
            }
        }

        FOR(i,0,9,1) if(res[i] > 0) cout << i << " ";
        cout << '\n';
    }
    
    return 0;
}