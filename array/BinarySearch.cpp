//
// Created by Zhaohong Liu on 2024/8/28.
// Link: https://leetcode.cn/problems/binary-search/description/
//

#include "../include/BaseSolution.h"

#include <vector>

class BinarySearch final : public BaseSolution {
public:
    BinarySearch() : BaseSolution(704, "Binary Search") {}

    // solution
    static int search(const std::vector<int>& nums, const int target) {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);
        if (nums.empty()) {
            throw std::invalid_argument("invalid input, nums is empty");
        }

        while (left <= right) {
            if (const int middle = left + (right - left) / 2; nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle -1;
            } else {
                return middle;
            }
        }

        // no target found
        return -1;
    }

    void runSolution() override {
        displayProblemInfo();

        const std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
        constexpr int target = 9;
        std::cout << "Example test: " << search(nums, target) << std::endl;
    }
};