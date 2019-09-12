/*
23. 合并K个排序链表
难度 困难
合并?k?个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。


示例:
输入:
[
? 1->4->5,
? 1->3->4,
? 2->6
]
输出: 1->1->2->3->4->4->5->6


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-k-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


思路：1. 逐个比较；2. 优先队列
*/



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 逐个比较
#include <vector>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        
        bool flag = true;
        int min_index = 0;
        while (flag) {
            flag = false;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] != nullptr) {
                    min_index = i;
                    flag = true;
                    break;
                }
            }
            if (!flag)
                break;
            for (int i = min_index + 1; i < lists.size(); i++) {                 
                if (lists[i] != nullptr && lists[i]->val < lists[min_index]->val) {
                    min_index = i;
                }
            }
            p->next = lists[min_index];
            p = p->next;
            lists[min_index] = lists[min_index]->next;
        }
        
        return head->next;
    }
};

// 优先队列
// #include <queue>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     struct cmp {
//         bool operator()(ListNode* a, ListNode* b) {
//             return a->val > b->val;
//         }
//     };
    
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
//         ListNode* head = new ListNode(0);
//         ListNode* p = head;
//         for (int i = 0; i < lists.size(); i++) {
//             if (lists[i])
//                 pq.push(lists[i]);
//         }
//         while (!pq.empty()) {
//             p->next = pq.top();
//             p = p->next;
//             pq.pop();
//             if (p->next)
//                 pq.push(p->next);
//         }
//         return head->next;
//     }
// };
