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
    int maxDepth(TreeNode* root) {
//         //Base case
//         if(root == NULL) return 0;
        
//         int leftHeight = maxDepth(root->left);
//         int rightHeight = maxDepth(root->right);
//         int height = max(leftHeight,rightHeight) + 1;
//         return height;
        
        
        // using level order traversal
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int cnt = 1;
        
        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();
            
            if(front == NULL){
                if(!q.empty()){
                    cnt ++;
                    q.push(NULL);
                }
             
            }
            else{
                //valid case
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
        
        }
        return cnt;
    }
};