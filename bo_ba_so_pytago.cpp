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

string Solve(ll a[])
{
    FOR(i,1,n-1,1) 
    {
        ll l = i+1, r = n, s = a[l]*a[l] + a[i]*a[i];
        while(l < r) 
        {
            while(l < r && a[r]*a[r] > s) r--;
            if(a[r]*a[r] == s) return "YES"; 
            l++;
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
        cin >> n;
        FOR(i,1,n,1) cin >> a[i];
        sort(a+1,a+1+n);

        cout << Solve(a) << '\n';
    }   
    
    return 0;
}