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
string a, b;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        n = a.size();
        ll x1 = 0, x2 = 0;

        FOR(i,0,n-1,1) 
        {
            if(a[i] != '0') x1 += pow(2,n-i-1);
        }

        n = b.size();
        FOR(i,0,n-1,1) 
        {
            if(b[i] != '0') x2 += pow(2,n-i-1);
        }

        cout << x1 * x2 << '\n';
    }
    
    return 0;
}