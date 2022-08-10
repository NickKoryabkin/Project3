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
//��������� �������
void DataEntry(Data* (&d), int &n);//���� ������ �������
void ReadingData(Data* (&d), int& n, string filename);//������ ������
void Print(Data* d, int n);//����� ������
void DataChange(Data* (&d), int n);//��������� ������
void DeleteData(Data* (&d),int &n);//�������� ������
void AddData(Data* (&d),int &n);//���������� ������
void SaveData(Data* d, int n, string filename);//���������� ������
void Copy(Data* (&d_n), Data* (&d_o), int n);//����� ������