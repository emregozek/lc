#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next{next} {}
};

class Solution {
private:
    static ListNode *meetingPoint(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode *fast {head};
        ListNode *slow {head};
        while (fast && fast->next != slow) {
            if (!fast || !fast->next) {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->next;
    }
public:
    static ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return nullptr;
        }
        
        if (ListNode* meet_node = meetingPoint(head); !meet_node) {
            return nullptr;
        } else {
            auto cycle {meet_node};
            auto iter_beg {head};
            while (iter_beg != cycle) {
                iter_beg = iter_beg->next;
                cycle = cycle->next;
            }
            return iter_beg;
        }
    }
};

int main() {
    std::cout << "Hello world!\n";
    {
        ListNode* head {nullptr};
        for (const auto& val : {5,4,3,2,1}) {
            head = new ListNode{val, head};
        }
        auto iter {head};
        while (iter) {
            std::cout << "iter.val = " << iter->val << "\n";
            iter = iter->next;
        }

        iter = head;
        while (iter) {
            if (iter->val == 4) {
                iter->next = head->next;
                break;
            }
            iter = iter->next;
        }

        auto intersect {Solution::detectCycle(head)};
        if (intersect) {
            std::cout << "intersect: " << intersect << " intersect->val = " << intersect->val << "\n";
        } else {
            std::cout << "no intersect\n";
        }
    }
    // {
    //     ListNode* head {nullptr};
    //     for (const auto& val : {2,1}) {
    //         head = new ListNode{val, head};
    //     }

    //     auto intersect {Solution::detectCycle(head)};
    //     if (intersect) {
    //         std::cout << "intersect: " << intersect << " intersect->val = " << intersect->val << "\n";
    //     } else {
    //         std::cout << "no intersect\n";
    //     }
    // }
    return 0;
}