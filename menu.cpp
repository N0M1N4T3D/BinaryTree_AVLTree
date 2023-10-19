#include "Menu.h"
#include <iostream>
using namespace std;

int menu()
{
    system("cls");
    cout << "Что хотите сделать?" << endl;
    cout << "0. Выход" << endl;
    cout << "1. Вывести данные работника" << endl;
    cout << "2. Вывести личные данные работника" << endl;
    cout << "3. Добавить к зарплате работника" << endl;
    cout << "4. Отнять от зарплаты работника" << endl;
    cout << "5. Изменить должность работника" << endl;
    cout << "6. Вывести количество сотрудников" << endl;
    cout << "7. Назначить сотрудника на место другого" << endl;
    cout << "8. Добавить нового сотрудника" << endl;
    int a;
    cin >> a;
    return a;
}
