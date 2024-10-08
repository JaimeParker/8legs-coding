//
// Created by Zhaohong Liu on 2024/8/28.
//

#ifndef SOLUTIONFACTORY_H
#define SOLUTIONFACTORY_H

#include "BaseSolution.h"
#include "../array/BinarySearch.cpp"
#include "../array/RemoveElement.cpp"
#include "../array/SquaresOfASortedArray.cc"
#include "../array/MinimumSizeSubarraySum.cc"
#include "../array/SpiralMatrix2.cc"
#include "../listnode/RemoveLinkedListElements.cc"
#include "../listnode/DesignLinkedList.cc"

#include <memory>
#include <unordered_map>
#include <functional>

class SolutionFactory {
public:
    SolutionFactory() {
        // register solutions
        solutionMap[704] = []() { return std::make_unique<BinarySearch>(); };
        solutionMap[27] = []() { return std::make_unique<RemoveElement>(); };
        solutionMap[977] = []() { return std::make_unique<SquaresOfASortedArray>(); };
        solutionMap[209] = []() { return std::make_unique<MinimumSizeSubarraySum>(); };
        solutionMap[59] = []() { return std::make_unique<SpiralMatrix2>(); };
        solutionMap[203] = []() { return std::make_unique<RemoveLinkedListElements>(); };
        solutionMap[707] = []() { return std::make_unique<DesignLinkedList>(); };
    }

    std::unique_ptr<BaseSolution> getSolution(const int id) {
        if (solutionMap.contains(id)) {
            return solutionMap[id]();
        }
        return nullptr;
    }

private:
    std::unordered_map<int, std::function<std::unique_ptr<BaseSolution>()>> solutionMap;
};

#endif //SOLUTIONFACTORY_H
