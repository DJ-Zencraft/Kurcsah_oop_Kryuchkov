#pragma once
#include<string>
#include <iostream>


class Taxi   //Класс, описывающий студента
{
private:
    std::string num_tax;    //Номер Такси
    std::string fio;         //ФИО водителя
    std::string otprav; 
    std::string pribit;
    int cost;       //Группа
    int length;           //Курс
public:
    //Конструкторы класса
    Taxi();
    Taxi(const Taxi& obj);
    Taxi(const std::string& _num_tax, const std::string& _fio, const std::string& _otprav, const std::string& _pribit, int _cost , int _length);

    //Методы получения доступа к значениям полей класса
    std::string get_num_tax() const;
    std::string get_fio() const;
    std::string get_otprav() const;
    std::string get_pribit() const;
    int get_cost() const; 
    int get_length() const;

    //Методы для задания значений полей класса
    void set_num_tax(std::string new_num_tax);
    void set_fio(std::string new_fio);
    void set_otprav(std::string new_otprav);
    void set_pribit(std::string new_pribit);
    void set_cost(int new_cost);
    void set_length(int new_length);

    //Метод для вывода содержимого полей класса на экран
    void show() const;

};


