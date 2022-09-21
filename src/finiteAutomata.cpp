#include "finiteAutomata.hpp"

std::ostream& operator<< (std::ostream& stream, const finiteAutomata& r) {
    stream << r._automataSize << ' ' << r._alphabetSize << '\n';
    //for (auto i : r._nodes) {
    //   for (auto j : i.transitions) 
    //        stream << j << ' ';
    //    stream << '\n';   
    //}
    return stream;
};

std::istream& operator>> (std::istream& stream, finiteAutomata& r) {
    stream >> r._automataSize >> r._alphabetSize;
    r = finiteAutomata(r._automataSize, r._alphabetSize);
    //for (auto i : r._nodes) {
    //   for (auto j : i.transitions) 
    //        stream >> j;  
    //}
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