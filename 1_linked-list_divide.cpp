/*
divide list, large int x and small int x.
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
    ListNode* partition(ListNode* head, int x){
        ListNode large(0);
        ListNode small(0);
        ListNode *large_ptr = &large;
        ListNode *small_ptr = &small;
        while (head){
            if (head->val < x){
                small_ptr->next = head;
                small_ptr = head;
            }
            else{
                large_ptr->next = head;
                large_ptr = head;
            }
            head = head->next;
        }
        small_ptr->next = large.next;
        large_ptr->next = NULL;
        return small.next;
    }
};

int main(){
    ListNode a(1);
    ListNode b(4);
    ListNode c(3);
    ListNode d(2);
    ListNode e(5);
    ListNode f(2);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    Solution solve;
    ListNode *result = solve.partition(&a, 3);
    while(result){
        cout<<result->val<<endl;
        result = result->next;
    }
    return 0;
}
