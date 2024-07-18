#pragma once
#include <iostream>
#include"clsMyQueue.h"

using namespace std;
template<class T>
class clsMyStack:public clsMyQueue<T>
{
	
public:
	void push(T value)
	{
		clsMyQueue <T>::_MyList.InsetAtBeginning(value);
	}

	T Top()
	{
		return clsMyQueue <T>::front();
	}

	T Bottom()
	{
		return clsMyStack<T>::back();
	}
};

