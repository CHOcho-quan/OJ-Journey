#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotate(ListNode *head, int k, int num)
{
    if (k==0) return head;

    ListNode *k_head = head;
    ListNode *tail = head;
    for (int i = 0;i < num;i++) {
        if (i < num-k-1) k_head = k_head->next;
        if (tail->next != NULL) tail = tail->next;
    }

    cout << k_head->val << endl;
    ListNode *result = k_head->next;
    // if (result==NULL)
    k_head->next = NULL;
    tail->next = head;

    return result;
}

ListNode* rotateRight(ListNode* head, int k) 
{
    if (head==NULL) return head;
    int num = 0;
    for (ListNode *t = head;t!=NULL;t=t->next) num+=1;

    k = k % num;
    // cout << 'k' << k << endl;
    ListNode *result;
    result = rotate(head, k, num);

    return result;
}
int main()
{
    ListNode *root;
    root = new ListNode(1);
    root->next = new ListNode(2);
    // root->next->next = new ListNode(3);
    // root->next->next->next = new ListNode(4);
    // root->next->next->next->next = new ListNode(5);

    ListNode *tmp = rotateRight(root, 1);
    for (ListNode *t = tmp;t!=NULL;t=t->next) cout << t->val << ' ';
}