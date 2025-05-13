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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        int level = 0;

        if (root){
            q.push(root);
        }

        while (!q.empty()){
            vector<int> temp;
            vector<TreeNode*> nextNodes;

            while (!q.empty()){
                TreeNode* front = q.front();
                q.pop();
                temp.push_back(front->val);
                if (front->left) nextNodes.push_back(front->left);
                if (front->right) nextNodes.push_back(front->right);
            }

            if (level%2){
                reverse(temp.begin(), temp.end());
            }

            for (auto next : nextNodes){
                q.push(next);
            }

            ans.push_back(temp);
            level++;
        }

        return ans;
    }
};