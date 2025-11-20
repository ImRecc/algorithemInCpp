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

    // 主函数
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }

private:

    // 核心递归函数：生成所有 [start, end] 能构成的 BST
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> result;

        // 空树情况
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        // 枚举所有可能的根 i
        for (int i = start; i <= end; i++) {
            // 所有左子树
            vector<TreeNode*> leftTrees = build(start, i - 1);

            // 所有右子树
            vector<TreeNode*> rightTrees = build(i + 1, end);

            // 左 × 右 所有组合
            for (TreeNode* L : leftTrees) {
                for (TreeNode* R : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = L;
                    root->right = R;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};
