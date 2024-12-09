#include <algorithm>
#include <queue>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> levelOrderBottom4(TreeNode *root) {
        std::queue<TreeNode *> q;
        std::vector<std::vector<int>> ans;
        if (root == NULL) return ans;
        q.push(root);
        while (!q.empty()) {
            std::vector<int> ans1;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                ans1.push_back(node->val);
            }
            ans.push_back(ans1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    std::vector<std::vector<int>> levelOrderBottom5(TreeNode *root) {
        std::queue<TreeNode *> q;
        std::vector<std::vector<int>> ans;
        if (root == NULL) return ans;
        q.push(root);
        while (!q.empty()) {
            std::vector<int> ans1;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                ans1.push_back(node->val);
            }
            ans.push_back(ans1);
        }
        return ans;
    }

    std::vector<std::vector<int>> levelOrderBottom6(TreeNode *root) {
        std::queue<TreeNode *> q;
        std::vector<std::vector<int>> ans;
        if (root == NULL) return ans;
        q.push(root);
        while (!q.empty()) {
            std::vector<int> ans1;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                ans1.push_back(node->val);
            }
            ans.push_back(ans1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        std::queue<TreeNode *> q;
        std::vector<std::vector<int>> ans;
        if (root == NULL) return ans;
        q.push(root);
        while (!q.empty()) {
            std::vector<int> ans1;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                ans1.push_back(node->val);
            }
            ans.push_back(ans1);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};