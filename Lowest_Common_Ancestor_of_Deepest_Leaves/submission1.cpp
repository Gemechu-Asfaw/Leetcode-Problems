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
    pair<int, TreeNode*> solve(TreeNode* root, int n, set<TreeNode*> &deepestLevelNodes){
        if (root){
            if (deepestLevelNodes.find(root) != deepestLevelNodes.end()){
                return {1, root};
            } else {
                pair<int, TreeNode*> left = solve(root->left, n, deepestLevelNodes);
                pair<int, TreeNode*> right = solve(root->right, n, deepestLevelNodes);

                if (left.first == n){
                    return {n, left.second};
                } else if (right.first == n){
                    return {n, right.second};
                } else if (left.first + right.first == n){
                    return {n, root};
                } else {
                    return {left.first + right.first, root};
                }
            }
        } else {
            return {0, NULL};
        }
    }

    int getHeight(TreeNode* root){
        if (!root){
            return 0;
        } else {
            return 1 + max(getHeight(root->left), getHeight(root->right));
        }
    }

    void getDeepestLevelNodes(TreeNode* root, set<TreeNode*> &nodes, int maxHeight, int currentHeight){
        if (root){
            if (currentHeight == maxHeight){
                nodes.insert(root);
            } else {
                getDeepestLevelNodes(root->left, nodes, maxHeight, currentHeight+1);
                getDeepestLevelNodes(root->right, nodes, maxHeight, currentHeight+1);
            }
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = getHeight(root);
        set<TreeNode*> deepestLevelNodes;
        getDeepestLevelNodes(root, deepestLevelNodes, height, 1);
        return solve(root, deepestLevelNodes.size(), deepestLevelNodes).second;
    }
};