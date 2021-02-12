/*
binary tree and graph
neighbor ancestor by tree
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        vector<TreeNode *> path;
        vector<TreeNode *> node_p_path;
        vector<TreeNode *> node_q_path;
        int finish = 0;
        preorder(root, p, path, node_p_path, finish);
        path.clear();
        finish = 0;
        preorder(root, q, path, node_q_path, finish);
        int path_len = 0;
        if (node_p_path.size() < node_q_path.size()){
            path_len = node_p_path.size();
        }
        else{
            path_len = node_q_path.size();
        }
        TreeNode *result = 0;
        for (int i = 0; i < path_len; i++){
            if (node_p_path[i] == node_q_path[i]){
                result = node_p_path[i];
            }
        }
        return result;
    }
private:
    void preorder(TreeNode* node, TreeNode* search, vector<TreeNode *> &path, vector<TreeNode *> &result, int &finish){
        if (!node || finish){
            return;
        }
        path.push_back(node);
        if (node == search){
            finish = 1;
            result = path;
        }
        preorder(node->left, search, path, result, finish);
        preorder(node->right, search, path, result, finish);
        path.pop_back();
    }
};

int main(){
    TreeNode a(3);
    TreeNode b(5);
    TreeNode c(1);
    TreeNode d(6);
    TreeNode e(2);
    TreeNode f(0);
    TreeNode x(8);
    TreeNode y(7);
    TreeNode z(4);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &x;
    e.left = &y;
    e.right = &z;
    Solution solve;
    TreeNode* result = solve.lowestCommonAncestor(&a, &b, &f);
    cout<<"lowestCommonAncestor = "<<result->val<<endl;
    result = solve.lowestCommonAncestor(&a, &d, &z);
    cout<<"lowestCommonAncestor = "<<result->val<<endl;
    result = solve.lowestCommonAncestor(&a, &b, &y);
    cout<<"lowestCommonAncestor = "<<result->val<<endl;
    return 0;
}
