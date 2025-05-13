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
    bool solve(TreeNode* root, long long minRange, long long maxRange){

        if (root == NULL) return true;

        bool current = ((long long)root->val >= minRange) && ((long long)root->val <= maxRange);
        bool left = solve(root->left, minRange, (long long)root->val-1);
        bool right = solve(root->right, (long long)root->val+1, maxRange);

        return current && left && right;

    }

    bool isValidBST(TreeNode* root) {
        long long minRange = INT_MIN, maxRange = INT_MAX;
        return solve(root, minRange, maxRange);
    }
};