/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

int helper(TreeNode* node, int depth) {
    if (!node) return depth;           // 空节点，返回当前深度
    int left = helper(node->left, depth + 1);
    int right = helper(node->right, depth + 1);
    return max(left, right);           // 取左右子树最大深度
}

class Solution{
    public:
    int maxDepth(TreeNode* root) {
    return helper(root, 0);
    }
    
};

/*
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int left = maxDepth(root->left);   // 函数调用 → 得到一个 int
    int right = maxDepth(root->right); // 函数调用 → 得到一个 int
    return max(left, right) + 1;        //函数调用本身就是一个表达式，它的值就是返回值
    //随着递归总会触及到return 0，所以初始值是0，然后随着递归回退退到正确的值
}
*/


