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
}

finiteAutomata& finiteAutomata::operator=(finiteAutomata r) {
    swap(*this, r);
    return *this;
}