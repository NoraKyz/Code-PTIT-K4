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

ll t, k;
string s;
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> k >> s;
        ll id = 0, n = s.size()-1, idc = 0, c = 0;
        char x = '0';

        while(k > 0 && id < n)
        {
            x = '0';
            idc = 0;
            c++;

            FOR(i,id,n,1) 
            {
                if(s[i] >= x) 
                {
                    idc = i;
                    x = s[i];
                }
            }

            if(idc != id && k > 0 && s[idc] != s[id]) 
            {
                k--;
                swap(s[id], s[idc]);
            }

            id++;
        }
        
        cout << s << '\n';
    }
    
    return 0;
}