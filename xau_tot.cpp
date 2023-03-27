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

ll n;
string s;
vector<ll> a, b;
ll res = 0;

/*
    xau xau gom AB..B, BA..A, AAAAB, BBA.
*/

void Solve(vector<ll> a, vector<ll> b) 
{
    ll len = a.size();

    if(len == 0) return ;

    FOR(i,0,len-2,1) 
    {
        res += a[i+1] - a[i] - 1;

        if(a[i]+1 == a[i+1]) 
        {
            auto it = lower_bound(all(b),a[i]);
            if(it != b.end()) res++;
        }
    }

    res += n - a[len-1] - 1;
}
    
int main()
{   
    fast_cin

    cin >> n;
    cin >> s;

    FOR(i,0,n-1,1) 
    {      
        if(s[i] == 'A') a.pb(i);
        else b.pb(i);
    }

    Solve(a,b);     
    Solve(b,a);

    cout << n * (n - 1) / 2 - res;

    return 0;
}