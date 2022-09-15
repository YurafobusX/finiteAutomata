#include <cassert>
#include <exception>
#include <stdexcept>
#include <vector>
#include <set>

#include "finiteAutomata.hpp"
#include "uTest.hpp"

class copyConstrT : public uTest {
	void _test() override {
		
	}
	public:
	copyConstrT() {
		_msg = "Проверка конструктора копирования: ";
	}
};

class swapT : public uTest {
	void _test() override {
		throw std::runtime_error("test");
	}
	public:
	swapT() {
		_msg = "Проверка функции swap: ";
	}
};

class eqT : public uTest {
	void _test() override {
		
	}
	public:
	eqT() {
		_msg = "Проверка оператора равентва: ";
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
};

class inputT : public uTest {
	void _test() override {
		std::set<int> a = {1,2};
		std::vector<int> b(a.begin(), a.end());
	}
	public:
	inputT() : uTest() {
		_msg = "Проверка на вход: ";
	}
};

class outputT : public uTest {
	void _test() override {
		std::set<int> a = {1,2};
		std::vector<int> b(a.begin(), a.end());
	}
	public:
	outputT() : uTest() {
		_msg = "Провекра на корректный вывод: ";
	}
};

class ioTT : public uTest {
	public:
	ioTT() : uTest() {
		_msg = "Блок тестов на ввод/вывод: ";
		_subTests.emplace_back(new outputT);
	}
};

class rootT : public uTest {
	public:
	rootT() : uTest() {
		_msg = "Начало тестов: ";
		_subTests.emplace_back(new eqTT());
		_subTests.emplace_back(new ioTT());
	}
};

int main() {
	rootT r;
	std::stringstream s;
	try {
		r.run();
	} catch (std::exception& e) {
	} 
	std::cout << '\n';
	return 0;
} 