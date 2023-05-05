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
char b[100][100];
string a[1000];
unordered_map<string, bool> um;
vector<string> res;
ll x[] = {};
ll y[] = {};

void DFS(ll u, ll v, string currentStr) 
{
    FOR(i,0,7,1) 
    {

    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> k >> m >> n;
        FOR(i,1,k,1) 
        {
            cin >> a[i];
            um[a[i]] = 1;
        }

        FOR(i,1,m,1) FOR(j,1,n,1) cin >> b[i][j];

        um.clear();
        res.clear();
    }
    
    return 0;
}