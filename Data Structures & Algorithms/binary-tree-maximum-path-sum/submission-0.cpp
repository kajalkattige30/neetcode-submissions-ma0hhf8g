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
    int maxSum;
    int solve(TreeNode* root) {
        if(root == NULL) return 0;

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        //case 1:
        int full_path = leftSum + rightSum + root->val;

        //case 2:
        int any_one_path = max(leftSum, rightSum) + root->val;

        //case 3:
        int only_root = root->val;

        maxSum = max({maxSum, full_path, any_one_path, only_root});

        return max(any_one_path, only_root);

    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};
