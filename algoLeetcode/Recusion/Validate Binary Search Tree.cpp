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
/*麻烦在于如果每一颗树都合规的情况下，左边的最底层右子节点要比根小，
右边的最底层左子节点要比根大啊
但如果用一个（对于左子树递归，把当前节点作为上限传入；右子树递归则作为下限传入）就可以完美避开了
定义嘛
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    
private:
    // 检查以 node 为根的子树是否是合法 BST，所有节点值必须在 (lower, upper) 开区间内
    bool dfs(TreeNode* node, long lower, long upper) 
    {
        if (node == nullptr) return true;
        //放心用，等到所有递归调用都返回 true才是总的true，这个return只是这一层递归的
        
        // 当前节点必须严格大于 lower 且严格小于 upper
        if (node->val <= lower || node->val >= upper) return false;
        
        // 左子树的所有值必须 < node->val，所以上界变成 node->val
        // 右子树的所有值必须 > node->val，所以下界变成 node->val
        return dfs(node->left,  lower, node->val) && 
               dfs(node->right, node->val, upper);
    }
};
