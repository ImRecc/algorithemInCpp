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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        
        while (cur || !stk.empty()) {
            
            // 根节点入栈，访问左节点，有则左节点设为新的根节点入栈，继续访问
            //           → “入栈一路左”的过程，同时前序就在这里访问根！
            while (cur) {
                result.push_back(cur->val);   // 前序：先访问根节点
                stk.push(cur);                // 入栈，为以后回溯做准备
                cur = cur->left;              // 一直往左走
            }
            
            // 没有左子树了 弹出栈顶，实现回溯
            cur = stk.top();
            stk.pop();
            
            // 回溯后判定有没有右节点，有就继续设为新根节点入栈继续找
            //           没有就继续弹栈回溯
            cur = cur->right;   // 如果没有右孩子，cur 变为 nullptr
                                // 下次外层 while 会继续弹栈，直到栈空或找到有右孩子的节点
        }
        
        // 栈空则判定为遍历结束
        return result;
    }
};
