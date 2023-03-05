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

ll t, n, k, res = 0;
ll a[1001];
vector<string> v;

bool Check() 
{
    ll kt = 0;
    FOR(i,1,n,1) 
    {
        if(a[i] == 0) 
        {
            ll tmp, j = i;
            while(a[j] == 0 && j <= n) j++;
            tmp = j-i;

            if(tmp > k) return 0;
            else if(tmp == k)
            {
                if(kt) return 0;
                kt = 1; 
            }

            i = j;
        }
    }

    return kt;
}

void Solve(ll i)
{
    FOR(j,0,1,1) 
    {
        a[i] = j;
        if(i < n) 
        {
            Solve(i+1);
        }
        else if(Check()) 
        {
            res++; 
            string s = "";
            FOR(i,1,n,1) if(a[i] == 0) s+="A"; else s += "B";
            v.push_back(s);
        }
    }
} 
    
int main()
{   
    fast_cin
    cin >> n >> k;
    Solve(1);
    cout << res << '\n';
    for(auto it : v) cout << it << '\n';
    
    return 0;
}