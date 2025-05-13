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
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> ans;

        if (root){
            q.push({root, 0});
        }

        while (!q.empty()){
            pair<TreeNode*, int> front = q.front();
            TreeNode* node = front.first;
            int level = front.second;
            q.pop();

            if (ans.size() == level){
                vector<int> temp = {node->val};
                ans.push_back(temp);
            } else {
                ans[level].push_back(node->val);
            }

            if (node->left) q.push({node->left, level+1});
            if (node->right) q.push({node->right, level+1});
        }

        return ans;
    }
};