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

void Solve(vector<string> v, ll i) 
{
    vector<string> res;
    ll len = v.size()-1;

    FOR(j,0,len,1) res.pb("0" + v[j]);
    FORD(j,len,0,1) res.pb("1" + v[j]);

    if(i < n) Solve(res,i+1);
    else for(auto it : res) cout << it << " ";
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {   
        vector<string> v;
        v.pb("0");
        v.pb("1");

        cin >> n;

        Solve(v,2);
        //else cout << "0 1";

        cout << '\n';
    }
    
    return 0;
}