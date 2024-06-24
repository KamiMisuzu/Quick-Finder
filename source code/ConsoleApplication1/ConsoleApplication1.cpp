#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <chrono>

// 测试直接创建 std::string 的性能
void test_direct_string_creation(size_t iterations) {
    std::vector<std::string> strings;
    strings.reserve(iterations);

    for (size_t i = 0; i < iterations; ++i) {
        strings.emplace_back("This is a test string");
    }
}

// 测试使用 std::unique_ptr 创建 std::string 的性能
void test_unique_ptr_string_creation(size_t iterations) {
    std::vector<std::unique_ptr<std::string>> strings;
    strings.reserve(iterations);

    for (size_t i = 0; i < iterations; ++i) {
        strings.emplace_back(std::make_unique<std::string>("This is a test string"));
    }
}

// 测试使用 std::shared_ptr 创建 std::string 的性能
void test_shared_ptr_string_creation(size_t iterations) {
    std::vector<std::shared_ptr<std::string>> strings;
    strings.reserve(iterations);

    for (size_t i = 0; i < iterations; ++i) {
        strings.emplace_back(std::make_shared<std::string>("This is a test string"));
    }
}

int main() {
    const size_t iterations = 1000000;

    auto start = std::chrono::high_resolution_clock::now();
    test_direct_string_creation(iterations);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> direct_duration = end - start;
    std::cout << "Direct string creation: " << direct_duration.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    test_unique_ptr_string_creation(iterations);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> unique_ptr_duration = end - start;
    std::cout << "Unique_ptr string creation: " << unique_ptr_duration.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    test_shared_ptr_string_creation(iterations);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> shared_ptr_duration = end - start;
    std::cout << "Shared_ptr string creation: " << shared_ptr_duration.count() << " seconds\n";

    return 0;
}
