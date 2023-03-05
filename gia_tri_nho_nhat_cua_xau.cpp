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
    while(t--)
    {
        ll a[500] = {0};
        cin >> n >> s;

        for(auto it : s) a[it]++;
        sort(a+'A',a+'Z'+1);

        while(n--) 
        {
            a['Z']--;
            sort(a+'A',a+'Z'+1);
        }

        ll res = 0;
        FOR(i,'A','Z',1) res += a[i]*a[i];

        cout << res << '\n';
    }
    
    return 0;
}