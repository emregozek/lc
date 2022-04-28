#include <iostream>
#include <memory>
#include <limits>
#include <algorithm>

class MinStackIterationFirst {
    private:
        struct Element {
            int val;
            int min;
        };
        std::size_t m_cap {10};
        std::size_t m_size {0};
        Element *m_data {nullptr};
        bool resize(std::size_t cap) {
            auto tmp_data = new Element[cap];
            if (!tmp_data) {
                return false;
            }
            std::memcpy(tmp_data, m_data, m_size * sizeof(Element));
            m_data = tmp_data;
            m_cap = cap;
            return true;
        }
    public:
        MinStackIterationFirst() : m_cap{10}, m_size{0} {
            m_data = new Element[m_cap];
            if (!m_data) {
                return;
            }
        }
        ~MinStackIterationFirst() {
            if (m_data) {
                delete[] m_data;
            }
            m_data = nullptr;
            m_cap = 0;
            m_size = 0;
        }
    
        void push(int val) {
            if (m_size == m_cap) {
                resize(m_cap * 2);
            }
            m_data[m_size].val = val;
            m_data[m_size].min = (m_size == 0) ? val : m_data[m_size - 1].min < val ? m_data[m_size - 1].min : val;
            ++m_size;
        }
    
        void pop() {
            if (m_size == 0) {
                return;
            }
            --m_size;
            return;
        }
    
        int top() {
            if (m_size == 0) {
                return 0;
            }
            return m_data[m_size - 1].val;
        }
    
        int getMin() {
            if (m_size == 0) {
                return 0;
            }
            return m_data[m_size - 1].min;
        }
};


class MinStackIterationSecond {
    private:
        int m_min {INT_MAX};
        std::size_t m_cap {10};
        std::size_t m_size {0};
        int *m_ptr {nullptr};
        bool resize(std::size_t cap) {
            auto tmp_ptr = new int[cap];
            if (!tmp_ptr) {
                return false;
            }
            std::memcpy(tmp_ptr, m_ptr, m_size * sizeof(int));
            m_ptr = tmp_ptr;
            m_cap = cap;
            return true;
        }
    public:
        MinStackIterationSecond() : m_min{INT_MAX}, m_cap{10}, m_size{0} {
            m_ptr = static_cast<int*>(std::malloc(sizeof(int)* m_cap));
            if (!m_ptr) {
                return;
            }
        }
        ~MinStackIterationSecond() {
            if (m_ptr) free(m_ptr);
            m_min = INT_MAX;
            m_cap = 0;
            m_size = 0;
        }
    
        void push(int val) {
            if (m_size == m_cap) {
                resize(m_cap * 3 / 2);
            }
            *(m_ptr + m_size) = val;
            if (INT_MAX == m_min) {
                m_min = val;
            } else if (val < m_min) {
                m_min = val;
            }
            ++m_size;
        }
    
        void pop() {
            if (m_size == 0) {
                return;
            } else if (m_size == 1) {
                --m_size;
                m_min = INT_MAX;
                return;
            }
            --m_size;
            m_min = *(std::min_element(m_ptr, (m_ptr + m_size)));
            return;
        }
    
        int top() {
            if (m_size == 0) {
                return 0;
            }
            return *(m_ptr + m_size - 1);
        }
    
        int getMin() {
            return m_min;
        }
};

class MinStackIterationThird {
    private:
        struct Min {
            int val;
            int n_items;
        };

        std::size_t m_size_data {0};
        std::size_t m_cap_data {10};

        std::size_t m_size_min {0};
        std::size_t m_cap_min {4};

        int *m_data {nullptr};

        Min *m_min {nullptr};
        
        bool resize_data(std::size_t cap) {
            auto tmp_data = new int[cap];
            if (!tmp_data) {
                return false;
            }
            std::memcpy(tmp_data, m_data, m_size_data * sizeof(int));
            m_data = tmp_data;
            m_cap_data = cap;
            return true;
        }
        bool resize_min(std::size_t cap) {
            auto tmp_min = new Min[cap];
            if (!tmp_min) {
                return false;
            }
            std::memcpy(tmp_min, m_min, m_size_min * sizeof(Min));
            m_min = tmp_min;
            m_cap_min = cap;
            return true;
        }
    public:
        MinStackIterationThird() {
            m_data = new int[m_cap_data];
            if (!m_data) {
                return;
            }
            m_min = new Min[m_cap_min];
            if (!m_min) {
                return;
            }
        }
        ~MinStackIterationThird() {
            if (m_data) {
                delete[] m_data;
            }
            if (m_min) {
                delete[] m_min;
            }
            m_data = nullptr;
            m_min = nullptr;
            m_cap_data = 0;
            m_cap_min = 0;
            m_size_data = 0;
            m_size_min = 0;
        }
    
