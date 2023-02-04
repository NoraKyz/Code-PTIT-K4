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

ll t, n, m, k;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        ll a[n], b[m], c[k];

        for(auto &it : a) cin >> it;
        for(auto &it : b) cin >> it;
        for(auto &it : c) cin >> it;

        vector<ll> res;

        ll i = 0, j = 0, h = 0;

        while(i < n && j < m && h < k) 
        {
            if(a[i] == b[j] && b[j] == c[h]) 
            {
                res.pb(a[i]);
                i++;
                j++;
                h++;
            }
            else if(a[i] <= b[j] && a[i] <= c[h]) i++;
            else if(b[j] <= a[i] && b[j] <= c[h]) j++;
            else h++;
        }

        for(auto it : res) cout << it << " ";
        if(res.size() == 0) cout << "NO"; 
        cout << '\n';
    }
    
    return 0;
}