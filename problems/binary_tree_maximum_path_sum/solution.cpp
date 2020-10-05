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
#include<algorithm>
#include<climits>
class Solution {
public:
    int maxSum(TreeNode* root) {
        if (root == NULL) return 0;
        
        int leftSum = maxSum(root->left);
        int rightSum = maxSum(root->right);
        
        // If sum of subtree is negative, there is no point considering it.
        if (leftSum < 0) leftSum = 0;
        if (rightSum < 0) rightSum = 0;
        
        //Get total of all nodes including current node.
        int subTreeTotal = root->val + leftSum + rightSum;        
        m_max = std::max(m_max, subTreeTotal);
        
        //Since the parent of current node will include this node
        //in the path starting at parent, the return value
        //should be current.val + max(left, right)
        //max is for optimising to max value;
        return root->val + std::max(leftSum, rightSum);
        
        
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return m_max;
    }
    
private:
    int m_max = INT_MIN;
};