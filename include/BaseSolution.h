//
// Created by Zhaohong Liu on 2024/8/28.
//

#ifndef BASESOLUTION_H
#define BASESOLUTION_H

#include <string>
#include <iostream>
#include <utility>

class BaseSolution {
protected:
    int problem_id;
    std::string problem_name;

public:
    BaseSolution(const int id, std::string name) : problem_id(id), problem_name(std::move(name)) {}

    // show problem info
    virtual void displayProblemInfo() const {
        std::cout << "" << std::endl;
#ifdef _WIN32
        std::cout << "Problem ID: " << problem_id << std::endl;
        std::cout << "Problem Name: " << problem_name << std::endl;
#else
        std::cout << "\033[1;32mProblem ID: " << problem_id << "\033[0m" << std::endl;
        std::cout << "\033[1;32mProblem Name: " << problem_name << "\033[0m" << std::endl;
#endif
        std::cout << "---------------------------------------" << std::endl;
    }

    virtual void runSolution() = 0;

    virtual ~BaseSolution() = default; // 虚析构函数以确保派生类的析构函数被调用
};

#endif //BASESOLUTION_H
