#define CATCH_CONFIG_RUNNER 
#include "catch.hpp"
#include "Stack.h"
#include <stack>
#include <iostream>

class test
{
	int val;
public:
	test& operator=(const test& a)
	{
		throw std::exception("teeeeeeeeeeeeeest");
	}
};

class test1
{
public:
	~test1()
	{
		throw std::exception();
	}
};

TEST_CASE("Checking push()")
{
	Stack<int> s;
	for (int i = 0; i < 10; i++)
	{
		s.push(i);
		REQUIRE(s.top() == i);
	}

	Stack<test> s1; //і перевірить калічний випадок
	test a;
	REQUIRE_THROWS(s1.push(a));
}

TEST_CASE("Cheking empty()")
{
	Stack<int> s;
	REQUIRE(s.empty() == true);
	s.push(1);
	REQUIRE(s.empty() == false);
}

TEST_CASE("Checking pop()")
{
	Stack<int> s;
	REQUIRE_THROWS(s.pop());
	for (int i = 0; i < 10; i++) s.push(i);
	for (int i = 9; i >0;i--)
	{
		s.pop();
		REQUIRE(s.top()==i-1);
	}
	
}

int main(int argc, char* argv[])
{
	/*test a;

	Stack<test> f;
	f.push(a);

	getchar();
	return 0;*/

	int result = Catch::Session().run(argc, argv);
	getchar();
	return result;
}
