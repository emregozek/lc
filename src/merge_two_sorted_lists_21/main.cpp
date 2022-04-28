#include <iostream>
#include <cstdio>
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {

    }
    ListNode(int x) : val(x), next(nullptr) {

    }
    ListNode(int x, ListNode *next) : val(x), next(next) {

    }
};


class Solution {
public:
    ListNode* sort(ListNode* list) {
        if (!list) {
            return nullptr;
        } else if (!list->next) {
            return list;
        }

        ListNode* head {nullptr};

        ListNode* iter_left_prev {nullptr};
        auto iter_left {list};

        std::size_t cnt {};

        while (iter_left) {
            ListNode* iter_right_prev {iter_left};

            ListNode* min_node_prev {iter_right_prev};

            while (iter_right_prev->next) {
                
                if (iter_right_prev->next->val < min_node_prev->next->val) {
                    min_node_prev = iter_right_prev;
                }

                iter_right_prev = iter_right_prev->next;
            }
            if (min_node_prev->next && min_node_prev->next->val < iter_left->val) {

                auto tmp_min_next {min_node_prev->next->next};
                auto tmp_min_cur {min_node_prev->next};
                auto tmp_left_next {iter_left->next};
                auto tmp_left_cur {iter_left};

                if (iter_left_prev) {
                    iter_left_prev->next = tmp_min_cur;
                }
                if (tmp_min_cur != tmp_left_next) {
                    tmp_min_cur->next = tmp_left_next;
                    min_node_prev->next = tmp_left_cur;
                } else {
                    tmp_min_cur->next = tmp_left_cur;
                }

                iter_left->next = tmp_min_next;

                iter_left = tmp_min_cur;

            }
            if (cnt++ == 0) {
                head = iter_left;
                iter_left_prev = iter_left;
            } else if (iter_left_prev) {
                iter_left_prev = iter_left_prev->next;
            }
            iter_left = iter_left->next;
        }
        return head;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (!list1 && !list2) {
            return nullptr;
        } else if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        }
        ListNode* head {nullptr};
        auto tail {head};
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                if (!head) {
                    head = list1;
                    tail = head;
                    list1 = list1->next;
                } else {
                    tail->next = list1;
                    list1 = list1->next;
                    tail = tail->next;
                }
            } else {
                if (!head) {
                    head = list2;
                    tail = head;
                    list2 = list2->next;
                } else {
                    tail->next = list2;
                    list2 = list2->next;
                    tail = tail->next;
                }
            }
        }
        if (tail) tail->next = list1 ? list1 : list2;
        return head;
    }
};


int main() {
    std::cout << "Hello world!\n";
    Solution sol{};

    // list1: [1,2,4]
    // list2: [1,3,4]

    ListNode *list1 = nullptr;
    for (auto& val : {5,3,1,4,2}) {
        list1 = new ListNode(val, list1);
    }
    auto iter1 {list1};

    std::cout << "\nlist1:\n";
    while (iter1) {
        std::cout << "list1->val: "<< iter1->val << "\n";
        iter1 = iter1->next;
    }
    list1 = sol.sort(list1);
    iter1 = list1;

    std::cout << "\nlist1:\n";
    while (iter1) {
        std::cout << "list1->val: "<< iter1->val << "\n";
        iter1 = iter1->next;
    }
    ListNode *list2 = nullptr;
    for (auto& val : {0}) {
        list2 = new ListNode(val, list2);
    }
    auto iter2 {list2};

    std::cout << "list2:\n";
    while (iter2) {
        std::cout << "list2->val: "<< iter2->val << "\n";
        iter2 = iter2->next;
    }

    auto merged_list {sol.mergeTwoLists(nullptr, list2)};
    auto iter3 {merged_list};

    std::cout << "merged list:\n";
    while (iter3) {
        std::cout << "merged_list->val: "<< iter3->val << "\n";
        iter3 = iter3->next;
    }

    return 0;
}