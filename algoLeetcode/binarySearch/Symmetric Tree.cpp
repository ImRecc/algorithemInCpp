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
/*这是比层序历遍更好的方式，直接根据左右节点的“左子?=右子"&&“左右?=右左"来确定是否镜像
而由于入队的顺序和层序遍历不同，是直接根据二叉树的特性镜像入队的
所以直接弹出比对是可行的
*/
/*层序历遍的话就需要一个双指针，动态数组，重置双指针这样那样的，很麻烦*/
/*括号配对或者回文那样的栈处理方法又无法处理比如6677这样的例子*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);   // 一开始就把左右子树按“外侧→内侧”顺序入队
        
        while (!q.empty()) 
        {
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            // 两个都空，继续下一对
            if (!left && !right) continue;
            // 一个空一个不空，或值不相等 → 不对称
            if (!left || !right || left->val != right->val) return false;
            
            // 下一对，外侧先入，内侧后入
            q.push(left->left);
            q.push(right->right);   // 外侧一对
            q.push(left->right);
            q.push(right->left);    // 内侧一对
        }
        return true;
    }
};
