#pragma once

#include <vector>
#include <cstddef>

class permutation {
    public:
    permutation(const std::vector<size_t> in = {}) : data(in) {};
    std::vector<size_t> data;
    permutation transposition(size_t a, size_t b) {
        std::swap(this->data[a], this->data[b]);
        auto temp = *this;
        std::swap(this->data[a], this->data[b]);
        return temp;
    };

    
};

inline std::vector<std::vector<permutation>> orderedPermutations = std::vector<std::vector<permutation>>();

std::vector<permutation> getOrderedPermutatuions(size_t size) {
        if (orderedPermutations.size() == 0) {
            orderedPermutations.push_back(std::vector<permutation>({permutation(std::vector<size_t>(1))}));
        }
        while (orderedPermutations.size() < size) {
            auto temp = orderedPermutations.back();
            orderedPermutations.emplace_back();
            for (auto& i : temp) {
                i.data.push_back(orderedPermutations.size() - 1);
            }
            for (size_t i = 0; i < orderedPermutations.size(); ++i) {
                for (auto& j : temp) {
                    orderedPermutations.back().push_back(j.transposition(i, orderedPermutations.size() - 1));
                }
            }
        }
        return orderedPermutations[size - 1];
    }