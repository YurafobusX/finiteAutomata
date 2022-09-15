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
    void run(size_t depth = 0, std::ostream& output = std::cout) {
        for (size_t i = 0; i < depth; i++) {
            output << '\t';
        }
        size_t total = _subTests.size();
        size_t passed = 0;
        if (total) {
            std::stringstream subOutput;
            subOutput << _msg << '\n';
            for (auto& test : _subTests) {
                try {
                    test->run(depth + 1, subOutput);
                    passed++;
                } catch (std::exception e) {
                }
                subOutput << '\n';
            }
            output << passed << '\\' << total << ": " << subOutput.str();
        } else {
            try {
                _test();
                output << '!' << _msg;
            } catch (std::exception e) {
                output << '?' << _msg << e.what();
                throw e;
            }
        }
        if (passed < total) throw std::runtime_error("not all tests passed");
    } 
    protected:
    virtual void _test() {}; //бросить исключение если что-то не так
    std::vector<std::unique_ptr<uTest>> _subTests = {};
    std::string _msg;
};