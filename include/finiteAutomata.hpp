#pragma once

#include <cstddef>
#include <vector>
#include <random>
#include <iostream>
#include <sstream>

class finiteAutomata {
    public:
    //блок конструкторов
    finiteAutomata(size_t automataSize = 0, size_t alphabetSize = 0) : 
        _currentState(0),
        _alphabetSize(alphabetSize),
        _automataSize(automataSize),
        _transitions(alphabetSize * automataSize, 0) {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist(0, _automataSize - 1);    
            for (auto& i : _transitions)
                i = dist(rng);
    };

    finiteAutomata(const finiteAutomata& aut) : 
        _currentState(aut._currentState),
        _alphabetSize(aut._alphabetSize),
        _automataSize(aut._automataSize),
        _transitions(aut._transitions) {};

    finiteAutomata(std::vector<size_t>::iterator bgn, std::vector<size_t>::iterator end) {
        size_t size = end - bgn;
        if (size < 2) throw std::out_of_range("not enough elements");
        _automataSize = *(bgn++);
        _alphabetSize = *(bgn++);
        if (size != 2 + _alphabetSize * _alphabetSize) throw std::out_of_range("not matching sizes of containers");
        _currentState = 0;
        _transitions.resize(_alphabetSize * _alphabetSize);
        for (size_t i = 0; i < _alphabetSize * _alphabetSize && bgn != end; i++) {
            _transitions[i] = *(bgn++);
        }
    } 

    /*template<class Iter>
    finiteAutomata(Iter bgn, Iter end) : finiteAutomata((size_t)*(bgn++), (size_t)*(bgn++)) {
        while (bgn != end) {
            (void)bgn;
            (void)end;
            ++bgn;
        }
    };*/


    //блок функций
    size_t process(size_t letter) {
        return _currentState = getTransition(_currentState, letter);
    };

    //блок гетеров и сетеров
    size_t getAlphabetSize() const{
        return _alphabetSize;
    };

    size_t getAutomataSize() const{
        return _automataSize;
    };

    size_t getCurrentState() const{
        return _currentState;
    };

    size_t getTransition(size_t node, size_t letter) const {
        (void)node;
        (void)letter;
        return 0;
    }

    void setTransition(size_t node, size_t letter, size_t targetNode) {
        (void)node;
        (void)letter;
        (void)targetNode;
    }


    //блок операторов и friend
    finiteAutomata& operator=(finiteAutomata r);

    friend void swap(finiteAutomata& l, finiteAutomata& r);
    
    friend std::ostream& operator<< (std::ostream& stream, const finiteAutomata& r);
    friend std::istream& operator>> (std::istream& stream, finiteAutomata& r);

    private:
    size_t _currentState;
    size_t _alphabetSize;
    size_t _automataSize;
    std::vector<size_t> _transitions;
};