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

bool levelOrder(binTree root) 
{
    bool kt = 0;
    queue<binTree> q;
    q.push(root);

    while(!q.empty()) 
    {
        if(kt) return 0;

        vector<binTree> v;
        while(!q.empty()) 
        {
            v.pb(q.front());
            q.pop();
        }

        for(binTree parent : v) 
        {
            if(parent -> left == NULL && parent -> right == NULL)  kt = 1;        

            if(parent -> left != NULL) 
            {
                q.push(parent -> left);
            }

            if(parent -> right != NULL) 
            {
                q.push(parent -> right);
            }
        }     
    }

    return 1;
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

        cout << levelOrder(root) << '\n';;
        
    }
    
    return 0;
}