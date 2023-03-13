#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <Windows.h>
#include "Taxi.h"
using namespace std;

//Вектор, содержащий объекты класса Taxi
vector<Taxi> List;

void menu();        //Функция прорисовки меню
void hline();       //Функция, рисующая горизонтальную линию

//Функции-компараторы для разных полей объекта класса Taxi
bool comp_tax(Taxi a, Taxi b);
bool comp_fio(Taxi a, Taxi b);
bool comp_otprav(Taxi a, Taxi b);
bool comp_pribit(Taxi a, Taxi b);
bool comp_cost(Taxi a, Taxi b);
bool comp_length(Taxi a, Taxi b);
//Функция для поиска данных по Номеру такси
int find(vector<Taxi>L, string key);
void vvod(vector<Taxi>& L);      //Функция ввода данных
void edit(vector<Taxi>& L);      //Функция редактирования данных
void vivod(vector<Taxi>L); 
void nomer(vector<Taxi>L); //Функция вывода данных
void dlina(vector<Taxi>L);      //Функция поиска данных
void sred(vector<Taxi>L);//void sortirovka(vector<Taxi>L);  //Функция сортировки
void del(vector<Taxi>& L);       //Функция удаления данных

//Главная функция программы
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 0;
    //Цикл обработки действий пользователя
    while (n != 8)
    {
        menu();
        cin >> n;
        switch (n)
        {
        case 1: vvod(List); break;
        case 2: vivod(List); break;
        case 3: edit(List); break;
        case 4: nomer(List); break;
        case 5: dlina(List); break;
        case 6: sred(List); break;
        case 7: del(List); break;
        case 8: break;
        default: cout << "Неверный вариант выбора" << endl;
        }
    }

}

//Реализация функции прорисовки меню
void menu()
{
    cout << endl << "      МЕНЮ     " << endl;
    cout << "1. Ввод данных" << endl;
    cout << "2. Вывод данных" << endl;
    cout << "3. Редактирование данных" << endl;
    cout << "4. Вывод такси по номеру  " << endl;
    cout << "5. Вывод самых протяжных маршрутов " << endl;
    cout << "4. Вывод среднего чека по заказам " << endl;
    cout << "7. Удаление данных" << endl;
    cout << "8. Выход" << endl;
    cout << "Введите номер пункта меню для дальнейшей работы" << endl;
}

//Реализация функции поиска элемента по ключу
int find(vector<Taxi>L, string key) {
    for (int i = 0; i < L.size(); i++)
    {
        if (L[i].get_num_tax() == key)
        {
            return i;
        }
    }
    return -1;
}

//Функция-компаратор для сортировки вектора по номеру такси
bool comp_num_tax(Taxi a, Taxi b)
{
    return a.get_num_tax() < b.get_num_tax();
}

//Функция-компаратор для сортировки вектора по ФИО таксиста
bool comp_fio(Taxi a, Taxi b)
{
    return a.get_fio() < b.get_fio();
}

//Функция-компаратор для сортировки вектора по пункту отправления
bool comp_otprav(Taxi a, Taxi b)
{
    return a.get_otprav() < b.get_otprav();
}

bool comp_pribit(Taxi a, Taxi b)
{
    return a.get_pribit() < b.get_pribit();
}

//Функция-компаратор для сортировки вектора по пункту прибытия
bool comp_cost(Taxi a, Taxi b)
{
    return a.get_cost() < b.get_cost();
}

bool comp_length(Taxi a, Taxi b)
{
    return a.get_length() < b.get_length();
}

//Реализация функции ввода данных
void vvod(vector<Taxi>& L)
{

    char choise;        //Переменная для запоминания выбора пользователя
    string num_tax, fio, otprav, pribit;   //Переменные для заполнения данных такси
    int cost, length;

    while (true)
    {
        cout << "Введите номер такси" << endl;
        while (cin.get() != '\n');
        getline(cin, num_tax);
        cout << "Введите Фамилию таксисита " << endl;
        getline(cin, fio);
        cout << "Введите пункт отправления" << endl;
        getline(cin, otprav);
        cout << "Введите пункт прибытия" << endl;
        getline(cin, pribit);
        cout << "Введите цену " << endl;
        cin >> cost;
        cout << "Введите протяжённость маршрута (в метрах) " << endl;
        cin >> length;
        //Добавление нового элемента в вектор
        L.push_back(Taxi(num_tax, fio, otprav, pribit, cost, length));
        //Запрос подтверждения на ввод новой записи
        while (true)
        {
            cout << "Продолжить ввод? Введите д - если да, н - если нет" << endl;
            cin >> choise;
            //Программа находится в режиме ожидания, пока пользователь не введет 'д' или 'н'
            if (choise == 'д' || choise == 'н') break;
        }
        //Если пользователь ввел 'н', то выходим из цикла
        if (choise == 'н') break;
    }
}

