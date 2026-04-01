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
    void traversal(TreeNode* node, int k, int& cnt, int& ans) {
        if(node == NULL) return;

        traversal(node->left, k, cnt, ans);
        cnt++;
        if(cnt == k) ans = node->val;
        traversal(node->right, k, cnt, ans);
        
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = -1;
        traversal(root, k, count, ans);
        return ans;
    }
};
