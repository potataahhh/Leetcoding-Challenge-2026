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

    long SUM=0;
    long maxProd=0;

// Function to get the total sum of whole Tree  

    int totalSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftSum = totalSum(root->left);
        int rightSum = totalSum(root->right);
        int sum = root->val+leftSum+rightSum;

        return sum;
    }

    // Function to get the sum/ remaining sum and maxproduct of the subtrees

    int func(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftSubtree = func(root->left);
        int rightSubtree = func(root->right);
        long sumSubtree = root->val+leftSubtree+rightSubtree;           // sum of subtree

        long remSum = SUM-sumSubtree;                                   // remaining sum of subtree
        maxProd=max(maxProd,sumSubtree*remSum);                         // Max product of subtrees

        return sumSubtree;
    }

    int maxProduct(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        maxProd=0;
        SUM=totalSum(root);
        func(root);

        return maxProd%(1000000007);
    }
};
