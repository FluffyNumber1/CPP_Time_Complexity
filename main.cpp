#include <iostream>
#include <vector>
#include <chrono>
#include <string>
//must import string, vector, and iostream from namespace.
//using namespace std; would allow for dropping std:: in the code below
#include "StringData.h"
int binary_search(const std::vector<std::string>& container, std::string element) {
    int low = 0;
    int high = container.size() - 1;  // Use .size() for vector size

    while (low <= high) {
        int mid = (low + high) / 2;

        if (container[mid]== element) {
            return mid;  // Element found
        }
        else if (container[mid] < element) {
            low = mid + 1;  // Search the right half
        }
        else {
            high = mid - 1;  // Search the left half
        }
    }

    return -1;  // Element not found
}

int linear_search(const std::vector<std::string>& container, std::string element) {
    for (size_t i = 0; i < container.size(); ++i) {  // Use .size() for vector size
        if (container[i] == element) {
            return i;  // Element found
        }
    }
    return -1;  // Element not found
}

int main() {
    //Linear search for the string "aaaaa"
    std::vector<std::string> container = getStringData();
    auto start_time = std::chrono::system_clock::now();
    int linear_aaaaa = linear_search(container, "aaaaa");
    auto end_time = std::chrono::system_clock::now();
    std::cout << "Linear Search {'aaaaa'}: " << end_time-start_time << "- Return: " << linear_aaaaa<<  std::endl;

    //Binary search for the string "aaaaa"
    start_time = std::chrono::system_clock::now();
    int binary_aaaaa = binary_search(container, "aaaaa");
    end_time = std::chrono::system_clock::now();
    std::cout << "Binary Search {'aaaaa'}: " << end_time-start_time << "- Return: " << binary_aaaaa<<  std::endl;

    //Linear search for the string "not_here"
    start_time = std::chrono::system_clock::now();
    int linear_not_here = linear_search(container, "not_here");
    end_time = std::chrono::system_clock::now();
    std::cout << "Linear Search {'not_here'}: " << end_time-start_time << "- Return: " << linear_not_here<<  std::endl;

    //Binary search for the string "not_here"
    start_time = std::chrono::system_clock::now();
    int binary_not_here = binary_search(container, "not_here");
    end_time = std::chrono::system_clock::now();
    std::cout << "Binary Search {'not_here'}: " << end_time-start_time << "- Return: " << binary_not_here<<  std::endl;

    //Linear search for the string "mzzzz"
    start_time = std::chrono::system_clock::now();
    int linear_mzzzz = linear_search(container, "mzzzz");
    end_time = std::chrono::system_clock::now();
    std::cout << "Linear Search {'mzzzz'}: " << end_time-start_time << "- Return: " << linear_mzzzz<<  std::endl;

    //Binary search for the string "mzzzz"
    start_time = std::chrono::system_clock::now();
    int binary_mzzzz = binary_search(container, "mzzzz");
    end_time = std::chrono::system_clock::now();
    std::cout << "Binary Search {'mzzzz'}: " << end_time-start_time << "- Return: " << binary_mzzzz<<  std::endl;

    return 0;
}