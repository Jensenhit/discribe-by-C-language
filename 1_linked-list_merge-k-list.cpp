/*
merge k list:
plan 1: merge one by one
plan 2: sorted and connect
plan 3: divide and conquer
*/

#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

bool cmp(const ListNode *a, const ListNode *b){
    return a->val < b->val;
}

//class Solution2{  //sort and connect
//public:
//    ListNode* mergeKlists(vector<ListNode *>& lists){
//        vector<ListNode *> node_vec;
//        for (int i = 0; i < list.size(); i++){
//            ListNode *head = lists[i];
//            while (head){
//                node_vec.push_back(head);
//                head = head->next;
//            }
//        }
//        if (node_vec.size() == 0){
//            return NULL;
//        }
//        sort(node_vec.begin(), node_vec.end(), cmp);
//        for (int i = 1; i < node_vec.size(); i++){
//            node_vec[i-1]->next = node_vec[i];
//        }
//        node_vec[node_vec.size()-1]->next = NULL;
//        return node_vec[0];
//    }
//};

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode *>& lists){
    if (lists.size() == 0){
        return NULL;
    }
    if (lists.size() == 1){
        return lists[0];
    }
    if (lists.size() == 2){
        return mergeTwoLists(lists[0], lists[1]);
    }
    int mid = lists.size()/2;
    vector<ListNode *> sub1_lists;
    vector<ListNode *> sub2_lists;
    for (int i = 0; i < mid; i++){
        sub1_lists.push_back(lists[i]);
    }
    for (int i = mid; i < lists.size(); i++){
        sub2_lists.push_back(lists[i]);
    }
    ListNode *L1 = mergeKLists(sub1_lists);
    ListNode *L2 = mergeKLists(sub2_lists);
    return mergeTwoLists(L1, L2);
}
private:
    ListNode* mergeTwoLists(ListNode* L1, ListNode* L2){
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
    ListNode a(1);
    ListNode b(4);
    ListNode c(6);
    ListNode d(0);
    ListNode e(5);
    ListNode f(7);
    ListNode g(2);
    ListNode h(3);
    a.next = &b;
    b.next = &c;
    d.next = &e;
    e.next = &f;
    g.next = &h;
    Solution solve;
    vector<ListNode *> lists;
    lists.push_back(&a);
    lists.push_back(&d);
    lists.push_back(&g);
    ListNode *head = solve.mergeKLists(lists);
    while (head){
        cout<<head->val<<endl;
        head = head->next;
    }
    return 0;
}
