#include <iostream>

#include "SolutionFactory.h"

int main()
{
    SolutionFactory factory;
    int problemId;

    std::cout << "enter the problem ID: ";
    std::cin >> problemId;

    if (const auto solution = factory.getSolution(problemId)) {
        solution->runSolution();
    } else {
        std::cout << "problem not found!" << std::endl;
    }

    return 0;
}
