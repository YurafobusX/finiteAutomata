#pragma once

#include <cstddef>
#include <stdexcept>
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

    finiteAutomata(size_t automataSize, size_t alphabetSize, std::vector<size_t>::iterator first, std::vector<size_t>::iterator last) : 
        _currentState(0),
        _alphabetSize(alphabetSize),
        _automataSize(automataSize) {
        size_t size = last - first;
        if (size < _alphabetSize * _automataSize) {
            _transitions = std::vector<size_t>(alphabetSize * automataSize, 0);
            throw std::out_of_range("not enough elements"); 
        } else
            _transitions = std::vector<size_t>(first, last);
    };

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

    void setCurrentState(size_t state) {
        if (state >= _automataSize) throw std::out_of_range("state doesn't exists in automata");
        _currentState = state;
    }

    std::vector<size_t> getTransitions() const {
        return _transitions;
    }

    size_t getTransition(size_t node, size_t letter) const {
        if (node >= _automataSize) throw std::out_of_range("node doesn't exists in automata");
        if (letter >= _alphabetSize) throw std::out_of_range("letter doesn't exists in automata");
        return _transitions[node * _alphabetSize + letter];
    }

    void setTransition(size_t node, size_t letter, size_t targetNode) {
        if (node >= _automataSize) throw std::out_of_range("node doesn't exists in automata");
        if (letter >= _alphabetSize) throw std::out_of_range("letter doesn't exists in automata");
        if (targetNode >= _automataSize) throw std::out_of_range("targetNode doesn't exists in automata");
        _transitions[node * _alphabetSize + letter] = targetNode; 
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