#include<bits/stdc++.h>
#define FOR(i,a,b,k) for (ll i=a;i<=b;i+=k)
#define FORD(i,a,b,k) for (ll i=a;i>=b;i-=k)
#define pb(i) push_back(i)
#define ll long long int
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define endl '\n'
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const ll MOD=1e9+7;

ll t, n;
string s;
set<string> res;
bool level;

bool isParenthesis(char c)
{
    return ((c == '(') || (c == ')'));
}

bool isValidString(string str)
{
    if(str.empty()) return 0;

    if(str.size() == 1 && isalpha(str[0])) return 0;

    ll cnt = 0;
    for(char it : str)
    {
        if(it == '(') ++cnt;
        else if(it == ')') --cnt;
        
        if(cnt < 0) return 0;
    }
    return !cnt;
}
 
void BFS(string str)
{
    unordered_set<string> visit;
    queue<string> q;
    string temp;
 
    q.push(str);
    visit.insert(str);
    level = 0;

    while (!q.empty())
    {
        str = q.front();  q.pop();

        if (isValidString(str))
        {
            res.insert(str);
            level = 1;
        }

        if (level) continue;
        
        ll len = str.size();

        if(len <= 1) continue;

        FOR(i,0,len,1)
        {
            if (!isParenthesis(str[i])) continue;

            temp = str.substr(0, i) + str.substr(i + 1);
            if (visit.find(temp) == visit.end())
            {
                q.push(temp);
                visit.insert(temp);
            }
        }
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        res.clear();
        cin >> s;

        BFS(s);
        
        if(level) 
        {
            for(auto it : res) cout << it << " ";
        }      
        else cout << -1;

        cout << '\n';
    }
    
    return 0;
}