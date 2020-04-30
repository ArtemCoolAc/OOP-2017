// Application.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\Library\Diagram.h"

#include <windows.h>
#include <locale.h>
#include <iostream>
#include <string.h>

int Dialog();
int getNum(int&);
int Invert();
int Add();
int Insert();
int Copy();
int Delete();

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

int Dialog()
{
	int n, o;
	printf("\n");
	char s[][50] = { "0.Выход", "1.Инвертировать", "2.Сложить", "3.Вставить", "4.Копировать", "5.Удалить" };
	for (o = 0; o < 6; o++) {
		printf("%s\n", s[o]);
	}
	printf("\n");
	do {
		o = getNum(n);
		if (!o) {
			return 0;
		}
		if (n > 5) {
			printf("Введённый номер должен быть <5 и >=0\n");
		}
	} while (n > 5);
	printf("\n");
	return n;
}

int getNum(int &a)
{
	std::cin >> a;
	if (!std::cin.good())
		return -1;
	return 1;
}



int Invert() {
	int length;
	std::cout << "Введите сигнал" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	try {
		lab3::Diagram s;
		std::cin >> s;
		lab3::Diagram s2 = s.Invert();
		std::cout << s2 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}

int Add() {
	int length;
	try {
		lab3::Diagram s;
		std::cout << "Введите 1-ый сигнал" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s1 = lab3::Diagram(s);
		std::cout << "Введите 2-ой сигнал" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s2 = lab3::Diagram(s);
		lab3::Diagram s3 = s1 + s2;
		std::cout << s3 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}

int Insert() {
	int length;  int time;
	try {
		lab3::Diagram s;
		std::cout << "Введите 1-ый сигнал" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s1 = lab3::Diagram(s);
		std::cout << "Введите 2-ой сигнал" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s2 = lab3::Diagram(s);
		std::cout << "Введите момент времени" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		getNum(time);
		lab3::Diagram s3 = s1.Insert(time, s2);
		std::cout << s3 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}

int Copy() {
	int length; int n;
	try {
		lab3::Diagram s;
		std::cout << "Введите сигнал" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		lab3::Diagram s1 = lab3::Diagram(s);
		std::cout << "Введите количество раз копирования" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		getNum(n);
		lab3::Diagram s2 = s1.Copy(n);
		std::cout << s2 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}

int Delete() {
	int length; int time; int duration;
	try {
		lab3::Diagram s;
		std::cout << "Введите сигнал" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cin >> s;
		std::cout << "Введите начальное время удаления" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		getNum(time);
		std::cout << "Введите длительность удаления" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		getNum(duration);
		lab3::Diagram s1 = lab3::Diagram(s);
		lab3::Diagram s2 = s1.Delete(time, duration);
		std::cout << s2 << std::endl;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 1;
}