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

struct Node
{
    char value;
    Node *left, *right;
};

typedef Node* binTree;

binTree createNode(char c) 
{
    binTree res = new Node;
    res -> value = c;
    res -> left = res -> right = NULL;

    return res;
} 

void inOrder(binTree a) 
{
    if(a != NULL) 
    {
        inOrder(a -> left);
        cout << a -> value;
        inOrder(a -> right);
    }
}
    
int main()
{   
    fast_cin
    cin >> t;
    while(t--)
    {
        stack<binTree> st;
        cin >> s;
        
        for(char it : s) 
        {
            if(it == '+' || it == '-' || it == '*' || it == '/') 
            {
                binTree tmp = createNode(it);
                tmp -> right = st.top();
                st.pop();
                tmp -> left = st.top();
                st.pop();
                st.push(tmp);
            }
            else st.push(createNode(it));
        }

        inOrder(st.top());
        cout << '\n';
    }
    
    return 0;
}