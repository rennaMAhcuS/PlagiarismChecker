#include <algorithm>
#include <queue>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> myFunc23(TreeNode *root) {
        std::vector<std::vector<int>> NoAns;
        if (root == nullptr) return NoAns;

        std::queue<TreeNode *> curr;
        std::queue<TreeNode *> next;

        curr.push(root);
        std::vector<int> level;
        while (!curr.empty()) {
            TreeNode *node = curr.front();
            curr.pop();
            level.push_back(node->val);
            if (node->left != nullptr) next.push(node->left);
            if (node->right != nullptr) next.push(node->right);

            if (curr.empty()) {
                NoAns.push_back(level);
                level = std::vector<int>();
                curr = next;
                next = std::queue<TreeNode *>();
            }
        }
        return NoAns;
    }

    std::vector<std::vector<int>> HisFunc45(TreeNode *root) {
        std::vector<std::vector<int>> HeIsGreat456;
        if (root == nullptr) return HeIsGreat456;

        std::queue<TreeNode *> curr;
        std::queue<TreeNode *> next;

        curr.push(root);
        std::vector<int> level;
        while (!curr.empty()) {
            TreeNode *node = curr.front();
            curr.pop();
            level.push_back(node->val);
            if (node->left != nullptr) next.push(node->left);
            if (node->right != nullptr) next.push(node->right);

            if (curr.empty()) {
                HeIsGreat456.push_back(level);
                level = std::vector<int>();
                curr = next;
                next = std::queue<TreeNode *>();
            }
        }
        return HeIsGreat456;
    }

    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        std::vector<std::vector<int>> ans;
        if (root == nullptr) return ans;

        std::queue<TreeNode *> curr;
        std::queue<TreeNode *> next;

        curr.push(root);
        std::vector<int> level;
        while (!curr.empty()) {
            TreeNode *node = curr.front();
            curr.pop();
            level.push_back(node->val);
            if (node->left != nullptr) next.push(node->left);
            if (node->right != nullptr) next.push(node->right);

            if (curr.empty()) {
                ans.push_back(level);
                level = std::vector<int>();
                curr = next;
                next = std::queue<TreeNode *>();
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};