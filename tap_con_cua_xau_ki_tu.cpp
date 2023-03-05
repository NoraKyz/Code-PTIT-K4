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
vector<string> res;
string s;

void Solve(ll i, ll st, string currentStr, ll k) 
{
    FOR(j,st,n,1) 
    {
        string tmp = currentStr + s[j];
        if(i < k) Solve(i+1,j+1,tmp,k);
        else res.pb(tmp);
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        res.clear();
        cin >> n >> s;
        n--;
        FOR(i,0,n,1) 
        {
            Solve(1,0,"",i+1);
        }

        sort(all(res));
        for(auto it : res) cout << it << " ";
        cout << '\n';
    }
    
    return 0;
}