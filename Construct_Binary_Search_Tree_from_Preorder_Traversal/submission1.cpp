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
    int findInorderPosition(vector<int> &inorder, int element, int i, int j){

        int s = i, e = j, mid;

        while (s<=e){
            mid = s + (e-s)/2;
            if (inorder[mid] == element) break;
            else if (inorder[mid] > element) e = mid-1;
            else s = mid + 1;
        }

        return mid-i;
    }

    TreeNode* solve(vector<int> &inorder, vector<int> &preorder, int inorderLeft, int inorderRight, int preorderLeft, int preorderRight){

        if (inorderLeft > inorderRight) return NULL;
        
        int element = preorder[preorderLeft], position = findInorderPosition(inorder, element, inorderLeft, inorderRight);
        TreeNode* root = new TreeNode(element);
        root->left = solve(inorder, preorder, inorderLeft, inorderLeft+position-1, preorderLeft+1, preorderLeft+position);
        root->right = solve(inorder, preorder, inorderLeft+position+1, inorderRight, preorderLeft+position+1, preorderRight);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());

        return solve(inorder, preorder, 0, inorder.size()-1, 0, inorder.size()-1);
    }
};