

//  快慢指针方法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //首先判断链表是不是空链表或者链表节点为一个
        if (head == nullptr || head->next==nullptr)
        {
            return false;
        }
        //定义快慢指针
        ListNode *fast = head->next;
        ListNode *slow = head;
        //循环，如果快指针和慢指针指向同一个地址，说明有环形。在这里快指针比慢指针快一步，当然也可以快多步
        while(fast != slow)
        {
            if(fast==nullptr || fast->next==nullptr)
            {
                return false;
            }
            //快指针指向接下来第二个结节的地址
            fast = fast->next->next;
            //慢指针指向下一个结节的地址
            slow = slow->next;
        }

        return true;

    }
};
