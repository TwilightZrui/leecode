/*
 * @Author: TwilightZrui
 * @Date: 2023-05-22 11:09:34
 */
/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (71.29%)
 * Likes:    1072
 * Dislikes: 0
 * Total Accepted:    859.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 * 示例 4：
 *
 *
 * 输入：root = [1,2]
 * 输出：[1,2]
 *
 *
 * 示例 5：
 *
 *
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100
 *
 *
 *
 *
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
 *
 */

// @lc code=start
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
    // // 递归
    // void preOrder(TreeNode *root, vector<int> &ans) {
    //     if (root == nullptr)
    //         return;
    //     ans.emplace_back(root->val);
    //     preOrder(root->left, ans);
    //     preOrder(root->right, ans);
    // }
    // vector<int> preorderTraversal(TreeNode *root) {
    //     vector<int> ans;
    //     preOrder(root, ans);
    //     return ans;
    // }

    // 迭代
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto node = q.top();
            q.pop();
            ans.emplace_back(node->val);

            if (node->right != nullptr)
                q.push(node->right);
            if (node->left != nullptr)
                q.push(node->left);
        }
        return ans;
    }
};
// @lc code=end
