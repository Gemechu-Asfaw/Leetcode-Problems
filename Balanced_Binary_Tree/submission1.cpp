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
    pair<bool, int> solve(TreeNode* root){
        if (!root){
            return {true, 0};
        } else {
            pair<bool, int> left = solve(root->left);
            pair<bool, int> right = solve(root->right);
            if (left.first && right.first && abs(left.second-right.second)<=1){
                return {true, 1+max(left.second, right.second)};
            } else {
                return {false, 1+max(left.second, right.second)};
            }
        }
    }

    bool isBalanced(TreeNode* root) {
        return solve(root).first;
    }
};