#pragma once

#include <vector>
#include <iostream>


namespace st {
    template<class T>
    class Stack {
    public:
        Stack(int size) {
            try {
                sizeArray = size;
                stack_array.reserve(size);
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }

        Stack(int size, T item) {
            try {
                sizeArray = size;
                for (int i = 0; i < sizeArray; i++)
                    stack_array.push_back(item);
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
                throw;
            }
        }

        Stack() {
            sizeArray = 0;
        }

        ~Stack() {

        }

        int size() {
            return sizeArray;
        }

        bool empty() {
            bool result = true;
            if (sizeArray != 0)
                result = false;
            return result;
        }

        void push(const T& item) {
            try {
                sizeArray++;
                stack_array.push_back(item);
            }
            catch (const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
        }

        void pop() {
            if (!empty()) {
                sizeArray--;
                stack_array.pop_back();
            }
            else
                throw std::out_of_range("stack is empty");
        }

        T& top() {
            if (!empty())
                return stack_array[sizeArray - 1];
            throw std::logic_error("stack is empty");
        }

    private:
        std::vector<T> stack_array;
        int sizeArray;

        friend std::ostream& operator<<(std::ostream& out, const Stack st) {
            for (const T item : st.stack_array) {
                out << item << " ";
            }
            out << std::endl;
            return out;
        }
    };

}

