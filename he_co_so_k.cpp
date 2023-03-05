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
string s1, s2;

ll Equal(string &s1, string &s2) { 
    ll len1 = s1.size();
    ll len2 = s2.size();
    if (len1 < len2) 
    { 
        FOR(i,0,len2-len1-1,1) s1 = '0' + s1;
        return len2; 
    } 
    else if (len1 > len2)  
    { 	
        FOR(i,0,len1-len2-1,1) s2 = '0' + s2;
    } 
    return len1;
} 

string Solve(string s1, string s2, ll k) { 
    string result = ""; 

    ll length = Equal(s1, s2); 

    ll carry = 0;

    FORD(i,length-1,0,1)
    { 
        ll val1 = s1.at(i) - '0'; 
        ll val2 = s2.at(i) - '0';
        ll sum = (val1 + val2 + carry)%k +'0';
        carry = (val1 + val2 + carry)/k;
        result = (char)sum + result;  
    }   
    if (carry)  
    {
    	char x = ('0' + carry);
    	result = x + result; 
	}  
    return result; 
} 
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        cin >> k >> s1 >> s2;
        cout << Solve(s1,s2,k) << '\n';
    }
    
    return 0;
}