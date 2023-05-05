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
string a, b;

bool cmp(pair<ll,ll> a, pair<ll,ll> b) 
{
    return a.first > b.first;
}

void Solve(string a, string b)
{
    unordered_map<ll,ll> m;

    stringstream ssa(a);
    string token;
    while(ssa >> token) 
    {
        if(token == "+") continue;

        ll len = token.size()-1;
        string tm1p = "", tm2p = "";
        ll i = 0;
        while(token[i] != '*') 
        {
            tm1p += token[i];
            i++;
        }

        i+=3;
        while(i <= len) 
        {
            tm2p += token[i];
            i++;
        }

        m[stoll(tm2p)] += stoll(tm1p);
    }

    stringstream ssb(b);
    while(ssb >> token) 
    {
        if(token == "+") continue;

        ll len = token.size()-1;
        string tm1p = "", tm2p = "";
        ll i = 0;
        while(token[i] != '*') 
        {
            tm1p += token[i];
            i++;
        }

        i+=3;
        while(i <= len) 
        {
            tm2p += token[i];
            i++;
        }

        m[stoll(tm2p)] += stoll(tm1p);
    }

    vector<pair<ll,ll>> res(all(m));
    sort(all(res),cmp);

    bool kt = 0;
    for(auto it : res) 
    {
        if(kt) 
        {
            cout << " + ";
        }
        kt = 1;
        cout << it.second << "*x^" << it.first;
    }
}

int main()
{   
    cin >> t;
    while(t--)
    {
        scanf("\n");
        getline(cin,a);
        scanf("\n");
        getline(cin,b);

        Solve(a,b);
        cout << '\n';
    }
    
    return 0;
}