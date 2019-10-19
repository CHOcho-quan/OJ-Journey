#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *r;
    r = new ListNode(0);
    ListNode *tmp1 = l1, *tmp2 = l2, *result = r;
    
    int jw = 0, val;
    
    while (tmp1 != NULL && tmp2 != NULL)
    {
        val = tmp1->val + tmp2->val + jw;
        if (val >= 10)
        {
            val = val % 10;
            jw = 1;
        }
        else jw = 0;
        
        r->next = new ListNode(val);
        r = r->next;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    
    if (tmp1 == NULL && tmp2 != NULL) {
        while (tmp2 != NULL) {
            val = tmp2->val + jw;
            if (val >= 10) {
                val = val % 10;
                jw = 1;
            } else jw = 0;
            
            r->next = new ListNode(val);
            r = r->next;
            tmp2 = tmp2->next;
        }
    }
    
    if (tmp1 != NULL && tmp2 == NULL)
    {
        while (tmp1 != NULL)
        {
            val = tmp1->val + jw;
            if (val >= 10) {
                val = val % 10;
                jw = 1;
            } else jw = 0;
            
            r->next = new ListNode(val);
            r = r->next;
            tmp1 = tmp1->next;
        }
    }
    
    if (jw == 0) return result->next;
    else
    {
        r->val = r->val % 10;
        r->next = new ListNode(1);
        return result->next;
    }
}

int main() {
    ListNode *s1, *s2, *r;
    s1 = new ListNode(2);
    //s1->next = new ListNode(4);
    //s1->next->next = new ListNode(3);
    
    s2 = new ListNode(5);
    //s2->next = new ListNode(6);
    //s2->next->next = new ListNode(4);
    
    r = addTwoNumbers(s1, s2);
    cout << r->val;// << r->next->val << r->next->next->val;
}
