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

ll t, n, check;
string s;

bool kt(string s) 
{
    vector<string> a;
    stringstream ss(s);
    string token;

    while(ss >> token)
    {
        a.pb(token);
    }

    ll x = stoll(a[0]);
    ll y = stoll(a[2]);
    ll z = stoll(a[4]);

    if(x < 10 || y < 10 || z < 10) return 0;

    if(a[1] == "+") return x+y == z;
    
    if(a[1] == "-") return x-y == z;

    if(a[1] == "*") return x*y == z;

    if(a[1] == "/") return (x/y == z) && (x%y == 0);  

    return 0;
}

bool nhanhcan(string s)
{
    
}

void Solve(ll i, string currentStr)
{
    if(check) return;

    if(s[i-1] == '?') 
    {
        if(i == 4) 
        {
            Solve(i+1,currentStr + '+');
            Solve(i+1,currentStr + '-');
            Solve(i+1,currentStr + '*');
            Solve(i+1,currentStr + '/');
        }
        else 
        {
            FOR(j,'0','9',1) 
            {
                string tmp = currentStr + (char)j;
                if(i == 12) 
                {
                    if(kt(tmp)) 
                    {
                        check = 1;
                        cout << tmp << '\n';
                    }
                }
                else if(i < 12) Solve(i+1,tmp);
            }
        }
    }
    else 
    {
        string tmp = currentStr + s[i-1];
        if(i == 12) 
        {
            if(kt(tmp)) 
            {
                check = 1;
                cout << tmp << '\n';
            }
        }
        else if(i < 12) Solve(i+1,tmp);
    }
}

    
int main()
{   
    cin >> t;
    while(t--)
    {
        check = 0;
        scanf("\n");
        getline(cin,s);
        
        Solve(1,"");
        if(check == 0) cout << "WRONG PROBLEM!" << '\n';
    }
    
    return 0;
}