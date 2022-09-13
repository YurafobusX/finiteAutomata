#include "finiteAutomata.hpp"

void swap(finiteAutomata& l, finiteAutomata& r) {
    std::swap(l._automataSize, r._automataSize);
    std::swap(l._alphabetSize, r._alphabetSize);
    std::swap(l._currentState, r._currentState);
    std::swap(l._nodes, r._nodes);
}

finiteAutomata& finiteAutomata::operator=(finiteAutomata r) {
    swap(*this, r);
    return *this;
}