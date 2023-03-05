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

// 1 cách ngắn hơn là trực tiếp sắp xếp

ll Solve(string s)
{
    ll a[1001] = {0};
    n = s.size();
    if(n == 1) return 1;
    for(auto it : s) a[it]++;

    FOR(i,'a','z',1) if(a[i] > n/2 + n%2) return -1;
    return 1;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << Solve(s) << '\n'; 
    }
    
    return 0;
}