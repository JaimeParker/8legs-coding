//
// Created by Zhaohong Liu on 2024/9/9.
//

#include <iostream>
#include <vector>

#include "BaseSolution.h"

class SquaresOfASortedArray final : public BaseSolution {
public:
    SquaresOfASortedArray() : BaseSolution(977, "Squares of a Sorted Array") {}

    static std::vector<int> sortedSquares(const std::vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        std::vector result(nums.size(), 0);

        if (nums[0] >= 0) {
            for (int i = 0; i < nums.size(); i++) {
                result[i] = nums[i] * nums[i];
            }
            return result;
        }

        int endIndex = static_cast<int>(nums.size() - 1);
        for (int leftIndex = 0, rightIndex = endIndex; leftIndex <= rightIndex;) {
            if (std::abs(nums[leftIndex]) > std::abs(nums[rightIndex])) {
                result[endIndex--] = nums[leftIndex] * nums[leftIndex];
                leftIndex++;
            } else {
                result[endIndex--] = nums[rightIndex] * nums[rightIndex];
                rightIndex--;
            }
        }

        return result;
    }

    void runSolution() override {
        displayProblemInfo();

        const std::vector nums = {-4,-1,0,3,10};
        const auto result = sortedSquares(nums);
        std::cout << "Example: " << std::endl;
        for (const auto& num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        std::cout << "Result: " << std::endl;
        for (const auto& num : result) {
            std::cout << num << " ";
        }
    }
};

