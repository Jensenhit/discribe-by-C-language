/*
binary tree and graph
tree to linked list
plan 1: vector
plan 2: change pointer
*/

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

#include <vector>
class Solution1{  //vector store node
public:
    void flatten(TreeNode* root){
        vector<TreeNode *> node_vec;
        preorder(root, node_vec);
        for (int i = 0; i < node_vec.size(); i++){
            node_vec[i-1]->left = NULL;
            node_vec[i-1]->right = node_vec[i];
        }
    }
private:
    void preorder(TreeNode *node, vector<TreeNode *> &node_vec){
        if (!node){
            return;
        }
        node_vec.push_back(node);
        preorder(node->left, node_vec);
        preorder(node->right, node_vec);
    }
};

class Solution2{
public:
    void flatten(TreeNode *root){
        TreeNode *last = NULL;
        preorder(root, last);
    }
private:
    void preorder(TreeNode *node, TreeNode *&last){
        if (!node){
            return;
        }
        if (!node->left && !node->right){
            last = node;
            return;
        }
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        TreeNode *left_last = NULL;
        TreeNode *right_last = NULL;
        if (left){
            preorder(left, left_last);
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if (right){
            preorder(right, right_last);
            if (left_last){
                left_last->right = right;
            }
            last = right_last;
        }
    }
};

int main(){
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    Solution2 solve;
    solve.flatten(&a);
    TreeNode *head = &a;
    while(head){
        if (head->left){
            cout<<"ERROR!"<<endl;
        }
        cout<<"["<<head->val<<"]"<<endl;
        head = head->right;
    }
    cout<<endl;
    return 0;
}
