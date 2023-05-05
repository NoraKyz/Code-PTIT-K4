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
struct Node
{
    ll value;
    Node *left, *right;
};

typedef Node* binTree;

binTree createNode(ll c) 
{
    binTree res = new Node;
    res -> value = c;
    res -> left = res -> right = NULL;

    return res;
} 

void buildTree(binTree &parent, char c, ll par, ll child) 
{
    if(parent != NULL) 
    {
        if(parent -> value == par) 
        {
            if(c == 'L') 
                parent -> left = createNode(child);
            else 
                parent -> right = createNode(child);
        }
        buildTree(parent -> left, c, par, child);
        buildTree(parent -> right, c, par, child);
    } 
}

void spiralOrder(binTree root) 
{
    stack<binTree> st1, st2;
    st1.push(root);

    while(!st1.empty() or !st2.empty()) 
    {     
        while(!st1.empty()) 
        {   
            binTree parent = st1.top();
            st1.pop();

            cout << parent -> value << " ";

            if(parent -> right != NULL) 
            {
                st2.push(parent -> right);
            }

            if(parent -> left != NULL) 
            {
                st2.push(parent -> left);
            }          
        }

        while(!st2.empty()) 
        {   
            binTree parent = st2.top();
            st2.pop();

            cout << parent -> value << " ";

            if(parent -> left != NULL) 
            {
                st1.push(parent -> left);
            }

            if(parent -> right != NULL) 
            {
                st1.push(parent -> right);
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
        ll par, child;
        char c;

        cin >> n;
        
        cin >> par >> child >> c;
        binTree root = createNode(par);
        buildTree(root, c, par, child);
        
        FOR(i,2,n,1) 
        {
            cin >> par >> child >> c;
            buildTree(root, c, par, child);
        }

        spiralOrder(root);

        cout << '\n';
        
    }
    
    return 0;
}