#include "finiteAutomata.hpp"

std::ostream& operator<< (std::ostream& stream, const finiteAutomata& r) {
    stream << r._automataSize << ' ' << r._alphabetSize << '\n';
    for (auto i : r.getTransitions()) {
        stream << i << ' ';  
    }
    return stream;
};

std::istream& operator>> (std::istream& stream, finiteAutomata& r) {
    stream >> r._automataSize >> r._alphabetSize;
    r = finiteAutomata(r._automataSize, r._alphabetSize);
    for (size_t i = 0; i < r._automataSize; i++) {
        for (size_t j = 0; j < r._alphabetSize; j++) {
            size_t b;
            stream >> b;
            r.setTransition(i, j, b);
        }
    }
    return stream;
}

void swap(finiteAutomata& l, finiteAutomata& r) {
    std::swap(l._automataSize, r._automataSize);
    std::swap(l._alphabetSize, r._alphabetSize);
    std::swap(l._currentState, r._currentState);
    std::swap(l._transitions, r._transitions);
    std::swap(l._isParentTransitionsCorrect, r._isParentTransitionsCorrect);
    std::swap(l._parentTransitions, r._parentTransitions);
}

finiteAutomata& finiteAutomata::operator=(finiteAutomata r) {
    swap(*this, r);
    return *this;
}

void finiteAutomata::setTransition(size_t node, size_t letter, size_t targetNode) {
    if (node >= _automataSize) throw std::out_of_range("node doesn't exists in automata");
    if (letter >= _alphabetSize) throw std::out_of_range("letter doesn't exists in automata");
    if (targetNode >= _automataSize) throw std::out_of_range("targetNode doesn't exists in automata");
    _transitions[node * _alphabetSize + letter] = targetNode; 
    _isParentTransitionsCorrect = false;
}

void finiteAutomata::setCurrentState(size_t state) {
    if (state >= _automataSize) throw std::out_of_range("state doesn't exists in automata");
    _currentState = state;
}

std::vector<size_t> finiteAutomata::getTransitions() const {
    return _transitions;
}

size_t finiteAutomata::getTransition(size_t node, size_t letter) const {
    if (node >= _automataSize) throw std::out_of_range("node doesn't exists in automata");
    if (letter >= _alphabetSize) throw std::out_of_range("letter doesn't exists in automata");
    return _transitions[node * _alphabetSize + letter];
}

size_t finiteAutomata::process(size_t letter) {
    return _currentState = getTransition(_currentState, letter);
};

    
size_t finiteAutomata::getAlphabetSize() const{
    return _alphabetSize;
};

size_t finiteAutomata::getAutomataSize() const{
    return _automataSize;
};

finiteAutomata::finiteAutomata(size_t automataSize, size_t alphabetSize, bool isRand) : 
    _currentState(0),
    _alphabetSize(alphabetSize),
    _automataSize(automataSize),
    _transitions(alphabetSize * automataSize, 0) {
        if (!isRand) return;
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, _automataSize - 1);    
        for (auto& i : _transitions)
            i = dist(rng);
    };

finiteAutomata::finiteAutomata(const finiteAutomata& aut) : 
    _currentState(aut._currentState),
    _alphabetSize(aut._alphabetSize),
    _automataSize(aut._automataSize),
    _transitions(aut._transitions),
    _parentTransitions(aut._parentTransitions),
    _isParentTransitionsCorrect(aut._isParentTransitionsCorrect) {};

finiteAutomata::finiteAutomata(size_t automataSize, size_t alphabetSize, std::vector<size_t>::iterator first, std::vector<size_t>::iterator last) : 
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
