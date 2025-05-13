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
    pair<int, bool> solve(TreeNode* root, vector<int> &ans){

        if (!root) return {0, true};

        pair<int, bool> left = solve(root->left, ans);
        pair<int, bool> right = solve(root->right, ans);
        int sum = left.first + right.first + 1;
        bool validity = left.second & right.second & (left.first==right.first);

        if (validity) ans.push_back(sum);
        return {sum, validity};
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> ans;
        solve(root, ans);
        sort(ans.begin(), ans.end());
        return ans.size()>= k ? ans[ans.size()-k] : -1;
    }
};