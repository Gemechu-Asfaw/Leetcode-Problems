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
    pair<int,int> solve(TreeNode* root){

        if (root == NULL){
            return make_pair(0,0);
        } else if (root->left==NULL && root->right==NULL){
            return make_pair(0,1);
        }

        pair<int, int> leftSubTree = solve(root->left);
        pair<int, int> rightSubTree = solve(root->right);
        int diameter = max(max(leftSubTree.first, rightSubTree.first), leftSubTree.second + rightSubTree.second + 1);
        int height = max(leftSubTree.second, rightSubTree.second) + 1;
        return make_pair(diameter, height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root->left==NULL and root->right==NULL){
            return 0;
        } return solve(root).first-1;
    }
};