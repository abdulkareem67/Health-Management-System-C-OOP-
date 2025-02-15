#include <iostream>
using namespace std;
class TreeNode 
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) 
    {
        val = x;
        left = right = nullptr;
    }
};
// void printTree(TreeNode* root, int space = 0, int COUNT = 5) //Prints Tree Format
// {
//     if (root == nullptr) 
//     return;
//     space += COUNT;
//     printTree(root->right, space);
//     cout << endl;
//     for (int i = COUNT; i < space; i++) cout << " ";
//     cout << root->val << endl;
//     printTree(root->left, space);
// }
TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) // LCA Calculating Function
{
    if (!root || root == p || root == q) return root;
    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);
    if (left && right) return root; // Finds the given nodes, returns both if found under a same node else returns one
    return left ? left : right;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // // Print the tree in top-down format
    // cout << "Tree structure:" << endl;
    // printTree(root);

    TreeNode* p = root->left->left;
    TreeNode* q = root->left->right;

    TreeNode* lca = findLCA(root, p, q);
    cout << "\nLCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}
