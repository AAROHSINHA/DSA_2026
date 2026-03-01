#include <iostream>
#include <vector>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(!root) return answer;
        TreeNode* currPtr = root;
        while(currPtr){
            if(currPtr->left == nullptr){
                answer.push_back(currPtr->val);
                currPtr = currPtr->right;
            }else{
                TreeNode* predPtr = currPtr->left;
                while(predPtr->right && predPtr->right!=currPtr){
                    predPtr = predPtr->right;
                }

                if(predPtr->right == currPtr){
                    predPtr->right = nullptr;
                    answer.push_back(currPtr->val);
                    currPtr = currPtr->right;
                }else{
                    predPtr->right = currPtr;
                    currPtr = currPtr->left;
                }
            }
        }
        return answer;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};