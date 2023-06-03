
#include "lab8/Stack.hpp"

int main() {
    st::Stack<int> stack;
    for (int i = 0; i < 10; ++i) {
        stack.push(10 + i);
    }
    std::cout << stack.empty() << std::endl;
    std::cout << stack << "Size of stack: " << stack.size() << std::endl;

    std::cout << "delete item: " << stack.top() << std::endl;
    stack.pop();
    std::cout << "Size changed " << stack.size() << ", the top el too" << stack.top() << std::endl;

    st::Stack<std::string> stack1(10, "sdfs");
    std::cout << stack1;

    return 0;
}
