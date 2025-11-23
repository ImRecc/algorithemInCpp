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
//但是用vector的话其实更直观一点点
//双指针理解起来也更容易一些
class Solution {
public:
    bool isSymmetric(TreeNode* root) 
    {
        if (!root) return true;
        
        vector<TreeNode*> level;           // 动态数组！
        level.push_back(root->left);
        level.push_back(root->right);
        
        while (!level.empty()) 
        {
            int left = 0;
            int right = (int)level.size() - 1;
            //用这种方法来更新指针位置
            
            // 双指针同时从两端往中间走
            while (left < right) 
            {
                TreeNode* l = level[left];
                TreeNode* r = level[right];
                
                // 两边都空 → OK，继续
                if (!l && !r) 
                { 
                    left++; right--; 
                    continue; 
                }
                // 一空一非空 或 值不相等 → 不对称
                if (!l || !r || l->val != r->val) {
                    return false;
                }
                left++; right--;
            }
            
            // 准备下一层：把下一层所有孩子加入 vector
            vector<TreeNode*> nextLevel;
            for (TreeNode* node : level) 
            {
                if (node) 
                {                     // 只有非空节点才加孩子
                    nextLevel.push_back(node->left);
                    nextLevel.push_back(node->right);
                }
            }
            level = std::move(nextLevel);       // 换到下一层
            //不要 nextLevel 这个 vector 了，它里面的所有内存全部偷给 level
        }
        return true;
    }
};
/*
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
*/
