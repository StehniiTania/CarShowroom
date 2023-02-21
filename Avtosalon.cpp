// Avtosalon.cpp : Этот файл содержит функцию "main".
//Создайте приложение для работы автосалона.Необходимо хранить информацию
//о продаваемых автомобилях(название, год выпуска, объем двигателя, цену).
//Реализуйте интерфейс для добавления данных, удаления данных, отображения 
//данных, сортировке данных по различным параметрам, поиску данных по 
//различным параметрам.
//При реализации используйте контейнеры, функторы и алгоритмы.

#include "Menu.h"
#include <Windows.h>
using namespace std;

void ShowAvto(vector<Car>& avtoshop);
void AddAvto(vector<Car>& avtoshop);
void DelAvto(vector<Car>& avtoshop);
void SortAvto(vector<Car>& avtoshop);
void SearchAvto(vector<Car>& avtoshop);
void _Menu(vector<Item_Menu>& menu, vector<string> title, vector<Car>& avtoshop);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    //инициализация вектора "автомобили"
	vector<Car> Avtosalon
	{
		Car("Renault Kengo", "white", 1.4, 2000, 240000, 2900),
		Car("Volkswagen Passat B5", "black", 1.8, 1995, 180000, 4500),
		Car("Renault Megane scenic", "blue", 1.9, 2007, 135000, 8100),
		Car("VAZ 21063", "white", 1.6, 1985, 75000, 500),
		Car("Ford Fiesta", "blue", 1.4, 1995, 150000, 4000),
		Car("Opel Meriva", "grey", 1.6, 2001, 185000, 3000)
	};

    //инициализация вектора "главное меню"
    vector<Item_Menu> Main_Menu
    {
        Item_Menu("Вывод информации обо всех авто", ShowAvto, &Avtosalon),
        Item_Menu("Добавить авто", AddAvto, &Avtosalon),
        Item_Menu("Удалить авто", DelAvto, &Avtosalon),
        Item_Menu("Сортировка", SortAvto, &Avtosalon),
        Item_Menu("Поиск", SearchAvto, &Avtosalon)
    };

    //инициализация вектора для вывода заголовка меню
    vector<string> Title_Main
    {
        "\n\t Автосалон:",
        "\n\t ==========",
        "\n\tЧто вы хотите делать: \n"
    };
   
    _Menu(Main_Menu, Title_Main, Avtosalon);
}

void _Menu(vector<Item_Menu>& menu, vector<string> title, vector<Car>& avtoshop)
{
    system("cls");
    //проверка - не пустой ли вектор "меню"
    if (menu.size() == 0)
    {
        cout << "\n\tМассив <Меню> пуст\n";
        return;
    }
    //вывод меню на консоль
    for_each(title.begin(), title.end(), [](string str) {cout << str; });
    for (int i = 0; i < menu.size(); i++)
    {
        cout << "\n\t" << i + 1 << " " + menu[i].GetName();
    }
    cout << "\n\t" << menu.size() + 1 << " Exit\n\t";

    //выбор пункта меню
    int key;
    cin >> key;
    try

    {
        //если выбран пункт, не входящий в диапазон
        if (key < 1 || key > menu.size() + 1)
            throw IncorrectChoiceRange("Incorrect choice ",  
                1, (menu.size() + 1));
        //если выбран пункт "Exit"
        if (key == menu.size() + 1)
        {
           // ShowAvto(avtoshop);
           // system("pause");
            return;
        }

        //если выбран один из пунктов меню, запускается соответствующая функция
        menu[key - 1].Start_Fun();
        cout << "\n\t";
        system("pause");
        _Menu(menu, title, avtoshop);

    }
    catch (IncorrectChoiceRange Ex)
    {
        Ex.Show();
        system("pause");
        _Menu(menu, title, avtoshop);
    }
}

void ShowAvto(vector<Car>& avtoshop)
{
    for_each(avtoshop.begin(), avtoshop.end(), [](Car car) {car.Show(); });   
}
      
void AddAvto(vector<Car>& avtoshop)
{
    Car C1;
    C1.Add();
    int k = avtoshop.size();
    avtoshop.resize(k + 1);
    avtoshop[k] = C1;
    for (int i = 0; i < k + 1; i++) avtoshop[i].Show();
}

void DelAvto(vector<Car>& avtoshop)
{
    string avto;
    bool flag_search = false;
    int key;
    cout << "\n\tВведите модель авто, которое Вы хотите удалить: ";
    cin.ignore();
    getline(cin, avto);
    for (int i = 0; i < avtoshop.size(); i++)
    {
        string s = avtoshop[i].GetAvto();
        if (s.find(avto) >= 0 && s.find(avto) < s.size())
        {
            avtoshop[i].Show();
            cout << "\n\tВы действительно хотите удалить эту запись? Да - 1, Нет - 0 ";
            cin >> key;
            if (key == 1) avtoshop.erase(avtoshop.begin() + i);
            flag_search = true;
        }
    }
    if (flag_search == false) cout << "\n\tЗапись не найдена";

}

