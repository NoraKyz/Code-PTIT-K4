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
pair<ll,ll> a[10001];

bool ss(pair<ll,ll> a, pair<ll,ll> b)
{
    return a.second > b.second;
}

// lam truoc deadline 1 don vi thoi gian la toi uu nhat
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n;
        FOR(i,1,n,1) 
        {
            cin >> a[i].first;
            cin >> a[i].first >> a[i].second;
        }

        sort(a+1,a+1+n,ss);

        ll cnt = 0, res = 0;
        bool kt[1001] = {0};
        
        FOR(i,1,n,1) 
        {
            FORD(j,a[i].first-1,0,1)
            {
                if(kt[j] == 0) 
                {
                    cnt ++;
                    res += a[i].second;
                    kt[j] = 1;
                    break;
                }
            }
        }


        cout << cnt << " " << res << '\n';
    }
    
    return 0;
}