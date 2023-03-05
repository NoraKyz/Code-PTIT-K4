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

ll t, n, s;

string SolveMin(ll s) 
{
    if(s < 1 || s > n*9) return "-1";
    string res = "";

    ll a[1000];

    a[1] = 1;
    s--;
    FOR(i,2,n,1) a[i] = 0;
    
    ll l = n;
    while(s > 0) 
    {
        if(s >= 9) 
        {
            a[l]+=9;
            s-=9;
        }
        else 
        {
            a[l]+=s;
            s = 0;
        }
        l--;
    }

    FOR(i,1,n,1) res += a[i] + '0';
    return res;
}   

string SolveMax(ll s) 
{
    if(s > n*9 || s < 1) return "-1";
    string res = "";

    ll a[1000];

    if(s >= 9) 
    {
        a[1] = 9;
        s-=9;
    }
    else 
    {
        a[1] = s;
        s = 0;
    }
    
    FOR(i,2,n,1) a[i] = 0;
    
    ll l = 2;
    while(s > 0) 
    {
        if(s >= 9) 
        {
            a[l]+=9;
            s-=9;
        }
        else 
        {
            a[l]+=s;
            s = 0;
        }
        l++;
    }

    FOR(i,1,n,1) res += a[i] + '0';
    return res;
}
    
int main()
{   
    fast_cin
    
    {
        cin >> n >> s;
        cout << SolveMin(s) << " " << SolveMax(s) << '\n';
    }
    
    return 0;
}
