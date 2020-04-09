#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == n) return head;
    if (head == NULL) return head;
    ListNode *fake;
    fake = new ListNode(0);
    fake->next = head;
    ListNode *root = fake;
    ListNode * tmp1, *tmp2, *tmp3;

    int cnt1 = -1, cnt2 = -1;
    bool flag = false;
    while (root != NULL) {
        cnt1++;
        cnt2++;
        if (cnt2 == n) {
            tmp3->next = root->next;
            root->next = tmp2;
            tmp1->next = root;
            break;
        }
        if (cnt1 == m) {
            root = root->next;
            continue;
        }
        if (cnt1 == m-1) {
            tmp1 = root;
            tmp2 = root->next;
            tmp3 = root->next;
            root = root->next;
            flag = true;
            continue;
        }
        if (flag) {
            tmp1->next = root->next;
            root->next = tmp2;
            tmp2 = root;
            root = tmp1->next;
        }
        else root=root->next;
    }
    if (m == 1) return root;
    return head;
}