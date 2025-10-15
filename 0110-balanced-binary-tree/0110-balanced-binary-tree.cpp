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
private:
    pair<bool, int> dfs(TreeNode* node){
        if (!node)
            return {true, 0};

        auto [leftBalanced, leftHeight] = dfs(node->left);
        auto [rightBalanced, rightHeight] = dfs(node->right);

        bool isBalanced = leftBalanced && rightBalanced && abs(leftHeight - rightHeight) <= 1;

        return {isBalanced, 1+max(leftHeight, rightHeight)};
    }
public:
    bool isBalanced(TreeNode* root) {    
        return dfs(root).first;
    }
};