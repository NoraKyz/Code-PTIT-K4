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

//inline ll readll()       {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();ll  n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
//inline string readstring() {char c;while(c=getchar(),c==' '||c=='\n'||c=='\t');string s({c});while(c=getchar(),c!=EOF&&c!=' '&&c!='\n'&&c!='\t')s+=c;return s;}

// hết phần lộn xào rồi, vào main code thoi :v

/* Không theo thuật toán nhưng học vì nó vui
                                -Lê Quý Long- */

ll t, n;
unordered_map<ll,ll> f;

ll fi(ll n)
{
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;

    if(f[n]) return f[n];

    if(n%2 == 0) 
    {
        ll k = n/2;
        f[n] = (2*fi(k-1)%MOD + fi(k)%MOD)*fi(k)%MOD;
        return f[n];
    }
    else 
    {
        ll k = (n+1)/2;
        f[n] = (fi(k)*fi(k)%MOD + fi(k-1)*fi(k-1)%MOD)%MOD;
        return f[n];
    }
}


int main()
{
    	fast_cin 	
	//freopen("TEST.INP", "r", stdin);
	//freopen("TEST.OUT", "w", stdout);
    f[1] = 1;
    f[2] = 1;

    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << fi(n) << '\n';
    }
	
	return 0;
}