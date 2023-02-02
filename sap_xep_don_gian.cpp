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
ll a[100005], vt[100005];
    
int main()
{   
    fast_cin
    cin >> n;
    FOR(i,1,n,1) 
    {
        cin >> a[i];
        vt[a[i]] = i;
    }

    ll len = 1, ans = 1;
    FOR(i,2,n,1) 
    {
        if(vt[i] > vt[i-1]) len++;
        else len = 1;
        
        ans = max(ans, len);
    }

    cout << n-ans;
    
    return 0;
}