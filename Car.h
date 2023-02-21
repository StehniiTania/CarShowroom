//Car.h
#pragma once
#include "MyException.h"
#pragma warning(disable : 4996)
#include <iostream>
#include <list>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

class Car
{
	string Avto;	//����� ����
	string Color;   //���� ����
	double Vol_Eng; //����� ���������
	int Year;		//��� �������
	int Mileage;    //������
	int Price;      //����	
	
public:
	Car();
	Car(string avto, string color, double vol, int year, int mileage, int price);
	~Car(){}

	Car(const Car& other); 
	Car& operator=(const Car& other); 
	void Show();  //�������� ���������� �� ����
	void Add(); //���������� ������
	
	bool SortBy(const Car& car1, const Car& car2)
	{
		return car1.Avto > car2.Avto;
	}
	string GetAvto() { return Avto; }
	double GetVolEng() { return Vol_Eng; }
	int GetYear() { return Year; }
	int GetMileage() { return Mileage; }
	int GetPrice() { return Price; }
	void SetAvto(string avto) { Avto = avto; }
};




