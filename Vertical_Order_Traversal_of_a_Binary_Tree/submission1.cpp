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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mapping;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()){
            pair<TreeNode*, pair<int, int>> front = q.front();
            TreeNode* node = front.first;
            int verticalPos = front.second.first, horizontalPos = front.second.second;
            
            mapping[horizontalPos][verticalPos].push_back(node->val);
            q.pop();

            if (node->left){
                q.push({node->left, {verticalPos+1, horizontalPos-1}});
            }

            if (node->right){
                q.push({node->right, {verticalPos+1, horizontalPos+1}});
            }
        }

        for (auto x : mapping){
            vector<int> temp = {};
            for (auto y : x.second){
                vector<int> temp2 = {};
                for (auto element : y.second){
                    temp2.push_back(element);
                }
                sort(temp2.begin(), temp2.end());

                for (auto element : temp2){
                    temp.push_back(element);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};