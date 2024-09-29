#include <iostream>
#include <vector>
#include <climits>

std::pair<int, int> find_max_ordered_congruent_pair(const std::vector<int>& arr, int n) {
    int max_sum = INT_MIN;
    std::pair<int, int> max_pair = {0, 0};

    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            int a = arr[i];
            int b = arr[j];

            // 判断 a 和 b 是否是 n 的同余对
            if ((a - b) == n * ((a - b) / n)) {
                // 计算和
                int current_sum = a + b;
                // 更新最大值
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    max_pair = {a, b};
                }
            }
        }
    }

    return max_pair;
}

int main() {
    std::vector<int> arr = {5, 11, 8, 7, 2};
    int n = 3;

    std::pair<int, int> result = find_max_ordered_congruent_pair(arr, n);
    std::cout << "最大有序同余对: (" << result.second << ", " << result.first << ")" << std::endl;

    return 0;
}