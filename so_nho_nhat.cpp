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

ll t, s, d;
ll a[1001] = {0};

string Solve(ll s, ll d)
{
    a[1] = 1;
    s--;
    if(s < 0) return "-1";

    if(s > 9) a[d] = 9;
    else a[d] = s;

    s -= a[d];
    
    FORD(i,d-1,2,1) 
    {
        if(s > 9) a[i] = 9;
        else a[i] = s;

        s-=a[i];
    } 

    if(s > 0) 
    {
        if(s + a[1] > 9) return "-1";
        else a[1] += s;
    }

    string res = "";
    FOR(i,1,d,1) res += a[i]+'0';
    return res;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s >> d;

        cout << Solve(s,d) << '\n';
    }
    
    return 0;
}