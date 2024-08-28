//
// Created by Zhaohong Liu on 2024/8/28.
// Link: https://leetcode-cn.com/problems/remove-element/description/
//

#include "../include/BaseSolution.h"

#include <vector>

class RemoveElement final : public BaseSolution {
public:
    RemoveElement() : BaseSolution(27, "Remove Element") {}

    static int removeElement(std::vector<int>& nums, const int val) {
        int slowIndex = 0;
        if (nums.empty()) {
            return 0;
            // Actually, I think it's better to throw an exception here
            // throw std::invalid_argument("invalid input, nums is empty");
        }

        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }

        return slowIndex;
    }

    void runSolution() override {
        displayProblemInfo();

        std::vector nums = {0,1,2,2,3,0,4,2};
        constexpr int val = 2;
        std::cout << "Example test: " << removeElement(nums, val) << std::endl;
    }
};