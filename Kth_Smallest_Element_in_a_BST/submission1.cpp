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
    void solve(TreeNode* root, vector<int> &nodes){
        if (root){
            solve(root->left, nodes);
            nodes.push_back(root->val);
            solve(root->right, nodes);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        solve(root, nodes);
        return nodes[k-1];
    }
};