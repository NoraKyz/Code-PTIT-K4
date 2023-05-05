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
vector<ll> child[200001];
ll a[200001], parent[200001];

void Solve(ll root) 
{
    for(auto it : child[root])
    {
        Solve(it);
    }

    if(child[root].empty()) a[root] = 1;
    //else a[root] += child[root].size();

    a[parent[root]] += a[root]+1;
}
    
int main()
{   
    fast_cin

    cin >> n;
    FOR(i,2,n,1) 
    {
        ll x;
        cin >> x;
        child[x].pb(i);
        parent[i] = x;
    }

    Solve(1);

    FOR(i,1,n,1) cout << a[i] << " ";
    
    return 0;
}