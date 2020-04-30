// Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Library\lemniscate.h"
#include <math.h>
#include <locale.h>
#include <Windows.h>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	lemniscate::lemniscate l(5, 6);
	int fl = 1;
	char* s = NULL; int t; double square, ro, phi,c,m; lemniscate::parameters x; int f2 = 1; 
	while (fl) {
		std::cout << "Уравнение лемнискаты: " << std::endl;
		s = l.text();
		std::cout << s << std::endl;
		delete[] s;
		t = l.type();
		if (t == 0) std::cout << "Точка" << std::endl;
		if (t == 1) std::cout << "Подера эллипса" << std::endl;
		if (t == -1) std::cout << "Подера гиперболы" << std::endl;
		square = l.square();
		std::cout << " Площадь кривой равна " << square << std::endl;
		x = l.trans();
		std::cout << "Коэффициенты уравнения кривой в полярных координатах: " << x.a*x.a << "," << x.b*x.b << std::endl;
		while (f2) {
			std::cout << "Введите фи" << std::endl;
			std::cin >> phi;
			f2 = std::cin.good();
			if (!f2) continue;
			ro = l.ro(phi);
			std::cout << "Расстояние до центра равно " << ro << std::endl;
			std::cin.clear();
		}
		std::cin.clear();
		std::cout << "Введите параметры лемнискаты или, если больше не хотите вводить параметры лемнискаты, нажмите ctrl+z" << std::endl;
		std::cin >> c >> m;
		if (std::cin.good())
			l.setcm(c, m);
		else fl = 0;
		f2 = 1;
	}
	return 0;
	
}

