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
    pair<TreeNode*,TreeNode*> getInorderPredecessor(TreeNode* root){

        TreeNode* parent = root, *child = root->left;
        while (child->right){
            parent = child;
            child = child->right;
        }

        return {parent, child};

    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == NULL) return NULL;

        if (root->val == key){
            
            // zero child case
            if (root->left == NULL && root->right==NULL) return NULL;

            // single child case
            if (root->right == NULL && root->left != NULL) return root->left;
            else if (root->left == NULL && root->right != NULL) return root->right;

            // two child case
            pair<TreeNode*, TreeNode*> pair = getInorderPredecessor(root);
            TreeNode* parent = pair.first;
            TreeNode* child = pair.second;

            root->val = child->val;
            if (parent == root) parent->left = deleteNode(child, child->val);
            else parent->right = deleteNode(child, child->val);

            // root->left = deleteNode(predecessor, root->left->val);
            
        } else if (root->val > key){
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};