//
//  Leetcode143_重排链表.cpp
//  
//
//  Created by 铨 on 2020/3/29.
//

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head) {
    if (head == NULL) return ;
    vector<ListNode*> n;
    while (head != NULL) {
        n.push_back(head);
        head = head->next;
    }
    
    for (int i = 0;i < n.size() / 2 + 1;i++) {
        if (i == n.size() / 2) {
            n[i]->next = NULL;
            break;
        }
        n[i]->next = n[n.size()-i-1];
        n[n.size()-i-1]->next = n[i+1];
    }
    return ;
}

int main() {
    ListNode *r;
    r = new ListNode(1);
    r->next = new ListNode(2);
    r->next->next = new ListNode(3);
    r->next->next->next = new ListNode(4);
    reorderList(r);
    
    while (r!=NULL) {
        cout << r->val << endl;
        r = r->next;
    }
}
