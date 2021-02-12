/*
the intersection in two linked list
*/

#include <iostream>
#include <set>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};
// set
class Solution1{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        set<ListNode *> list_set;
        while (headA){
            list_set.insert(headA);
            headA = headA->next;
        }
        while (headB){
            if (list_set.find(headB) != list_set.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
};
//
int get_list_length(ListNode *head){
    int len = 0;
    while (head){
        len++;
        head = head->next;
    }
    return len;
}
ListNode *forward_long_list(int long_len, int short_len, ListNode *head){
    int delta = long_len - short_len;
    while (head && delta){
        cout<<delta<<endl;
        head = head->next;
        delta--;
    }
    return head;
}

class Solution2{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        int list_A_len = get_list_length(headA);
        int list_B_len = get_list_length(headB);
        if (list_A_len > list_B_len){
            headA = forward_long_list(list_A_len, list_B_len, headA);
        }
        else{
            headB = forward_long_list(list_B_len, list_A_len, headB);
        }
        while (headA && headB){
            if (headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

int main(){
    ListNode a1(1);
    ListNode a2(2);
    ListNode b1(3);
    ListNode b2(4);
    ListNode b3(5);
    ListNode c1(6);
    ListNode c2(7);
    ListNode c3(8);
    a1.next = &a2;
    a2.next = &c1;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    Solution2 solve;
    ListNode *result = solve.getIntersectionNode(&a1, &b1);
    cout<<result->val<<endl;
    return 0;
}
