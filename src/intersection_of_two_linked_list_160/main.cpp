#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto iterA {headA};
        auto iterB {headB};
        std::unordered_set<ListNode*> node_list;
        while (iterA) {
            node_list.insert(iterA);
            iterA = iterA->next;
        }
        while (iterB && node_list.end() == node_list.find(iterB)) {
            iterB = iterB->next;
        }
        return iterB ? iterB : nullptr;
    }
    static ListNode *getIntersectionNodeOptimized(ListNode *headA, ListNode *headB) {
        auto iterA {headA};
        auto iterB {headB};
        // [4,1,  8,4,5]
        // [5,6,1,8,4,5]
        while (iterA != iterB) {
            iterA = iterA->next == nullptr ? headB : iterA->next;
            iterB = iterB->next == nullptr ? headA : iterB->next;
        }
        return iterA;
    }
};

int main() {

    // [4,1,  8,4,5]
    // [5,6,1,8,4,5]
    ListNode *headA {nullptr};
    for (auto& val : {5,4,8,1,4}) {
        headA = new ListNode{val, headA};
    }
    ListNode *intersection {headA->next->next};
    ListNode *headB {nullptr};
    for (auto& val : {1,6,5}) {
        headB = new ListNode{val, headB};
    }
    auto tailB {headB};
    while (tailB->next) { tailB = tailB->next; }
    tailB->next = intersection;
    
    for (auto iterA {headA}; iterA != nullptr; iterA = iterA->next) {
        std::cout << "iterA: " << iterA << " iterA->val: " << iterA->val << "\n";
    }
    std::cout << "\n\n";
    for (auto iterB {headB}; iterB != nullptr; iterB = iterB->next) {
        std::cout << "iterB: " << iterB << " iterB->val: " << iterB->val << "\n";
    }
    std::cout << "\n\n";

    auto intersect1 = Solution::getIntersectionNode(headA, headB);
    if (intersect1) {
        std::cout << "intersect1: " << intersect1 << " val: " << intersect1->val << "\n";
    } else {
        std::cout << "no intersection\n";
    }
    
    auto intersect2 = Solution::getIntersectionNodeOptimized(headA, headB);
    if (intersect2) {
        std::cout << "intersect2: " << intersect2 << " val: " << intersect2->val << "\n";
    } else {
        std::cout << "no intersection\n";
    }

    return 0;
}