void SortAvto(vector<Car>& avtoshop)
{
    auto Sort_Avto = [&](vector<Car>& avtoshop)
    {
        sort(avtoshop.begin(), avtoshop.end(),
            [&](Car c1, Car c2) {return c1.GetAvto() < c2.GetAvto(); });
        cout << "\n\tСортировка окончена\n\t";
        ShowAvto(avtoshop);
    };   
    auto Sort_VolEng = [&](vector<Car>& avtoshop)
    {
        sort(avtoshop.begin(), avtoshop.end(),
            [&](Car c1, Car c2) {return c1.GetVolEng() < c2.GetVolEng(); });
        cout << "\n\tСортировка окончена\n\t";
        ShowAvto(avtoshop);
    };
    auto Sort_Year = [&](vector<Car>& avtoshop)
    {
        sort(avtoshop.begin(), avtoshop.end(),
            [&](Car c1, Car c2) {return c1.GetYear() < c2.GetYear(); });
        cout << "\n\tСортировка окончена\n\t";
        ShowAvto(avtoshop);
    };
    auto Sort_Mileage = [&](vector<Car>& avtoshop)
    {
        sort(avtoshop.begin(), avtoshop.end(),
            [&](Car c1, Car c2) {return c1.GetMileage() < c2.GetMileage(); });
        cout << "\n\tСортировка окончена\n\t";
        ShowAvto(avtoshop);
    };         
    auto Sort_Price = [&](vector<Car>& avtoshop)
    {
        sort(avtoshop.begin(), avtoshop.end(),
            [&](Car c1, Car c2) {return c1.GetPrice() < c2.GetPrice(); });
        cout << "\n\tСортировка окончена\n\t";
        ShowAvto(avtoshop);
    };
      
    vector<string> Title_sort
    {
       "\n\t Выберите способ сортировки:",
       "\n\t ==========================="
    };

    vector<Item_Menu> Sort_Menu
    {
        Item_Menu("По модели авто", Sort_Avto, &avtoshop),
        Item_Menu("По объему двигателя", Sort_VolEng, &avtoshop),
        Item_Menu("По году выпуска", Sort_Year, &avtoshop),
        Item_Menu("По пробегу", Sort_Mileage, &avtoshop),
        Item_Menu("По цене", Sort_Price, &avtoshop)
    };

    _Menu(Sort_Menu, Title_sort, avtoshop);

}

void SearchAvto(vector<Car>& avtoshop)
{
    auto Search_Avto = [&](vector<Car>&)
    {
        cout << "\n\tВведите модель авто: ";
        string avto;
        cin.ignore();
        getline(cin, avto);
        vector<Car> temp;
        Car a2;
        copy_if(avtoshop.begin(), avtoshop.end(), back_inserter(temp), [&](Car& car)
            {
                string s = car.GetAvto();
                return (s.find(avto) >= 0 && s.find(avto) < s.size());
            });
        if (!temp.empty()) ShowAvto(temp);
        else cout << "\n\tЗапись не найдено!\n\t";
    };
    auto Search_Year = [&](vector<Car>&)
    {
        cout << "\n\tВведите год выпуска авто - не более: ";
        int year;
        cin >> year;
        vector<Car> temp;
        copy_if(avtoshop.begin(), avtoshop.end(), back_inserter(temp), [&](Car& car)
            {
                return car.GetYear() <= year;
            });
        if (!temp.empty()) ShowAvto(temp);
        else cout << "\n\tЗапись не найдено!\n\t";
    };
    auto Search_Mileage = [&](vector<Car>&)
    {
        cout << "\n\tВведите пробег - не более: ";
        int mileage;
        cin >> mileage;
        vector<Car> temp;
        copy_if(avtoshop.begin(), avtoshop.end(), back_inserter(temp), [&](Car& car)
            {
                return car.GetMileage() <= mileage;
            });
        if (!temp.empty()) ShowAvto(temp);
        else cout << "\n\tЗапись не найдено!\n\t";
    };
    auto Search_Price = [&](vector<Car>&)
    {
        cout << "\n\tВведите цену - не более: ";
        int price;
        cin >> price;
        vector<Car> temp;
        copy_if(avtoshop.begin(), avtoshop.end(), back_inserter(temp), [&](Car& car)
            {
                return car.GetPrice() <= price;
            });
        if (!temp.empty()) ShowAvto(temp);
        else cout << "\n\tЗапись не найдено!\n\t";
    };
    vector<string> Title_Search
    {
        "\n\t Выберите способ поиска:",
        "\n\t ======================="
    };
    vector<Item_Menu> Search_Menu
    {
       Item_Menu("По модели авто", Search_Avto, &avtoshop),
       Item_Menu("По году выпуска", Search_Year, &avtoshop),
       Item_Menu("По пробегу", Search_Mileage, &avtoshop),
       Item_Menu("По цене", Search_Price, &avtoshop)
    };

    _Menu(Search_Menu, Title_Search, avtoshop);
}



