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

bool kt(char x)
{
    if(x == '+' || x == '-') return 1;
    return 0;
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> s;
        n = s.size() - 1;

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

        FOR(i,0,n,1) 
        {
            if(s[i] >= 'a' && s[i] <= 'z') cout << s[i];
            else if(kt(s[i]) && !kt(s[i+1])) cout << s[i];
        }

        cout << '\n';
    }
    
    return 0;
}