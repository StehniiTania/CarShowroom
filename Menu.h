//Menu.h

#pragma once
#include <functional>
#include <vector>
#include <algorithm>
#include "Car.h"

using namespace std;
using std::function;

class Item_Menu
{	
	string Name_Item;
	function<void(vector<Car>&)> Function;
	vector<Car>* VectorCar;
public:
	Item_Menu(string name, function<void(vector<Car>&)> func, vector<Car>* pvCar)
	{
		Name_Item = name; Function = func;  VectorCar = pvCar;
	}
	~Item_Menu() {}
	string GetName() { return Name_Item; }
	void Start_Fun() {	Function(*VectorCar);   }	
};