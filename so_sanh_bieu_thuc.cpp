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
string x, y;

bool kt(char x)
{
    if(x == '+' || x == '-') return 1;
    return 0;
}

string DeleteNgoac(string s)
{
    n = s.size() - 1;

    stack<char> st;

    FORD(i,n,0,1) 
    {
        if(kt(s[i]) && s[i+1] == '(')
        {
            ll j = i+1;

            while(s[j] != ')') 
            {
                if(s[i] == '-') 
                {
                    if(s[j] == '+') s[j] = '-';
                    else if(s[j] == '-') s[j] = '+';
                }

                j++;
            } 

            s[i+1] = '.'; s[j] = '.';
        }
    }

    string res = "";

    FOR(i,0,n,1) 
    {
        if(s[i] >= 'a' && s[i] <= 'z') res += s[i];
        else if(kt(s[i]) && !kt(s[i+1])) res += s[i];
    }

    return res;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        x = DeleteNgoac(x);
        y = DeleteNgoac(y);

        if(x == y) cout << "YES";
        else cout << "NO";

        cout << '\n';
    }
    
    return 0;
}