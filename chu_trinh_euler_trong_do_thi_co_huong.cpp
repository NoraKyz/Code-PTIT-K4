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

ll t, n, m, q;
vector<ll> adjIn[2001], adjOut[2001];
bool visited[2001] = {0};

int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        FOR(i,1,m,1) 
        {
            ll x, y;
            cin >> x >> y;
            adjIn[y].pb(x);
            adjOut[x].pb(y);
        }

        ll cnt = 0;

        FOR(i,1,n,1) 
        {
            if(adjIn[i].size() != adjOut[i].size()) cnt++;
            adjIn[i].clear();
            adjOut[i].clear();
        }    

        if(cnt == 0) cout << 1;
        else cout << 0;

        cout << '\n';
    }
    return 0;
}