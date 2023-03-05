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
ll a[10001];
string s;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        char tmp = s[0];
        cout << tmp;
        n = s.size();
        FOR(i,1,n-1,1) if(s[i] == '0') 
        {
            cout << tmp;
        }
        else 
        {
            if(tmp == '0') tmp = '1';
            else tmp = '0';
            
            cout << tmp;
        }

        cout << '\n';
    }
    
    return 0;
}