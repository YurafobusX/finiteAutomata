#include <cassert>
#include <exception>
#include <stdexcept>
#include <vector>
#include <set>

#define BOOST_TEST_MODULE your_test_module
#include <boost/test/included/unit_test.hpp>
#include "finiteAutomata.hpp"

BOOST_AUTO_TEST_CASE( Проверка_конструктора_копирования ) {
	
}

BOOST_AUTO_TEST_CASE( Проверка_функции_swap ) {
	
}

BOOST_AUTO_TEST_CASE( Проверка_оператора_равентва ) {
	
}

BOOST_AUTO_TEST_CASE( Проверка_на_ввод ) {
	std::stringstream s("2 1 1 0");
		finiteAutomata a;
		s >> a;
		BOOST_TEST(a.getAutomataSize() == 2);
		BOOST_TEST(a.getAlphabetSize() == 1);
		BOOST_TEST(a.process(0) == 1 );
}

BOOST_AUTO_TEST_CASE( Провекра_на_корректный_вывод ) {
	
}

BOOST_AUTO_TEST_CASE( your_test_case ) {
    std::vector<int> a{1, 2};
    std::vector<int> b{1, 2};
    BOOST_TEST( a == b );
}