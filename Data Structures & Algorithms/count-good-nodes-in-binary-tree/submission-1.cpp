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
    void traversal(TreeNode* node, int& count, int currentMax) {
        if(node == NULL) return;

        if(node->val >= currentMax) {
            count++;
            currentMax = node->val;
        } 

        traversal(node->left, count, currentMax);
        traversal(node->right, count, currentMax);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        int rootVal = root->val;
        traversal(root, count, rootVal);
        return count;
    }
};
