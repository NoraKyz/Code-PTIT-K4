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

string levelOrder(binTree root) 
{
    bool kt1 = 0, kt2 = 0;
    queue<binTree> q;
    q.push(root);

    while(!q.empty()) 
    {
        if(kt1) return "No";

        vector<binTree> v;
        while(!q.empty()) 
        {
            v.pb(q.front());
            q.pop();
        }

        for(binTree parent : v) 
        {
            kt2 = 0;
             
            if(parent -> left == NULL && parent -> right == NULL)  kt1 = 1;        

            if(parent -> left != NULL) 
            {
                kt2 = 1;
                q.push(parent -> left);
            }

            if(parent -> right != NULL) 
            {
                kt2 = 1;
                q.push(parent -> right);
            }

            if((parent -> left == NULL || parent -> right == NULL) && kt2) return "No";
        }     
    }

    return "Yes";
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