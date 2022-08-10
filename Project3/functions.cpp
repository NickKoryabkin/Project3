#include "functions.h"

void DataEntry(Data* (&d), int& n)
{
	cout << "������� ���������� ������: ";
	cin >> n;
	d = new Data[n];
	for (int i = 0; i < n; i++) {
		cout << "������� ��������, �������� �����: ";
		cin >> d[i]._auto.name;
		cin >> d[i]._auto.serial_number;
		cout << "������� ���� ����������� �� �����: ";
		cin >> d[i]._date.day;
		cin >> d[i]._date.month;
		cin >> d[i]._date.year;
		while (d[i]._date.day < 1 or d[i]._date.day > 31 or d[i]._date.month < 1 or d[i]._date.month > 12 or d[i]._date.year < 1950 or d[i]._date.year > 2100) {
			cout << "������� ���� ����������� �� ����� ���������: ";
			cin >> d[i]._date.day;
			cin >> d[i]._date.month;
			cin >> d[i]._date.year;
		}
		cout << "�����, ����� ������: ";
		cin >> d[i]._warehouse.address;
		cin >> d[i]._warehouse.number_of_warehouse;
		cout << "______________________________" << endl;
	}
}

void ReadingData(Data* (&d), int& n, string filename)
{
	ifstream reading(filename);
	if (reading) {
		reading >> n;
		d = new Data[n];
		for (int i = 0; i < n; i++) {
			reading >> d[i]._auto.name;
			reading >> d[i]._auto.serial_number;
			reading >> d[i]._date.day;
			reading >> d[i]._date.month;
			reading >> d[i]._date.year;
			reading >> d[i]._warehouse.address;
			reading >> d[i]._warehouse.number_of_warehouse;
		}
		cout << "������ �������!" << endl;
	}
	else {
		cout << "������ �������� �����!" << endl;
	}
	reading.close();
}

void Print(Data* d, int n)
{
	for (int i = 0; i < n; i++) {
		cout << "������ � " << i + 1 << ": " << endl;
		cout << "��������, �������� �����: " << d[i]._auto.name << " " << d[i]._auto.serial_number << endl;
		cout << "���� ����������� �� �����: " << d[i]._date.day << " " << d[i]._date.month << " " << d[i]._date.year << endl;
		cout << "����� ������: " << d[i]._warehouse.address << endl;
		cout << "����� ������: " << d[i]._warehouse.number_of_warehouse << endl;
		cout << "______________________________________" << endl;
	}
}

void DataChange(Data* (&d), int n)
{
	int _n;
	cout << "������� ����� �������� (�� 1 �� "<<n<<"): ";
	cin >> _n;
	_n--;
	
	if (_n >= 0 && _n < n) {
		cout << "��������, �������� �����: ";
		cin >> d[_n]._auto.name;
		cin >> d[_n]._auto.serial_number;
		cout << "������� ���� ����������� �� �����: ";
		cin >> d[_n]._date.day;
		cin >> d[_n]._date.month;
		cin >> d[_n]._date.year;
		while ((d[_n]._date.day > 1) or (d[_n]._date.day > 31) or (d[_n]._date.month < 1) or (d[_n]._date.month > 12) or (d[_n]._date.year < 1950) or (d[_n]._date.year > 2100)) {
			cout << "������� ���� ����������� �� ����� ���������: ";
			cin >> d[_n]._date.day;
			cin >> d[_n]._date.month;
			cin >> d[_n]._date.year;
		}
		cout << "������� ����� ������, ����� ������: ";
		cin >> d[_n]._warehouse.address;
		cin >> d[_n]._warehouse.number_of_warehouse;
		system("cls");
		cout << "������ ��������!" << endl;
	}
	else {
		cout << "����� ������ �� �����!" << endl;
	}
}



void DeleteData(Data* (&d), int& n)
{
	int _n;
	cout << "������� ����� �������� (�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");
	if (_n >= 0 && _n < n) {
		Data* buf = new Data[n];
		Copy(buf, d, n);
		--n;
		d = new Data[n];
		int q = 0;
		for (int i = 0; i < n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}
		system("cls");
		delete[]buf;
		cout << "������ �������" << endl;
	}
	else {
		cout << "����� ������ �� �����!" << endl;
	}
}

void AddData(Data* (&d), int& n)
{
	Data* buf;
	buf = new Data[n];
	Copy(buf, d, n);
	n++;
	d = new Data[n];
	Copy(d, buf, --n);
	cout << "��������, �������� �����: ";
	cin >> d[n]._auto.name;
	cin >> d[n]._auto.serial_number;
	cout << "������� ���� ����������� �� �����: ";
	cin >> d[n]._date.day;
	cin >> d[n]._date.month;
	cin >> d[n]._date.year;
	while ((d[n]._date.day > 1) or (d[n]._date.day > 31) or (d[n]._date.month < 1) or (d[n]._date.month > 12) or (d[n]._date.year < 1950) or (d[n]._date.year > 2100)) {
		cout << "������� ���� ����������� �� ����� ���������: ";
		cin >> d[n]._date.day;
		cin >> d[n]._date.month;
		cin >> d[n]._date.year;
	}
	cout << "������� ����� ������, ����� ������: ";
	cin >> d[n]._warehouse.address;
	cin >> d[n]._warehouse.number_of_warehouse;
	cout << "______________________________" << endl;
	system("cls");
	delete[]buf;
	cout << "������ ���������!";
}



void SaveData(Data* d, int n, string filename)
{
	ofstream record(filename, ios::out);
	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++) {
			record << d[i]._auto.name<<endl;
			record << d[i]._auto.serial_number<<endl;
			record << d[i]._date.day<<" ";
			record << d[i]._date.month<<" ";
			record << d[i]._date.year<<endl;
			record << d[i]._warehouse.address<<endl;
			if (i < n - 1) {
				record << d[i]._warehouse.number_of_warehouse << endl;
			}
			else {
				record << d[i]._warehouse.number_of_warehouse;
			}
		
		}
	}
	else {
		cout << "������ �������� �����" << endl;
	}
	record.close();
}

void Copy(Data* (&d_n), Data* (&d_o), int n)
{
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}

}
