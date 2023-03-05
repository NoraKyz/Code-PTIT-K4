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

string Solve()
{
    FOR(i,1,n-1,1) 
    {
        ll l = i+1, r = n, s = k - a[i];
        while(l < r) 
        {
            if(a[r] + a[l] == s) return "YES";
            else if(a[r] + a[l] < s) l++;
            else r--;
        }
    }

    return "NO";
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i,1,n,1) cin >> a[i];
        sort(a+1,a+1+n);
    
        cout << Solve() << '\n';
    }
    
    return 0;
}