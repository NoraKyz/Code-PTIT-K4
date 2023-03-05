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

bool Check()
{
    FOR(i,1,n-1,1) if(a[i] > a[i+1]) return 0;
    return 1;
}
    
int main()
{   
    fast_cin
    cin >> n;
    FOR(i,1,n,1) cin >> a[i];
    ll cnt = 1;
    FOR(i,1,n,1) 
    {
        cout << "Buoc " << cnt++ << ": "; 
        FOR(j,1,n-1,1)
        {
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
        }

        FOR(j,1,n,1) cout << a[j] << " ";
        cout << '\n';

        if(Check()) break;
    }
    
    return 0;
}