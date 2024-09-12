//
// Created by Zhaohong Liu on 2024/9/9.
//

#include<iostream>
#include<vector>

#include "BaseSolution.h"

class MinimumSizeSubarraySum final : public BaseSolution {
public:
    MinimumSizeSubarraySum() : BaseSolution(209, "Minimum Size Subarray Sum") {}

    static int minSubArrayLen(const int target, const std::vector<int>& nums) {
        int sum = 0;
        int result = INT_MAX;
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); ++fastIndex) {
            sum += nums[fastIndex];
            while (sum >= target) {
                int subArrayLen = fastIndex - slowIndex + 1;
                result = std::min(result, subArrayLen);

                // update slowIndex and sum
                sum -= nums[slowIndex++];
            }
        }
        return result == INT_MAX ? 0 : result;
    }

    void runSolution() override {
        displayProblemInfo();
        constexpr int target = 7;
        const std::vector<int> nums = {2, 3, 1, 2, 4, 3};

        std::cout << "The target sum is: " << target << std::endl;
        std::cout << "The input array is: ";
        for (const auto& num : nums) {
            std::cout << num << " ";
        }

        std::cout << std::endl << "The minimum size of subarray sum is: " << minSubArrayLen(target, nums) << std::endl;

    }
};