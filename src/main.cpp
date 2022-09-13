#include <cassert>
#include <exception>
#include <stdexcept>
#include <vector>

#include "finiteAutomata.hpp"
#include "uTest.hpp"

class copyConstrT : public uTest {
	void _test() override {
		
	}
	public:
	copyConstrT() {
		_msg = "Проверка конструктора копирования ";
	}
};

class swapT : public uTest {
	void _test() override {
		
	}
	public:
	swapT() {
		_msg = "Проверка функции swap ";
	}
};

class eqT : public uTest {
	void _test() override {
		
	}
	public:
	eqT() {
		_msg = "Проверка оператора равентва ";
	}
};

class eqTT : public uTest {
	public:
	eqTT() : uTest() {
		_msg = "Блок проверки присваиваний: ";
		_subTests.emplace_back(new eqT());
		_subTests.emplace_back(new swapT());
		_subTests.emplace_back(new copyConstrT());
	}
	void _test() {};
};

int main() {
	eqTT r;
	try {
		r.run();
	} catch (std::exception e) {
	} 
	std::cout << '\n';
	return 0;
} 