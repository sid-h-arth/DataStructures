#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
    int data;
    vector<TreeNode*> children;
};

TreeNode *GetNode(int data);
void addChild(TreeNode *node,int data);
void print(TreeNode *root);

TreeNode *GetNode(int data)
{
    TreeNode *newNode=new TreeNode();
    newNode->data=data;
    return newNode;
}

void addChild(TreeNode *node,int data)
{
    TreeNode *newNode=GetNode(data);
    newNode->children.push_back(newNode);
}

void print(TreeNode *root)
{
    cout<<root;
    cout<<root->children[0]->data;
    cout<<root->children[1]->data;
    cout<<root->children[2]->data;
    cout<<root->children[0]->children[0]->data;
    cout<<root->children[1]->children[0]->data;
    cout<<root->children[2]->children[0]->data;
}

int main()
{
    TreeNode *root;
    root=GetNode(3);
    addChild(root,2);
    addChild(root,4);
    addChild(root,6);
    addChild(root->children[0],8);
    addChild(root->children[1],9);
    addChild(root->children[2],10);
    print(root);
    
    return 0;
}

