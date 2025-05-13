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
    bool solve(TreeNode* root, vector<int> &value, int level){

        if (root == NULL){
            return true;
        } else if (!(level % 2 ^ root->val % 2)){
            return false;
        } else if (value.size() <= level){
            value.push_back(root->val);
            bool left = solve(root->left, value, level+1);
            bool right = solve(root->right, value, level+1);
            return left && right;
        } else if ( (level % 2 == 0 && root->val > value[level])  ||  (level % 2 != 0 && root->val < value[level])) {
            value[level] = root->val;
            bool left = solve(root->left, value, level+1);
            bool right = solve(root->right, value, level+1);
            return left && right;
        } else{
            return false;
        }
    }

    bool isEvenOddTree(TreeNode* root) {
        vector<int> value;
        return solve(root, value, 0);
    }
};