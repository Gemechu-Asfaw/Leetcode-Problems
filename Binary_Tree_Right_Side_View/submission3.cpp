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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int, int> positionToValue;
        queue<pair<TreeNode*, int>> q;

        if (root){
            q.push({root, 0});
        }
        
        while (!q.empty()){
            pair<TreeNode*, int> front = q.front();
            TreeNode *node = front.first;
            int position = front.second;
            q.pop();

            positionToValue[position] = node->val;

            if (node->left){
                q.push({node->left, position+1});
            }

            if (node->right){
                q.push({node->right, position+1});
            }
        }

        for (auto x : positionToValue){
            ans.push_back(x.second);
        }

        return ans;
    }
};