        void push(int val) {
            if (m_size_data == m_cap_data) {
                resize_data(m_cap_data * 3 / 2);
            }
            m_data[m_size_data] = val;

            if (m_size_min == 0) {
                if (m_size_min == m_cap_min) {
                    resize_min(m_cap_min * 3 / 2);
                }
                m_min[m_size_min].n_items = 1;
                m_min[m_size_min].val = val;
                ++m_size_min;
            } else if (val == m_min[m_size_min - 1].val) {
                ++m_min[m_size_min - 1].n_items;
            } else if (val < m_min[m_size_min - 1].val) {
                if (m_size_min == m_cap_min) {
                    resize_min(m_cap_min * 3 / 2);
                }
                m_min[m_size_min].n_items = 1;
                m_min[m_size_min].val = val;
                ++m_size_min;
            }
            ++m_size_data;
        }
    
        void pop() {
            if (m_size_data == 0 || m_size_min == 0) {
                return;
            }
            if (m_data[m_size_data - 1] == m_min[m_size_min - 1].val) {
                if (m_min[m_size_min - 1].n_items > 1) {
                    --m_min[m_size_min - 1].n_items;
                } else {
                    --m_size_min;
                }
            }
            --m_size_data;
            return;
        }
    
        int top() {
            if (m_size_data == 0) {
                return 0;
            }
            return m_data[m_size_data - 1];
        }
    
        int getMin() {
            if (m_size_data == 0 || m_size_min == 0) {
                return 0;
            }
            return m_min[m_size_min - 1].val;
        }
};

using MinStack = MinStackIterationThird;

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

void f1() {
    
        auto minStack = new MinStack();
        minStack->push(-2);
        minStack->push(0);
        minStack->push(-3);
        // return -3
        std::cout << "minStack->getMin() = " << minStack->getMin() << "\n"; 
        minStack->pop();
        // return 0
        std::cout << "minStack->top() = " << minStack->top() << "\n";
        // return -2
        std::cout << "minStack->getMin() = " << minStack->getMin() << "\n";
    
}
void f2()
{
    auto minStack = new MinStack();
    minStack->push(2);
    minStack->push(0);
    minStack->push(3);
    minStack->push(0);
    std::cout << "minStack->getMin() = " << minStack->getMin() << "\n";
    minStack->pop();
    std::cout << "minStack->getMin() = " << minStack->getMin() << "\n";
    minStack->pop();
    std::cout << "minStack->getMin() = " << minStack->getMin() << "\n";
    minStack->pop();
    std::cout << "minStack->getMin() = " << minStack->getMin() << "\n";
}
void f3() {
    auto stack {new MinStack{}};
    stack->push(85);
    stack->push(-99);
    stack->push(67);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(-27);
    stack->push(61);
    stack->push(-97);
    stack->push(-27);
    stack->push(35);
    stack->top();
    stack->push(99);
    stack->push(-66);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(-89);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(4);
    stack->push(-70);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(52);
    stack->top();
    stack->push(54);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(94);
    stack->push(-41);
    stack->push(-75);
    stack->push(-32);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(5);
    stack->push(29);
    stack->top();
    stack->push(-78);
    stack->push(-74);
}


void f4() {
    auto stack {new MinStack{}};
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->pop();
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(-58);
    stack->push(-44);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(-64);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->pop();
    stack->push(-45);
    stack->push(-99);
    stack->push(-27);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(-96);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->pop();
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(26);
    stack->push(-58);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->top();
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(25);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(33);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(71);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(-62);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(-78);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->pop();
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(-30);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(85);
    stack->push(-15);
    stack->pop();
    stack->push(-40);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(72);
    stack->top();
    stack->top();
    stack->push(18);
    stack->push(59);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->pop();
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(-59);
    stack->top();
    stack->push(10);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    stack->push(9);
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";
    std::cout << "stack->getMin() = " << stack->getMin() << "\n";

}
int main() {
    f1();
    f2();
    f3();
    f4();
}