#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

bool isBalanced(struct Node *root);

struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBalanced(root) << endl;
  }
  return 0;
}

int height(Node *node){
    if(node==NULL)return 0;
    return 1+max(height(node->left),height(node->right));
}
bool isBalanced(Node *root)
{
    int lh;
    int rh;
   
    if(root==NULL)return 1;
   
    lh=height(root->left);
    rh=height(root->right);
   
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))return 1;
    return 0;   
}
int max(int a,int b){
    return a>=b ?a:b;
}
