/*
23. �ϲ�K����������
�Ѷ� ����
�ϲ�?k?�������������غϲ������������������������㷨�ĸ��Ӷȡ�


ʾ��:
����:
[
? 1->4->5,
? 1->3->4,
? 2->6
]
���: 1->1->2->3->4->4->5->6


��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/merge-k-sorted-lists
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


˼·��1. ����Ƚϣ�2. ���ȶ���
*/



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ����Ƚ�
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

// ���ȶ���
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
