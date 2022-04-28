#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* ptr) : val(x), next(ptr) {}
 };

class Solution {
public:
    static bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> ptr_hash_table;
        while (head && (ptr_hash_table.end() == ptr_hash_table.find(head))) {
            ptr_hash_table.insert(head);
            head = head->next;
        }
        if (head) {
            return true;
        } else {
            return false;
        }
    }
    static bool hasCycle2pointers(ListNode *head) {
        if (!head) {
            return false;
        }
        auto slow {head};
        auto fast {head->next};

        while (slow != fast) {
            if (!fast || !fast->next) {
                return false;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};


int main() {

    ListNode* head = nullptr;
    for (const auto val : {1,3,5,7,9,11}) {
        head = new ListNode(val, head);
    }
    auto iter {head};
    while (iter) {
        std::cout << "val = " << iter->val << " ";
        iter = iter->next;
    }

    ListNode* node4 = new ListNode(4,nullptr);
    ListNode* node3 = new ListNode(3,node4);
    ListNode* node2 = new ListNode(2,node3);
    ListNode* head_cyclic = new ListNode(1,node2);

    node3->next = node2;

    std::cout << "\n";
    std::cout << std::boolalpha << "answer: " << Solution::hasCycle(head) << "\n";
    std::cout << std::boolalpha << "answer: " << Solution::hasCycle(head_cyclic) << "\n";

    std::cout << std::boolalpha << "answer: " << Solution::hasCycle2pointers(head) << "\n";
    std::cout << std::boolalpha << "answer: " << Solution::hasCycle2pointers(head_cyclic) << "\n";
    return 0;
}