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
string s;
    
int main()
{   
    fast_cin
    cin >> t;
    vector<ll> v;
    while(t--)
    {
        cin >> s;
        if(s == "PUSH") 
        {
            cin >> n;
            v.pb(n);
        }
        else if(s == "PRINT") 
        {
            if(v.empty()) cout << "NONE";
            else cout << v.back();
            cout << '\n';
        }
        else 
        {
            if(!v.empty()) v.pop_back();
        }
    }
    
    return 0;
}