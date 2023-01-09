class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        stack < TreeNode * > s;
        if (root != nullptr) {
            s.push(root);
            v.push_back(root->val);
        }
        while (!s.empty()) {
            TreeNode *curTop = s.top();
            if (curTop->left != nullptr) {
                v.push_back(curTop->left->val);
                s.push(curTop->left);
                curTop->left = nullptr;
            } else if (curTop->right != nullptr) {
                v.push_back(curTop->right->val);
                s.push(curTop->right);
                curTop->right = nullptr;
            } else s.pop();
        }
        return v;
    }
};