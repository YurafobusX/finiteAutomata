#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <random>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <algorithm>
#include <numeric>

#include "permutation.hpp"

class finiteAutomata {
    public:
    //блок конструкторов
    finiteAutomata(size_t automataSize = 0, size_t alphabetSize = 0, bool isRand = false);
    finiteAutomata(const finiteAutomata& aut);
    finiteAutomata(size_t automataSize, size_t alphabetSize, std::vector<size_t>::iterator first, std::vector<size_t>::iterator last);
    finiteAutomata(size_t automataSize, size_t alphabetSize, std::vector<size_t> tr);

    //блок функций
    size_t process(size_t letter);
        //Провертяет достижимость каждого состояния из from до какого-нибудь из to
    bool isReachable(std::vector<size_t> from, std::vector<size_t> to);
    bool isSync() const;

    //блок гетеров и сетеров
    size_t getAlphabetSize() const;
    size_t getAutomataSize() const;
    size_t getCurrentState() const;
    void setCurrentState(size_t state);
    std::vector<size_t> getTransitions() const;
    size_t getTransition(size_t node, size_t letter) const;
    void setTransition(size_t node, size_t letter, size_t targetNode);

    //блок операторов и friend
    finiteAutomata& operator=(finiteAutomata r);
    friend void swap(finiteAutomata& l, finiteAutomata& r);
    friend std::ostream& operator<< (std::ostream& stream, const finiteAutomata& r);
    friend std::istream& operator>> (std::istream& stream, finiteAutomata& r);

    private:
    //блок приватных функций
    void _calculateParentTransitions();

    //Поля
    size_t _currentState;
    size_t _alphabetSize;
    size_t _automataSize;
    std::vector<size_t> _transitions;
    std::vector<std::vector<size_t>> _parentTransitions = {};
    bool _isParentTransitionsCorrect = false;
};