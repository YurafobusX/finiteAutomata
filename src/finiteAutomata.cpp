#include "finiteAutomata.hpp"


std::ostream& operator<< (std::ostream& stream, const finiteAutomata& r) {
    stream << r._automataSize << ' ' << r._alphabetSize << '\n';
    for (auto i : r._nodes) {
        for (auto j : i.transitions) 
            stream << j << ' ';
        stream << '\n';   
    }
    return stream;
};

std::istream& operator>> (std::istream& stream, finiteAutomata& r) {
    stream >> r._automataSize >> r._alphabetSize;
    for (auto i : r._nodes) {
        for (auto j : i.transitions) 
            stream >> j;  
    }
    return stream;
}