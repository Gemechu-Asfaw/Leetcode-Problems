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
private:
    void solve(TreeNode *root, int position, map<int, int> &positionToValue){
        if (root){
            solve(root->left, position+1, positionToValue);
            positionToValue[position] = root->val;
            solve(root->right, position+1,positionToValue);
        }
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int, int> positionToValue;

        solve(root, 0, positionToValue);

        for (auto x : positionToValue){
            ans.push_back(x.second);
        }

        return ans;
    }
};