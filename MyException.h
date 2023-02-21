#pragma once
#include <iostream>
#include <string>

using namespace std;

class MyException //базовый класс 
{
protected:
	string Name;   //название проблемы
public:
	MyException(string name) { Name = name; }
	~MyException() {}
};


class IncorrectChoice : public MyException	//некорректный выбор
{
protected:
	double N1;
	double N2;
public:
	IncorrectChoice(string name = "Incorrect choice", double n1 = 0, double n2 = 7) :
		MyException(name), N1(n1), N2(n2) {}
	~IncorrectChoice() {}
	void Show()
	{
		cout << "\n\t" << Name;
		cout << "\n\t" << "You need to choose a number not less than " <<
			N1 << " and not more than " << N2 << endl;
	}
};

class IncorrectChoiceRange : public IncorrectChoice //некорректный выбор диапазон
{
public:
	IncorrectChoiceRange(string name = "Incorrect choice", double n1 = 0, double n2 = 7) :
		IncorrectChoice(name, n1, n2) {}
	~IncorrectChoiceRange() {}
	void Show()
	{
		cout << "\n\t" << Name;
		cout << "\n\t" << "You need to choose a number not less than " <<
			N1 << " and not more than " << N2 << endl;
	}
};

class IncorrectChoiceTwo : public IncorrectChoice //некорректный выбор 2 варианта
{
public:
	IncorrectChoiceTwo(string name = "Incorrect choice", double n1 = 0, double n2 = 7) :
		IncorrectChoice(name, n1, n2) {}
	~IncorrectChoiceTwo() {}
	void Show()
	{
		cout << "\n\t" << Name;
		cout << "\n\t" << "You need to choose a number " <<
			N1 << " or " << N2 << endl;
	}
};

class ErrorOpenFile : public MyException	//не удалось открыть файл
{
private:
	string NameFile;
public:
	ErrorOpenFile(string name = "Could not open file ", string n_file = "") :
		MyException(name), NameFile(n_file) {}
	~ErrorOpenFile() {}
	void Show() { cout << "\n\t" << Name << NameFile << "\n\n"; }
};

class ErrorMemoryAllocation : public MyException //ошибка распределения памяти
{
private:
	string NameVariable;
public:
	ErrorMemoryAllocation(string name = "Failed to create variable ", string n_var = "") :
		MyException(name), NameVariable(n_var) {}
	~ErrorMemoryAllocation() {}
	void Show() { cout << "\n\t" << Name << NameVariable << "\n\n"; }

};

class EntryEmpty : public MyException //запись пуста
{
private:
	string NameEntry;
public:
	EntryEmpty(string name = "Entry is empty ", string n_en = "") :
		MyException(name), NameEntry(n_en) {}
	~EntryEmpty() {}
	void Show() { cout << "\n\t" << Name << NameEntry << "\n\n"; }
};

class InvalidExpression : public MyException //некорректное выражение
{
private:
	string NameInvExpr;
public:
	InvalidExpression(string name = "Invalid Expression ", string n_en = "") :
		MyException(name), NameInvExpr(n_en) {}
	~InvalidExpression() {}
	void Show() { cout << "\n\t" << Name << NameInvExpr << "\n\n"; }
};

