
#include <C:\Users\Nick\source\repos\Project3\Project3\functions.h>

int _StateMenu;
void Menu() {
    cout << "Выберите действие" << endl
        << "(0) Выход из программы." << endl
        << "(1) Ввод данных." << endl
        << "(2) Вывод данных." << endl
        << "(3) Изменение данных." << endl
        << "(4) Удаление данных." << endl
        << "(5) Добавление данных." << endl
        << "(6) Сохранение данных." << endl
        << "Ваш выбор: ";
    cin >> _StateMenu;
}

void Main() {
    //Руссификация консоли ввода/вывода
    SetConsoleCP(1251);//Установка кодовой страницы win-cp в поток ввода
    SetConsoleOutputCP(1251);//Установка кодовой страницы win-cp в поток вывода


    Menu();

    int _actions,
        amountofData=0;
    string filename;

    Data* d = new Data[amountofData];

    while (_StateMenu != 0) {
        switch (_StateMenu)
        {
        case 1:
            system("cls");
            cout << "Ввод вручную или из файла?: ";
            cin >> _actions;
            if (_actions == 1) {
                DataEntry(d, amountofData);
            }
            else {
                ReadingData(d, amountofData, "input.txt");
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 2:
            system("cls");
            if (amountofData != 0) {
                Print(d, amountofData);
            }
            else {
                cout << "Данные пусты!";
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 3:
            system("cls");
            if (amountofData != 0) {
                DataChange(d, amountofData);
            }
            else {
                cout << "Данные пусты!";
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 4:
            system("cls");
            if (amountofData != 0) {
                DeleteData(d, amountofData);
            }
            else {
                cout << "Данные пусты!";
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 5:
            system("cls");
            if (amountofData != 0) {
                AddData(d, amountofData);
                amountofData++;
            }
            else {
                cout << "Данные пусты!";
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 6:
            system("cls");
            cout << "Введите название файла: ";
            cin >> filename;
            if (amountofData != 0) {
                SaveData(d, amountofData, filename);
            }
            else {
                cout << "Данные отсутствуют!" << endl;
            }
            system("pause");
            system("cls");
            Menu();
            break;
        default:
            cout << "Неверно введен номер действия"<<endl;
            system("pause");
            system("cls");
            Menu();
            break;
        }


    }
    system("cls");

    cout << "Работа завершена" << endl;
    system("pause");
}


int main()
{
    Main();
}