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
    bool findPath(TreeNode* root, int targetSum, int length){

        length = length + root->val;
        if (root->left==NULL && root->right==NULL){
            if (length==targetSum){
                return true;
            }
            return false;
        }

        bool leftAns=false, rightAns=false;
        if (root->left!=NULL){
            leftAns = findPath(root->left, targetSum, length);
        }
        if (root->right!=NULL){
            rightAns = findPath(root->right, targetSum, length);
        }

        return (leftAns || rightAns);

    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if (root==NULL){
            return false;
        }

        int length = 0;
        bool ans = findPath(root, targetSum, length);

        return ans;

    }
};