//Car.cpp
#include "Car.h"
Car::Car()
{	
	Avto = "";
	Color = "";     //цвет авто
	Vol_Eng = 0;    //объем двигателя
	Year = 0;		//год выпуска
	Mileage = 0;    //пробег
	Price = 0;      //цена	
}

Car::Car(string avto, string color, double vol, int year, int mileage, int price)
{
	Avto = avto;
	Color = color;
	Vol_Eng = vol;
	Year = year;
	Mileage = mileage;
	Price = price;
}

Car::Car(const Car& other)
{
	Avto = other.Avto;
	Color = other.Color;
	Vol_Eng = other.Vol_Eng;
	Year = other.Year;
	Mileage = other.Mileage;
	Price = other.Price;
}

Car& Car::operator=(const Car& other)
{
	if (&other == this) return *this;
	Avto = other.Avto;
	Color = other.Color;
	Vol_Eng = other.Vol_Eng;
	Year = other.Year;
	Mileage = other.Mileage;
	Price = other.Price;
	return *this;
}

void Car::Show()
{
	try
	{
		if (Avto == "") throw EntryEmpty("Entry is empty", "");
		cout << "\n\tМодель авто: " << Avto;
		cout << "\n\tЦвет: " << Color;
		cout << "\n\tОбъем двигателя: " << Vol_Eng;
		cout << "\n\tГод выпуска: " << Year;
		cout << "\n\tПробег: " << Mileage;
		cout << "\n\tЦена: " << Price << endl;
	}
	catch (EntryEmpty Ex)
	{ 	Ex.Show(); 	}	
}

void Car::Add()
{
	try
	{
		cout << "\n\tМодель авто: ";
		cin.ignore();
		getline(cin, Avto);
		cout << "\tЦвет: ";
		getline(cin, Color);
		while (100)
		{
			cout << "\n\tОбъем двигателя: ";
			cin >> Vol_Eng;
			if (Vol_Eng < 0.8 || Vol_Eng > 8)
				throw IncorrectChoiceRange("Incorrect choice", 0.8, 8);
			break;
		}
		
		while (100)
		{
			cout << "\tГод выпуска: ";
			cin >> Year;
			if (Year < 1900 || Year > 2021)			
				throw IncorrectChoiceRange("Incorrect choice", 1900, 2021);				
			break;
		}
		cout << "\tПробег: ";
		cin >> Mileage;
		cout << "\tЦена: ";
		cin >> Price;
	}
	catch (IncorrectChoiceRange Ex)
	{
		Ex.Show();	
		return Add();
	}	
	
}

//Car* Car::MakeCarRandom()
//{
//	Car* a1 = new Car;
//	string letter{ "WRTIOPASDFGHKJLZCVBNM" };
//	//string letter_ru{ "КНЕГШЗХФВАПРОЛДЖЯСМТБИ" };
//	string num{ "0123456789" };
//	//выбор рандомной модели авто
//	string avto[10]{ "Opel", "Renault", "BMW", "Toyota", "Mersedes",
//		"Volvo", "Mazda", "Nissan", "Audi", "Ford" };
//	a1->Avto = avto[rand() % 10] + " " + letter[rand() % 21] + letter[rand() % 21]
//		+ num[rand() % 10] + num[rand() % 10] + num[rand() % 10];
//	string color[10]{ "white", "black", "red", "blue", "grey",
//		"green", "beige", "silver", "khaki", "olive" };
//	a1->Color = color[rand() % 10];
//	string trans[2] = { "mehanical", "avto" };
//	a1->Trans = trans[rand() % 2];
//	a1->Year = rand() % 35 + 1985;
//	a1->Mileage = rand() % 200 * 1000 + 20000;
//	a1->Price = rand() % 500 * 100 + 50000;
//	
//	return a1;
//}
