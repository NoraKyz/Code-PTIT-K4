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
ll x[10001];
string s;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.size();

        ll i = n-1;
        while(i > -1) 
        {
            if(s[i] == '0') break;
            i--;
        }

        if(i == -1) 
        {
            FOR(j,1,n,1) cout << '0';
        }
        else 
        {
            s[i] = '1';
            FOR(j,i+1,n-1,1) s[j] = '0';
            cout << s;
        }

        cout << '\n';
    }
    
    return 0;
}