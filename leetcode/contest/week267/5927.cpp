

#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<deque>
#include<map>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* tmp = head;
        ListNode* prev = head;
        ListNode* last = head;
        int count = 0;
        int len = 1;
        while (tmp != nullptr)
        {
            count++;
            if (count == len) {
                if (count % 2 == 0) {
                    // 偶数长度
                    // prev->next 开始，到 tmp进行反转
                    ListNode* after = tmp->next;
                    ListNode* newHead = reverse(prev->next, tmp);
                    tmp = prev->next;
                    prev->next->next = after;
                    prev->next = newHead;
                }
                prev = tmp;
            }
            last = tmp;
            tmp = tmp->next;
            if (count == len) {
                count = 0;
                len++;
            }
        }
        if (count > 0 && (count % 2 == 0)) {
            ListNode* after = last->next;
            ListNode* newHead = reverse(prev->next, last);
            prev->next->next = after;
            prev->next = newHead;
        }
        return head;
    }
    // reverse 反转 prev->next...end
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* next = start->next;

        while (prev != end)
        {
            start->next = prev;

            prev = start;
            start = next;
            if (next->next != nullptr) {
            next = next->next;
            }
        }
        return end;
    }
};

int main() {
    vector<int> value{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode *start;
    ListNode *tmp;
    for (int i = 0; i != value.size(); i ++) {
        if (i == 0) {
            start = new ListNode{value[i]};
            tmp = start;
        } else {
            tmp->next = new ListNode{value[i]};
            tmp = tmp->next;
        }
    }
    Solution s = Solution();
    ListNode* result = s.reverseEvenLengthGroups(start);
    return 1;
}