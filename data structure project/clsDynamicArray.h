#pragma once
#include<iostream>

using namespace std;
template <class T>
class clsDynamicArray
{
protected:
	int _Size = 0;
	T* _TempArray;

public:
	T* OriginalArray;
	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		OriginalArray = new T[_Size];

	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	};

	bool SetItem(int index, T value)
	{
		if (index >= _Size || index < 0)
			return false;

		OriginalArray[index] = value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size;
	}

	void PrintList()
	{
		for (int i= 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << "\n";
    }

	void Resize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];
		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
			_TempArray[i] = OriginalArray[i];

		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;

	}

	T GetItem(int index)
	{
		return OriginalArray[index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];

		for (int i = _Size - 1; i >= 0; i--)
			_TempArray[_Size - 1 - i] = OriginalArray[i];

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[]OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int index)
	{
		if (index >= _Size || index < 0)
			return false;

		_Size--;
		_TempArray = new T[_Size];

		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		for(int i=index+1;i<=_Size;i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == value)
				return i;
		}
		return -1;
	}

	bool DeleteItem(T value)
	{
		int index = Find(value);
		if (index == -1)
			return false;

		DeleteItemAt(index);
		return true;
	}

	bool InserAt(int index, T value)
	{
		if (index > _Size || index < 0)
		{
			return false;
		}
		_Size++;
		_TempArray = new T[_Size];
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		_TempArray[index] = value;
		for (int i = index; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = OriginalArray[i];
		}
		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void InsertAtBeginning(T value)
	{
		InserAt(0, value);
	}

	bool InsertBefore(T index, T value)
	{
		if (index < 0)
			return InserAt(0, value);
		else
			return InserAt(index-1, value);
	}
	bool InsertAfter(T index, T value)
	{
		if (index >=_Size )
			return InserAt(_Size-1, value);
		else
			return InserAt(index+1, value);
	}
	bool InsertAtEnd(T value)
	{
		return InserAt(_Size, value);
	}


};

