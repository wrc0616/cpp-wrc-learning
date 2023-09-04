//方法一 迭代
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* now=head ;
        ListNode* pre=nullptr ;
        ListNode* next ;
        while(now!=NULL ){
            next = now->next;
            now->next = pre;
            pre = now;
            now = next;

        }
        return pre;
    }
};

//方法二 递归法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
        {return head;}
        ListNode* p;
        p = reverseList(head->next);
        head->next->next= head;
        head-> next = nullptr;
        return p;
    }
};
