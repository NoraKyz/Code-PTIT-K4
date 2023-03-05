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
deque<ll> d;
string s;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        if(s == "PUSH") 
        {
            cin >> n;
            d.push_back(n);
        }
        else if(s == "PRINTFRONT") 
        {
            if(d.empty()) cout << "NONE";
            else cout << d.front();

            cout << '\n';
        }
        else
        {
            if(!d.empty()) d.pop_front();
        }
        
    }
    
    return 0;
}