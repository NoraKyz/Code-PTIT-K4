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
ll a[10001], x[10001];
vector<string> res;

void Solve(ll i, ll st, ll currentSum)
{
    FOR(j,st,n,1) 
    {
        x[i] = a[j];
        ll tmp = currentSum + a[j];
        if(tmp < k) Solve(i+1,j,tmp);
        else if(tmp == k) 
        {
            string s = "{" + to_string(x[1]);
            FOR(h,2,i,1) s += " " + to_string(x[h]);
            s += "}";
            res.push_back(s);
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        res.clear();
        cin >> n >> k;
        FOR(i,1,n,1) cin >> a[i];
        sort(a+1,a+1+n);
        Solve(1,1,0);

        if(res.size() == 0) cout << -1 << '\n';
        else 
        {
            cout << res.size() << " ";
            for(auto it : res) cout << it << " ";
            cout << '\n';
        }

    }
    
    return 0;
}