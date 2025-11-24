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
/*正常来说就是先序遍历嘛，用个栈从根到左子节点一路下去
到头了比对，不对就回退访问右边*/
/*但是这题传入了目标值，那如果存在：
叶子节点，且去掉到这个叶子节点的路径的值剩下的和叶子节点的值相同
那就成立
如果用递归来多路线的执行同样的操作那么很快就能找到结果了
*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        // 走到叶子节点了
        if (!root->left && !root->right) {
            return root->val == targetSum;
        }
        
        // 递归检查左右子树（自动减去当前节点值）
        //当前值作为了一个路径节点，需要被减去
        //以便访问到叶子节点时候比对剩下的是否和叶子节点值一致
        int remain = targetSum - root->val;
        return hasPathSum(root->left, remain) || 
               hasPathSum(root->right, remain);
    }
};
