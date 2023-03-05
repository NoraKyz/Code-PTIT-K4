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

ll t, n, k;
ll a[100001];
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        deque<ll> d;
        cin >> n >> k;
        FOR(i,1,n,1) cin >> a[i];

        FOR(i,1,n,1) 
        {
            while(!d.empty() && a[d.front()] <= a[i]) 
            {
                d.pop_front();
            }
            d.push_front(i);

            if(i >= k) 
            {
                cout << a[d.back()] << " ";
                if(d.back() == i-k+1) d.pop_back();
            }
        }

        cout << '\n';
    }
    
    return 0;
}