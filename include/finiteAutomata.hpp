#pragma once

#include <vector>
#include <random>
#include <iostream>

enum errorCodes {
    succsess,
    error
};

class finiteAutomata {
    public:

    finiteAutomata(size_t automataSize = 0, size_t alphabetSize = 0) : 
        _currentState(0),
        _alphabetSize(alphabetSize),
        _automataSize(automataSize),
        _nodes(std::vector<_node>(automataSize, {std::vector<size_t>(alphabetSize, 0)})) {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist(0, _automataSize - 1);    
            for (auto& i : _nodes) 
                for(size_t j = 0; j < _alphabetSize; j++)
                    i.transitions[j] = dist(rng);
    };

    finiteAutomata(const finiteAutomata& aut) : 
        _currentState(aut._currentState),
        _alphabetSize(aut._alphabetSize),
        _automataSize(aut._automataSize),
        _nodes(aut._nodes) {};

    errorCodes process(size_t letter) {
        _currentState = _nodes[_currentState].transitions[letter];
        return errorCodes::succsess;
    };

    size_t getCurrentState() {
        return _currentState;
    }

    friend void swap(finiteAutomata& l, finiteAutomata& r);

    private:
    size_t _currentState;
    size_t _alphabetSize;
    size_t _automataSize;
    struct _node {
        std::vector<size_t> transitions;
    }; 
    std::vector<_node> _nodes;
};