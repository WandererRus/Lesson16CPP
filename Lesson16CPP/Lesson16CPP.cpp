// Lesson16CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
class MyDate {
private:
    int _year;
    int _month;
    int _day;
    bool visokos;
    bool isVisokos(int year) 
    {
        return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    }
    int dayCountInMonth(int month)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
            return 31;
        if (month == 4 || month == 6 || month == 9 || month == 11)
            return 30;
        if (month == 2 && isVisokos(_year))
            return 29;
        if (month == 2 && !isVisokos(_year))
            return 28;
    }
    int dayCountPassInYear()
    {
        int days = 0;
        for (int i = 1; i < _month; i++)
        {
            days += dayCountInMonth(i);
        }
        return days + _day;
    }

public:
    MyDate()
    {
        _year = 2000;
        _month = 1;
        _day = 1;
        visokos = isVisokos(_year);
    }
    MyDate(int year, int month, int day)
    {
        _year = year;
        if (month > 12)
        {
            _month = 12;
        }
        else if (month <= 0)
        {
            _month = 1;
        }
        else
        {
            _month = month;
        }
        if (day > dayCountInMonth(_month))
        {
            _day = dayCountInMonth(_month);
        }
        else if (day <= 0)
        {
            _day = 1;
        }
        else
        {
            _day = day;
        }
        visokos = isVisokos(_year);
    }
    int operator-(MyDate& seconddate)
    {
        int visokosYearCount = 0;
        if (_year > seconddate._year)
        {
            for (int i = seconddate._year; i <= _year; i++)
            {
                if (isVisokos(i))
                    visokosYearCount++;
            }
            return (((_year - seconddate._year) - visokosYearCount) * 365 + visokosYearCount * 366) -
                dayCountPassInYear() + seconddate.dayCountPassInYear();
        }    
        if (_year <= seconddate._year)
        {
            for (int i = _year; i <= seconddate._year; i++)
            {
                if (isVisokos(i))
                    visokosYearCount++;
            }
            return (((seconddate._year - _year) - visokosYearCount) * 365 + visokosYearCount * 366) -
                seconddate.dayCountPassInYear() + dayCountPassInYear();
        }
    }

};
int main()
{
    MyDate date1(2023, 31, -12);
    MyDate date2(2023, -1, 36);
    int passdays = abs(date1 - date2);
    std::cout << passdays;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
