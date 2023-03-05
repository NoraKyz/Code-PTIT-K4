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
ll a[200001], b[200001];
vector<ll> res;
unordered_map<ll,ll> m;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) 
        {
            cin >> a[i];
            m[a[i]]++;
            b[i] = a[i];
        }
        
        sort(b+1,b+1+n);
        ll l = 1;

        ll Ma = -1e10, mi = 1e10;
        FOR(i,1,n-1,1) 
        {
            m[a[i]]--;
            while(m[b[l]] == 0) l++;
            Ma = max(Ma,a[i]);
            mi = b[l];
            if(Ma <= mi) res.pb(i);
        }

        cout << res.size() << '\n';
        for(auto it : res) cout << it << " ";
        cout << '\n';

        res.clear();
        m.clear();
    }
    
    return 0;
}