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
    void solve(TreeNode* root, vector<int> &ans, int level){
        
        // Logic for maximum value at a level
        if (root==NULL){
            return;
        }
        else if (level > ans.size()){
            ans.push_back(root->val);
        }
        else if (root->val > ans[level-1]){
            ans[level-1] = root->val;
        }

        // Traversing left
        solve(root->left, ans, level+1);

        // Traversing right
        solve(root->right, ans, level+1);
    }

    vector<int> largestValues(TreeNode* root) {
        
        int level = 1;
        vector<int> ans;

        solve(root, ans, level);
        return ans;
    }
};