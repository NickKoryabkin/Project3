#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


using namespace std;

struct Auto {
	string name,
		serial_number;
};

struct Date {
	int day,
		month,
		year;
};
struct Warehouse {
	string address;
	int number_of_warehouse;
};
struct Data {
	Auto _auto;
	Date _date;
	Warehouse _warehouse;
};
//Прототипы функций
void DataEntry(Data* (&d), int &n);//Ввод данных вручную
void ReadingData(Data* (&d), int& n, string filename);//Чтение данных
void Print(Data* d, int n);//Вывод данных
void DataChange(Data* (&d), int n);//Изменение данных
void DeleteData(Data* (&d),int &n);//Удаление данных
void AddData(Data* (&d),int &n);//Добавление данных
void SaveData(Data* d, int n, string filename);//Сохранение данных
void Copy(Data* (&d_n), Data* (&d_o), int n);//Копия данных