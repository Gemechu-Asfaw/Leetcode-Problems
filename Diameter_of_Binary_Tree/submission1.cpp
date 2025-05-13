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
    pair<int, int> solve(TreeNode* root){
        if (!root){
            return {0, 0};
        } 

        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        return {max(max(left.first, right.first), left.second+right.second+1), max(left.second, right.second)+1};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = solve(root).first;
        return max(0, ans-1);
    }
};