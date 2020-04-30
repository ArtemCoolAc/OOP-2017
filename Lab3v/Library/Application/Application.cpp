// Application.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\Library\Diagram.h"
#include <iostream>
#include <locale.h>
#include <Windows.h>
#include <string.h>

int Dialog();
int getNum(int&);
int Invert();
int Add();
int Insert();
int Copy();
int Delete();
void _cls();

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	int ch;

	int(*P[])() = { Invert, Add, Insert, Copy, Delete };
	while ((ch = Dialog())) {
		if (!(P[ch - 1])()) {
			break;
		}
	}

	return 0;
}

void _cls() {
	for (int i = 0; i < 30; ++i) {
		std::cout << std::endl;
	}
}

int Dialog()
{
	setlocale(LC_ALL, "Rus");
	int n, o;
	printf("\n");
	char s[][50] = { "	0.Выход", "	1.Инвертировать", "	2.Сложить", "	3.Вставить", "	4.Копировать", "	5.Удалить" };
	for (o = 0; o < 6; o++) {
		printf("%s\n", s[o]);
	}
	printf("\n");
	do {
		std::cout << "        ";
		o = getNum(n);
		if (!o) {
			return 0;
		}
		if ((n > 5) || (n < 0)) {
			printf("	Введённый номер должен быть <5 и >=0\n");
		}
	} while ((n > 5) || (n < 0));
	printf("\n");
	return n;
}

int getNum(int &a)
{
	do {
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> a;
		if (std::cin.eof()) return -1;
		else {
			if (!(std::cin.good())) {
				std::cout << std::endl;
				std::cout << "        Ошибка при вводе числа. Повторите попытку" << std::endl;				
				std::cout << "        ";
			}
		}
	} while (!(std::cin.good()));
	return 1;
}



int Invert() {
	//int length;
	_cls();
	system("cls");
	_flushall();
	std::cout << "	Введите сигнал" << std::endl;
	std::cout << "        ";
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	try {
		lab3::Diagram s;
		std::cin >> s;
		lab3::Diagram s2 = s.Invert();
		//std::cout << "        Инвертированный сигнал имеет вид:" << std::endl;
		std::cout << s2 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}

int Add() {
	//int length;
	try {
		lab3::Diagram s;
		_cls();
		system("cls");
		_flushall();
		std::cout << "	Введите 1-ый сигнал" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s1 = lab3::Diagram(s);
		std::cout << "	Введите 2-ой сигнал" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s2 = lab3::Diagram(s);
		lab3::Diagram s3 = s1 + s2;
		//std::cout << "        Суммарный сигнал имеет вид:" << std::endl;
		std::cout << s3 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}

int Insert() {
	//int length;
	_cls();
	system("cls");
	_flushall();
	int time;
	try {
		lab3::Diagram s;
		std::cout << "	Введите 1-ый сигнал" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s1 = lab3::Diagram(s);
		std::cout << "	Введите 2-ой сигнал" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s2 = lab3::Diagram(s);
		std::cout << "	Введите момент времени" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		getNum(time);
		lab3::Diagram s3 = s1.Insert(time, s2);
		//std::cout << "        Итоговый сигнал имеет вид:" << std::endl;
		std::cout << s3 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}

int Copy() {
	//int length;
	int n;
	_cls();
	system("cls");
	_flushall();
	try {
		lab3::Diagram s;
		std::cout << "	Введите сигнал" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s1 = lab3::Diagram(s);
		std::cout << "	Введите количество раз копирования" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		getNum(n);
		lab3::Diagram s2 = s1.Copy(n);
		//std::cout << "        Скопированный сигнал имеет вид:" << std::endl;
		std::cout << s2 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}

int Delete() {
	//int length;
	_cls();
	system("cls");
	_flushall();
	int time; int duration;
	try {
		lab3::Diagram s;
		std::cout << "	Введите сигнал" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		std::cout << "	Введите начальное время удаления" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		getNum(time);
		std::cout << "	Введите длительность удаления" << std::endl;
		std::cout << "        ";
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		getNum(duration);
		lab3::Diagram s1 = lab3::Diagram(s);
		lab3::Diagram s2 = s1.Delete(time, duration);
		//std::cout << "        После преобразований сигнал имеет вид:" << std::endl;
		std::cout << s2 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}
