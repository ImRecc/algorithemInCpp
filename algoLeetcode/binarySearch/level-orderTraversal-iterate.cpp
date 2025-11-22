/*人话就是把preOder的栈换成先进先出的队列
这样就能实现一层一层了
然后用一个小循环for (int i = 0; i < levelSize; ++i)
来实现处理当前层的数个节点
*/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);                     // 根节点入队
        
        while (!q.empty()) {              // 直到队列空就结束
            int levelSize = q.size();     // 当前这一层的节点数
            vector<int> currentLevel;     // 存放当前层的所有值
            
            // 一次性把当前层所有节点处理完
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();   // 出列
                q.pop();
                
                currentLevel.push_back(node->val);  // 访问当前节点
                
                // 访问该节点的左右子节点，访问到就入队
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(currentLevel);   // 当前层结束，加入结果
        }
        
        return result;
    }
};
