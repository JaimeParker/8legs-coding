// Created by Zhaohong Liu on 2024/9/27.
// Ref: https://kamacoder.com/problempage.php?pid=1070
// 题目名称：区间和
// 题目描述：给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
// 输入描述：第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。
//         随后的输入为需要计算总和的区间下标：a，b （b > = a），直至文件结束。
// 输出描述：输出每个指定区间内元素的总和。

#include <iostream>
#include <vector>

int main() {
    int n, a, b;
    std::cin >> n;
    std::vector<int> vec(n);
    std::vector<int> vec_sum(n);
    int vec_sum_till_i = 0;

    // input n, and the vector
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
        vec_sum_till_i += vec[i];
        vec_sum[i] = vec_sum_till_i;
    }

    while (std::cin >> a >> b) {
        int sum;
        if (a == 0) {
            sum = vec_sum[b];
        } else {
            sum = vec_sum[b] - vec_sum[a - 1];
        }
        std::cout << sum << std::endl;
    }
}
