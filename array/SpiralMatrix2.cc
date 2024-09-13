//
// Created by Zhaohong Liu on 2024/9/12.
//

#include <iostream>
#include <vector>

#include "BaseSolution.h"

class SpiralMatrix2 final : public BaseSolution {
public:
    SpiralMatrix2() : BaseSolution(59, "Spiral Matrix II") {}

    static std::vector<std::vector<int>> generateMatrix(const int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
        int index = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int sector_length = n - 1;
        // 定义前闭后开区间
        while (sector_length > 0) {
            // 左上到右上
            for (int i = left; i < right; i++) {
                matrix[top][i] = index++;
            }
            // 右上到右下
            for (int i = top; i < bottom; i++) {
                matrix[i][right] = index++;
            }
            // 右下到左下
            for (int i = right; i > left; i--) {
                matrix[bottom][i] = index++;
            }
            // 左下到左上
            for (int i = bottom; i > top; i--) {
                matrix[i][left] = index++;
            }
            top++;
            bottom--;
            left++;
            right--;
            sector_length --;
        }

        if (n % 2 == 1) {
            matrix[n / 2][n / 2] = index;
        }

        return matrix;
    }

    void runSolution() override {
        displayProblemInfo();
        constexpr int n = 5;
        for (auto result = generateMatrix(n); const auto &row : result) {
            for (const auto &elem : row) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    }
};