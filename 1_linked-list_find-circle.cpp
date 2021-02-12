/*
1-->2-->3-->4-->5-->6-->7-->3
find circle intersection in linked list
*/

#include <iostream>
#include <set>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
public:
    ListNode *detectCycle(ListNode *head){
        set<ListNode *> node_set;
        while (head){
            if (node_set.find(head) != node_set.end()){
                return head;
            }
            node_set.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

int main(){
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &c;
    Solution solve;
    ListNode *node = solve.detectCycle(&a);
    if (node){
        cout<<node->val<<endl;
    }
    else{
        cout<<"NULL"<<endl;
    }
    return 0;
}



