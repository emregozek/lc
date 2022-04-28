#include <iosfwd>
#include <cstddef>

class MyLinkedList {
private:
    struct Node {
        int val;
        Node *next;
    };
    std::size_t m_size {0};
    Node* m_head {nullptr};
public:
    MyLinkedList() = default;
    void addAtHead(int val) {
        m_head = new Node{val, m_head};
        ++m_size;
    }

    int get(std::size_t index) {
        if (index >= m_size) {
            return -1;
        }
        auto iter {m_head};
        while (index > 0) {
            iter = iter->next;
            --index;
        }
        return iter->val;
    }
    
    void addAtTail(int val) {
        auto tail {m_head};
        while (tail && tail->next) {
            tail = tail->next;
        }
        if (tail) {
            tail->next = new Node{val, nullptr};
        } else {
            m_head = new Node{val, nullptr};
        }
        ++m_size;
    }
    
    void addAtIndex(std::size_t index, int val) {
        if (index > m_size) {
            return;
        }
        auto prev {m_head};
        while (index > 1) {
            prev = prev->next;
            --index;
        }
        if (index != 0) {
            prev->next = new Node{val, prev ? prev->next : nullptr};
        } else {
            m_head = new Node{val, prev};
        }
        ++m_size;
    }
    
    void deleteAtIndex(std::size_t index) {
        if (index >= m_size || m_size == 0) {
            return;
        }
        auto prev {m_head};
        if (index == 0) {
            m_head = prev->next ? prev->next : nullptr;
            delete prev;
        } else {
            while (index > 1) {
                prev = prev->next;
                --index;
            }
            auto node_to_delete {prev->next};
            if (node_to_delete->next) {
                prev->next = node_to_delete->next;
            } else {
                prev->next = nullptr;
            }
            delete node_to_delete;
        }
        --m_size;
    }
    void print() const {
        std::cout << "\nmyLinkedList->print()\n";
        std::cout << "size: " << m_size << "\n";
        auto iter {m_head};
        while (iter) {
            std::cout << "val: " << iter->val << "\n";
            iter = iter->next;
        }
    }
};