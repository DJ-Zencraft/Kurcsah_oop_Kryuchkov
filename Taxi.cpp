//Taxi

#include "Taxi.h"

using namespace std;

//Реализация конструкторов
Taxi::Taxi() : cost(0) {}
Taxi::Taxi(const Taxi& obj) : num_tax(obj.num_tax), fio(obj.fio), otprav(obj.otprav), pribit(obj.pribit), cost(obj.cost), length(obj.length) {}
Taxi::Taxi(const string& _num_tax, const string& _fio, const string& _otprav, const string& _pribit, int _cost, int _length) : num_tax(_num_tax), fio(_fio), otprav(_otprav),pribit(_pribit), cost(_cost),length (_length) {}

//Реализация методов получения доступа к значениям полей класса
string Taxi::get_num_tax() const { return num_tax; }
string Taxi::get_fio() const { return fio; };
string Taxi::get_otprav() const { return otprav; };
string Taxi::get_pribit() const { return pribit; };
int Taxi::get_cost() const { return cost; };
int Taxi::get_length() const { return length; };

//Реализация методов для задания значений полей класса
void Taxi::set_num_tax(string new_num_tax) { num_tax = new_num_tax; }
void Taxi::set_fio(string new_fio) { fio = new_fio; };
void Taxi::set_otprav(string new_otprav) { otprav = new_otprav; };
void Taxi::set_pribit(string new_pribit) { pribit = new_pribit; };
void Taxi::set_cost(int new_cost) { cost = new_cost; };
void Taxi::set_length(int new_length) { length = new_length; };

//Реализация метода для вывода содержимого полей класса на экран
void Taxi::show()  const {
    cout << "Номер машины : " << num_tax << endl;
    cout << "Фамилия таксиста : " << fio << endl;
    cout << "Пункт отправления : " << otprav << endl;
    cout << "Пункт прибытия : " << pribit << endl;
    cout << "Стоимость поездки : " << cost << endl;
    cout << "Протяжённость маршрута : " << length << endl << endl;
}
