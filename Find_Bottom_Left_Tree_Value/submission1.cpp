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
    void solve(TreeNode* root, int level, pair<int,int> &ans){

        if (root==NULL){
            return;
        }

        solve(root->left, level+1, ans);
        if (level > ans.first){
            ans.first = level;
            ans.second = root->val;
        }
        solve(root->right, level+1, ans);
    }

    int findBottomLeftValue(TreeNode* root) {
        int level = 0;
        pair<int,int> ans = make_pair(0, root->val);
        solve(root, level, ans);
        return ans.second;
    }
};