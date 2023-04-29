//https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathDown(TreeNode* root,int &maxi)
    {
        
        if(root==NULL)
        return 0;
        
        int leftSum=max(0,maxPathDown(root->left,maxi));
        int rightSum=max(0,maxPathDown(root->right,maxi));
        maxi=max(root->val+leftSum+rightSum,maxi);
        return root->val+max(leftSum,rightSum);
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathDown(root,maxi);
        return maxi;
    }
};