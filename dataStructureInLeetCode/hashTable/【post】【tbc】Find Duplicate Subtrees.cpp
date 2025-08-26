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
//LeetCode 用**层序遍历（level-order, BFS）**表示输入树，从上到下、左到右，每层依次列出节点，空节点用 null 表示。
/*按层序：第1层：1（根）
第2层：2, 3（左、右孩子）
第3层：4, null, 2, 4（2 的左/右，3 的左/右）
第4层：null, null, 4, null（2 的左孩子的左/右，3 的左孩子的左/右）
合并：[1,2,3,4,null,2,4,null,null,4]。
*/
//序遍历（root->left->right）构造输入，但 LeetCode 标准是层序遍历。
//前序遍历顺序：1, 2, 4, 3, 2, 4, 4（不含 null，与输入格式不符）。
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(vector<int>& nums) { // 假设输入数组，null 为 INT_MIN
        unordered_map<string, pair<int, TreeNode*>> seen; // 序列 -> {次数, 节点}
        vector<TreeNode*> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == INT_MIN) continue; // 跳过 null
            string serial = serialize(nums, i);
            if (seen[serial].first++ == 1) {
                result.push_back(new TreeNode(nums[i])); // 构造节点返回
            }
        }
        return result;
    }
    
private:
    string serialize(vector<int>& nums, int idx) {
        if (idx >= nums.size() || nums[idx] == INT_MIN) return "#"; // 空节点
        // 前序序列化：root,left,right
        string serial = to_string(nums[idx]) + "," +
                       serialize(nums, 2 * idx + 1) + "," +
                       serialize(nums, 2 * idx + 2);
        return serial;
    }
};
