#include "valid_paranthesis.h"
#include <iostream>


// class MemberFunctionPointerArray {
//     public:
//         int f1(int, int) {return 0;}
//         int f2(int, int) {return 0;}
//         int f3(int, int) {return 0;}
//         int f4(int, int) {return 0;}
//         int f5(int, int) {return 0;}
// };

// using MFptr = int(MemberFunctionPointerArray::*)(int, int);

int main() {
    // MemberFunctionPointerArray myelem {}; 
    // MFptr mfptr {&MemberFunctionPointerArray::f1};
    // MFptr mfptr_arr[] {
    //     &MemberFunctionPointerArray::f1,
    //     &MemberFunctionPointerArray::f2,
    //     &MemberFunctionPointerArray::f3,
    //     &MemberFunctionPointerArray::f4,
    //     &MemberFunctionPointerArray::f5
    //     };

    // int(MemberFunctionPointerArray::* mfptr2[])(int, int) {
    //     &MemberFunctionPointerArray::f1,
    //     &MemberFunctionPointerArray::f2,
    //     &MemberFunctionPointerArray::f3,
    //     &MemberFunctionPointerArray::f4,
    //     &MemberFunctionPointerArray::f5
    // };
    
    Solution sol;

    std::cout << std::boolalpha << sol.isValid("()") << "\n";
    return 0;
}