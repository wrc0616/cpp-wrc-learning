

//方法一  快慢指针
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




//方法二 哈希表，集合
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
        //定义一个集合，<>中为存储的数据类型
        unordered_set<ListNode *> myset;
        while(head!=nullptr)
        {
            //count函数是查找集合中有无相同的元素，如果有返回true，没有返回false
            if(myset.count(head)==1)
            {
                return true;
            }
            //insert在集合中插入head这个元素
            myset.insert(head);
            head=head->next;
        }
        return false;

    }
};

