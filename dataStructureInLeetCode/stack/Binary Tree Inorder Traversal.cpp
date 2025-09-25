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
/*
从根节点开始，从上到下，从左到右，入栈，然后如果到某个节点没有子节点就出栈，然后这个节点的父节点也就可以出栈，当然，这个节点的父节点如果有右子节点那就继续入栈，历遍这个操作
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; // 结果
        stack<TreeNode*> stk; // 存待处理节点
        TreeNode* curr = root; // 当前节点
        
        while (curr || !stk.empty()) {
            while (curr) { // 沿左子树入栈
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top(); // 左子树到底，处理根
            stk.pop();
            res.push_back(curr->val);
            curr = curr->right; // 转右子树
        }
        return res;
    }
};
