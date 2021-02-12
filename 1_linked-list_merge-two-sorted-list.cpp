/*
merge two sorted list
*/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode* mergeTwoSortList(ListNode* L1, ListNode* L2){
        ListNode result(0);
        ListNode *res_ptr = &result;
        while(L1 && L2){
            if (L1->val < L2->val){
                res_ptr->next = L1;
                L1 = L1->next;
            }
            else{
                res_ptr->next = L2;
                L2 = L2->next;
            }
            res_ptr = res_ptr->next;
        }
        if (L1){
            res_ptr->next = L1;
        }
        if (L2){
            res_ptr->next = L2;
        }
        return result.next;
    }
};

int main(){
    ListNode a1(1);
    ListNode b1(0);
    ListNode a2(4);
    ListNode b2(5);
    ListNode a3(6);
    ListNode b3(7);
    a1.next = &a2;
    a2.next = &a3;
    b1.next = &b2;
    b2.next = &b3;
    Solution solve;
    ListNode *result = solve.mergeTwoSortList(&a1, &b1);
    while (result){
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}
