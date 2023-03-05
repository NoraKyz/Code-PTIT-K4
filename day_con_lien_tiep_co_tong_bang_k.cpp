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

ll t, n, k;
ll a[100001];

string Solve()
{
    if(a[1] == k) return "YES";
    if(n >= 1 && a[1] + a[2] == k) return "YES";

    ll l = 1, r = 2, currSum = a[1] + a[2];
    while(r <= n) 
    {
        if(currSum == k) return "YES";

        if(currSum > k) 
        {
            if(l < r) 
            {
                currSum -= a[l];
                l++;             
            } 
            else 
            {
                l++;
                r++;
                currSum = a[r];
            }
        }
        else if(currSum < k)
        {
            r++;
            currSum +=a[r];
        }
    }

    return "NO";
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i,1,n,1) cin >> a[i];
        cout << Solve() << '\n';
    }
    
    return 0;
}