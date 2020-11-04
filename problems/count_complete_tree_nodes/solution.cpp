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
    int binarySearch(TreeNode* root) {
        if (root == NULL) return 0;
        
        TreeNode* temp = root->left;
        int leftLevel = 1;
        
        while (temp != NULL) {
            leftLevel++;
            temp = temp->left;
        }
        
        temp = root->right;
        int rightLevel = 1;
        
        while (temp != NULL) {
            rightLevel++;
            temp = temp->right;
        }
        
        // Perfect Binary Tree
        if (leftLevel == rightLevel) {
            return (1 << leftLevel) - 1;
        }
        
        return 1 + binarySearch(root->left) + binarySearch(root->right);
    }
    
    void dfs(TreeNode* root, int& count) {
        if (root == NULL) return;
        
        count++;
        dfs(root->left, count);
        dfs(root->right, count);
    }
    
    int countNodes(TreeNode* root) {
        // Brute force approach
        // int count = 0;
        // dfs(root, count);
        // return count;
        
        //optimized approach
        return binarySearch(root);
    }
};