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
string s;
    
int main()
{   
    cin >> t;
    while(t--)
    {
        scanf("\n");
        getline(cin,s);
        stringstream ss(s);

        vector<string> v;
        string token;
        while(ss >> token)
        {
            v.pb(token);
        }

        n = v.size();

        FORD(i,n-1,0,1) 
        {
            cout << v[i] << " ";
        }

        cout << '\n';
    }
    
    return 0;
}