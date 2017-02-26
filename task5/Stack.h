#pragma once
#include <vector>
#include <iostream>
#include <exception>

template <typename T>
class Stack
{
	struct element
	{
		T val;
		element* next = nullptr;
		~element()
		{
			delete next;
		};
	};

	element* _top;
public:
	Stack() : _top{ nullptr }
	{};
	~Stack()
	{
		delete _top;
	};

	bool empty()
	{
		if (_top) return false;
		return true;
	}

	void push(const T& val)
	{
		if (!_top)
		{
			_top = new element;
			_top->next = nullptr;
			try{
				_top->val = val;
			}
			catch (std::exception& e)
			{
				try{
					delete _top;
				}
				catch(std::exception& ee)
				{
					_top = nullptr;
				}
				_top = nullptr;
				throw;
			}
		}
		else
		{
			element* temp = new element;
			try{
				temp->val = val;
			}
			catch (std::exception& e)
			{
				delete temp; 
				throw;
			}
			temp->next = _top;
			_top = temp;
		}
	}

	T& top()
	{
		if (!_top) throw std::exception();
		return _top->val;
	}

	void pop()
	{
		if (!_top) throw std::exception();
		element* temp = _top->next;
		_top->next = nullptr;
		try{
			delete _top; //may throw
		}
		catch (std::exception& e)
		{
			_top = temp;
			throw;
		}
		_top = temp;
	}
	
};

