/*
reverse linked list
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
    ListNode* reverseList(ListNode *head){
        ListNode *new_head = NULL;
        while (head){
            ListNode *next = head->next;
            head->next = new_head;
            new_head  = head;
            head = next;
        }
        return new_head;
    }
};

int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    Solution solve;
    ListNode *head = &a;
    cout<<"before reverse:"<<endl;
    while(head){
        cout<<head->val<<endl;
        head = head->next;
    }
    head = solve.reverseList(&a);
    cout<<"After reverse:"<<endl;
    while(head){
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}
