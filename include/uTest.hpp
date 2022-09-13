#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <string>
#include <exception>
#include <iostream>
#include <memory>

class uTest {
    public:
    virtual ~uTest() = default;
    void run(size_t depth = 0) {
        for (size_t i = 0; i < depth; i++) {
            std::cout << '\t';
        }
        size_t total = _subTests.size();
        size_t passed = 0;
        if (total) {
            std::cout << _msg << '\n';
            for (auto& test : _subTests) {
                total++;
                try {
                    test->run(depth + 1);
                    passed++;
                } catch (std::exception e) {
                }
                std::cout << '\n';
            }
        } else {
            try {
                _test();
                std::cout << '!' << _msg;
            } catch (std::exception e) {
                std::cout << '?' << _msg << e.what();
                throw e;
            }
        }
        if (passed < total) throw std::runtime_error("not all tests passed");
    } 
    protected:
    virtual void _test() = 0; //бросить исключение если что-то не так
    std::vector<std::unique_ptr<uTest>> _subTests = {};
    std::string _msg;
};