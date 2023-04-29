//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
        vector<vector<int>>res;

        if(root==NULL)
        return res;
          bool lefttoright=true;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            vector<int>row(size);
            for(int i=0;i<size;i++)
            {
          TreeNode* temp=q.front();
          q.pop();
            
          int index=lefttoright?i:size-1-i;
    
          row[index]=temp->val;

           if(temp->left!=NULL)
          q.push(temp->left); 
          if(temp->right!=NULL) 
          q.push(temp->right);
          
            }
            lefttoright=!lefttoright;
           res.push_back(row);
        
         
        }
       
      return res;
    }
};









































































































































































































































































































































































































































































































































































































































































































    