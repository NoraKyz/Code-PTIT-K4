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

ll t, n, l, r;
bool kt[6] = {0};
vector<ll> res;

void Solve(ll i, ll st, ll currentNum) 
{
    FOR(j,st,5,1) 
    {
        if(kt[j] == 0) 
        {
            ll tmp = currentNum * 10 + j;
            res.pb(tmp);

            if(i < 5) 
            {
                kt[j] = 1;
                Solve(i+1,0,tmp);
                kt[j] = 0;
            }
        }
    }
}
    
int main()
{   
    fast_cin
    res.pb(0);
    Solve(1,1,0);
    sort(all(res));

    cin >> t;
    while(t--)
    {
        cin >> l >> r;

        ll c = lower_bound(all(res),l) - res.begin();
        ll d = upper_bound(all(res),r) - res.begin();

        cout << d - c << '\n';
    }

    //for(auto it : res) if(it > 100) break; else cout << it << " ";
    
    return 0;
}