//Реализация функции вывода данных
void vivod(vector<Taxi>L)
{
    //Прорисовка шапки таблицы
    cout << "          Такси          " << endl;
    hline();
    cout << "|   Номер машины   |  Фамилия таксисита  | Пункт отправления |   Пункт прибытия   | Стоимость |Протяжённость (в метрах)|" << endl;
    hline();
    //Вывод на экран элементов вектора
    for (int i = 0; i < L.size(); i++)
    {
        cout << "| " << setw(16) << L[i].get_num_tax();
        cout << " | " << setw(19) << L[i].get_fio();
        cout << " | " << setw(17) << L[i].get_otprav();
        cout << " | " << setw(18) << L[i].get_pribit();
        cout << " | " << setw(9) << L[i].get_cost();
        cout << " | " << setw(22) << L[i].get_length() << " |" << endl;
    }
    hline();
}

//Реализация функции редактирования элемента вектора
void edit(vector<Taxi>& L)
{
    //Переменные для заполнения данных о такси
    string num_tax;
    string fio, otprav,pribit;
    int cost,length;
    cout << "Введите номер машины для поиска" << endl;
    while (cin.get() != '\n');
    getline(cin, num_tax);
    //Поиск по номеру машины в векторе
    int ind = find(L, num_tax);
    //Если нашлась машина  - вывод найденных сведений и
    //предложение отредактировать нужные поля
    if (ind != -1)
    {
        cout << endl << "Данные найдены" << endl;
        L[ind].show();
        cout << endl << "Введите новый номер машины или 0, если хотите оставить старый" << endl;
        getline(cin, num_tax);
        if (num_tax != "0")
            L[ind].set_num_tax(num_tax);
        cout << "Введите новую фамилию или 0, если хотите оставить старые данные" << endl;
        getline(cin, fio);
        if (fio != "0")
            L[ind].set_fio(fio);
        cout << "Введите новый пункт назначения или 0, если хотите оставить старое" << endl;
        getline(cin, otprav);
        if (otprav != "0")
            L[ind].set_otprav(otprav);
        cout << "Введите новый пункт прибытия или 0, если хотите оставить старое" << endl;
        getline(cin, pribit);
        if (pribit != "0")
            L[ind].set_otprav(pribit);
        cout << "Введите новую стоимость  или 0, если хотите оставить старую" << endl;
        cin >> cost;
        if (cost != 0)
            L[ind].set_cost(cost);
        cout << "Введите новое расстояние маршрута  или 0, если хотите оставить старую" << endl;
        cin >> length;
        if (length != 0)
            L[ind].set_cost(length);
        cout << endl << "Редактирование окончено" << endl;
    }
    else
        cout << "Данные для редактирования не найдены" << endl;

}

void nomer(vector<Taxi>L)
{
    string numb;
    cout << "Введите номер или часть номера для поиска" << endl;
    while (cin.get() != '\n');
    getline(cin, numb);
    cout << endl << "Результаты поиска:" << endl;
    for (int i = 0; i < L.size(); i++)
    {
        string numb_st = L[i].get_num_tax();
        if (numb_st.find(numb) != numb_st.npos) //npos - максимально возможная позиция символа в строке +1
            L[i].show();
    }
}


//Реализация функции поиска по большему расстоянию
void dlina(vector<Taxi>L)
{
    int length;
    cout << "Введите минимальное расстояние" << endl;
    //while (cin.get() != '\n');
    cin >> length;
    cout << endl << "Результаты поиска:" << endl;
    for (int i = 0; i < L.size(); i++)
    {
        int length_st = L[i].get_length();
        //Поиск введеной пользователем расстояния 
        
        if (length_st > length)
            L[i].show();
    }
}

void sred(vector<Taxi>L)
{
    int cst=0;
    int j = 0;
    cout << "Средний чек по всем заказам: " << endl;
    for (int i = 0; i < L.size(); i++)
    {
        cst += L[i].get_cost();
        j++;
    }
    cout << "Результат:  " << cst / j << endl;
}


//Реализация функции удаления элемента из вектора
void del(vector<Taxi>& L)
{
    string key;
    cout << "Введите номер машины для поиска" << endl;
    while (cin.get() != '\n');
    getline(cin, key);
    int ind = find(L, key);
    if (ind != -1)
    {
        //В методе erase() требуется указать начало вектора
        //плюс смещение до удаляемого элемента
        L.erase(L.begin() + ind);
        cout << "Машина удалена" << endl;
    }
    else
        cout << "Данные для удаления не найдены" << endl;
}

//Функция прорисовки горизонтальной линии
void hline() {
    const int m = 119;
    for (int i = 0; i < m; i++)
        cout << "-";
    cout << endl;
}
