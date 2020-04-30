#include "stdafx.h"
#include "Diagram.h"
#include <iostream>
#include <Windows.h>
#include <string>
namespace lab3 {
	Diagram::Diagram(char zn)
	{
		if (zn != '1' && zn != '0')
			throw std::invalid_argument::invalid_argument("        Инициализировать сигнал можно только нулем или единицей");
		else {
			Diagram::arr = new unit;
			Diagram::arr[0].dur = Diagram::max_dur;
			Diagram::arr[0].val = zn;
		}
	}

	Diagram::Diagram()
	{
		Diagram::curq = 0;
		Diagram::ar[0].dur = 0;
		Diagram::arr = nullptr;
	}

	int Diagram::getmax()
	{
		return (Diagram::max_dur);
	}

	Diagram::Diagram(char* s)
	{
		for (int g = 0; g < strlen(s); ++g) {
			if ((s[g] != '1') && (s[g] != '0')) throw std::invalid_argument("        Неверные символы в строке");
		}
		if (!s) throw std::invalid_argument::invalid_argument("        Пустой сигнал");
		int len = strlen(s);
		int i, dur; int j = 0;
		for (i = 0; i < len; ++i) {
			if ((s[i + 1] != '\0') && (s[i + 1] == s[i])) { dur = 1; }
			else {
				++j;
			}
		}
		Diagram::curq = j;
		Diagram::arr = new unit[Diagram::curq];
		j = 0;
		dur = 1;
		for (i = 0; i < len; ++i) {
			if ((s[i + 1] != '\0') && (s[i + 1] == s[i])) dur++;
			else {
				Diagram::arr[j].dur = dur;
				Diagram::arr[j].val = s[i];
				++j;
				dur = 1;
			}
		}
	}

	/*std::ostream& Diagram::Print(std::ostream &os) const
	{
		if (!Diagram::curq) os << "Сигнал отстутствует" << std::endl;
		else {
			for (int i = 0; i < Diagram::curq; ++i) {
				for (int j = 0; j < Diagram::arr[i].dur; ++j) {
					if (Diagram::arr[i].val == '1') os << ("-");
					else { if (Diagram::arr[i].val == '0') os << ("_"); }
				}
			}
			os << std::endl;
		}
		return os;
	}*/

	std::ostream& Diagram::Print(std::ostream &os) const
	{
		if (!Diagram::curq) os << "        Сигнал отстутствует" << std::endl;
		else {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получить консоль
			POINT op;
			HWND hWnd = GetConsoleWindow();
			HDC hDC = GetDC(hWnd);
			SelectObject(hDC, GetStockObject(WHITE_PEN));
			CONSOLE_SCREEN_BUFFER_INFO bi;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
			int ssx = bi.dwCursorPosition.X;
			int ssy = bi.dwCursorPosition.Y;
			MoveToEx(hDC, ssx + 70, ssy * 20 + 20, &op);
			int x = ssx + 70; int y = ssy * 20 + 20;
			int cdy = 10;
			int zn = 1; int i;
			if (Diagram::arr[0].val == '1') zn = 1;
			if (Diagram::arr[0].val == '0') zn = -1;
			for (i = 0; i < Diagram::curq-1; ++i) {
				int dy = zn * cdy;
				x += (10 * (Diagram::arr[i].dur));
				LineTo(hDC, x, y);
				MoveToEx(hDC, x, y, &op);
				y += dy;
				LineTo(hDC, x, y);
				MoveToEx(hDC, x, y, &op);
				zn = -zn;
			}
			LineTo(hDC, (x + 10 *(Diagram::arr[i].dur)), y);
			ReleaseDC(hWnd, hDC);
			int a;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
			COORD position;
			position.X = bi.dwCursorPosition.X+8;
			position.Y = bi.dwCursorPosition.Y+10;
			SetConsoleCursorPosition(hConsole, position);
			std::cin >> a;
			position.Y = bi.dwCursorPosition.Y+6;
			SetConsoleCursorPosition(hConsole, position);
			std::cout << std::endl;
			os << std::endl;
			
		}
		return os;
	}

	char* Diagram::OutStroka(char* s)
	{
		int dur = Diagram::SumDur();
		s = new char[dur + 1];
		int alr = 0; int j; int d = 0;
		for (int i = 0; i < Diagram::curq; ++i) {
			for (j = 0; j < Diagram::arr[i].dur; ++j) {
				s[d + j] = Diagram::arr[i].val;
			}
			d += Diagram::arr[i].dur;
		}
		s[d] = '\0';

		return s;
	}

	Diagram Diagram::Invert()
	{
		int i;
		char* s = nullptr;
		s = Diagram::OutStroka(s);
		Diagram inv = Diagram::Diagram(s);
		delete[] s;
		if (Diagram::curq == -1) throw std::logic_error("        Пустой сигнал");
		else {
			for (i = 0; i < Diagram::curq; ++i) {
				inv.arr[i].dur = Diagram::arr[i].dur;
				if (Diagram::arr[i].val == '1')
					inv.arr[i].val = '0';
				else inv.arr[i].val = '1';
			}
			inv.curq = Diagram::curq;
		}
		return inv;
	}

	int Diagram::SumDur() const
	{
		int sum = 0;
		for (int i = 0; i < Diagram::curq; ++i) {
			sum += Diagram::arr[i].dur;
		}
		return sum;
	}

	Diagram Diagram::Add(Diagram& second)
	{
		int dur1 = Diagram::SumDur();
		int dur2 = second.SumDur();
		if (dur1 + dur2 > Diagram::max_dur) throw std::length_error("        Суммарный сигнал будет слишком большим");
		else {
			char* s2 = nullptr;
			second.OutStroka(s2);
			char* s1 = nullptr;
			Diagram::OutStroka(s1);
			char* s3 = nullptr;
			s3 = new char[strlen(s1) + strlen(s2) + 1];
			strcat_s(s3, strlen(s3), s1);
			strcat_s(s3, strlen(s3), s2);
			Diagram Added = Diagram::Diagram(s3);
			delete[] s2;
			delete[] s1;
			delete[] s3;
			return Added;
		}
	}

	Diagram Diagram::Insert(int time, Diagram& second)
	{
		if (time<0) throw std::length_error("        Время вставки находится за пределами представлений человека об индексах");
		else {
			int sum = 0;
			int dur2 = second.SumDur();
			if (time + dur2 > Diagram::max_dur) throw std::length_error("        Слишком длинный сигнал получается");
			else {
				int dur1 = Diagram::SumDur();
				int l = 0;
				if (time > dur1) throw std::length_error("        Время вставки находится за пределами сигнала");
				else {

					char* s2 = nullptr; char* s1 = nullptr;
					s2 = second.OutStroka(s2);
					s1 = Diagram::OutStroka(s1);
					char* s1be = nullptr; char* s1af = nullptr;
					s1be = new char[time + 1];
					int length = time + 1 + strlen(s1) - time;
					strncpy(s1be, s1, time);
					s1be[time] = '\0';
					char* ins = nullptr;
					ins = new char[strlen(s1) + strlen(s2) + 1];
					*ins = '\0';
					strcat(ins, s1be);
					strcat(ins, s2);
					int f = 0; int p = (strlen(s1) + strlen(s2)); int t;
					for (t = time + strlen(s2); t < p; ++t, f++) {
						ins[t] = s1[time + f];
					}
					ins[t] = '\0';
					Diagram EAdded = Diagram::Diagram(ins);
					delete[] s1be;
					delete[] ins;
					return EAdded;
				}
			}
		}
	}

	Diagram Diagram::Copy(int quan)
	{
		if (quan <= 0) throw std::logic_error("        Количество самой диаграммы в скопированной не меньше 1");
		else {
			int d = 0;
			int dur = Diagram::SumDur();
			dur *= quan;
			if (dur > Diagram::max_dur) throw std::length_error("        Получается слишком длинный сигнал");
			else {
				char* s1 = nullptr;
				s1 = new char[dur / quan + 1];
				s1 = Diagram::OutStroka(s1);
				char* s2 = nullptr;
				s2 = new char[dur + 1];
				*s2 = '\0';
				for (int i = 0; i < quan; ++i) {
					strcat(s2, s1);
				}
				Diagram Copied = Diagram::Diagram(s2);
				return Copied;
			}
		}
	}

	Diagram Diagram::Delete(int time, int duration)
	{
		if ((time < 0) || (duration < 0)) throw std::length_error("        Отрицательные время вставки или продолжительность удаления");
		else {
			char* s = nullptr; int p;
			s = Diagram::OutStroka(s);
			if ((time + duration)>(strlen(s))) throw std::length_error("        Как минимум последний удаленный символ находится вне сигнала");
			else {
				char* s1 = nullptr;
				s1 = new char[strlen(s) - duration + 1];
				*s1 = '\0';
				strncat(s1, s, time);
				int l = strlen(s) - (duration + time);
				for (p = time; (p - time) < l; ++p) {
					s1[p] = s[p + duration];
				}
				s1[p] = '\0';
				Diagram Deleted = Diagram::Diagram(s1);
				delete[]s;
				delete[]s1;
				return Deleted;
			}
		}
	}

	/*char *getstr(int &len)
	{
		int max; lab3::Diagram a;
		char *ptr = (char *)calloc(1, sizeof(char *));
		char buf[81];
		int n;
		len = 0;
		*ptr = '\0';
		do {
			n = scanf_s("%80[^\n]", buf, 81);
			if (n < 0) {
				free(ptr);
				ptr = NULL;
				continue;
			}
			if (n == 0)
				scanf_s("%*c");
			else {
				len += strlen(buf);
				ptr = (char *)realloc(ptr, len + 1);
				strcat(ptr, buf);
				len++;
			}
		} while (n > 0);
		if (len > (max = a.getmax())) throw std::length_error("        Вы ввели слишком длинный сигнал");
		else {
			for (int i = 0; i < len; ++i) {
				if ((ptr[i] != '1') && (ptr[i] != '0')) throw std::invalid_argument("        В строке содержатся некорректные символы");
			}
		}
		return ptr;
	}*/

	Diagram operator + (Diagram& first, Diagram& second)
	{
		int l;
		int dur1 = first.SumDur();
		int dur2 = second.SumDur();
		if (dur1 + dur2 > first.getmax()) throw std::length_error("        Суммарный сигнал будет слишком большим");
		else {
			char* s2 = nullptr;
			s2 = second.OutStroka(s2);
			char* s1 = nullptr;
			s1 = first.OutStroka(s1);
			char* s3 = nullptr;
			s3 = new char[l = (strlen(s1) + strlen(s2) + 1)];
			*s3 = '\0';
			strcat_s(s3, l, s1);
			strcat_s(s3, l, s2);
			Diagram Added = Diagram(s3);
			delete[] s2;
			delete[] s1;
			delete[] s3;
			return Added;
		}
	}

	std::ostream& operator << (std::ostream &os, const Diagram& first)
	{
		first.Print(os);
		return os;
	}

	std::istream& operator >> (std::istream &is, Diagram& first)
	{
		int len;
		int max; lab3::Diagram a;
		char *ptr = (char *)calloc(1, sizeof(char *));
		char buf[81];
		int n;
		len = 0;
		*ptr = '\0';
		do {
			n = scanf_s("%80[^\n]", buf, 81);
			if (n < 0) {
				free(ptr);
				ptr = NULL;
				continue;
			}
			if (n == 0)
				scanf_s("%*c");
			else {
				len += strlen(buf);
				ptr = (char *)realloc(ptr, len + 1);
				strcat(ptr, buf);
				len++;
			}
		} while (n > 0);
		if (len > (max = a.getmax())) throw std::length_error("        Вы ввели слишком длинный сигнал");
		else {
			int i;
			for (i = 0; i < len - 1; ++i) {
				if ((ptr[i] != '1') && (ptr[i] != '0')) throw std::invalid_argument("        В строке содержатся некорректные символы");
			}

		}
		first = Diagram(ptr);
		free(ptr);
		return is;
	}

	Diagram::Diagram(const Diagram& first) :curq(first.curq), arr(nullptr)
	{
		if (curq) {
			arr = new unit[curq];
			for (int i = 0; i < curq; ++i) {
				arr[i] = first.arr[i];
			}
		}
	}

	Diagram& Diagram::operator=(const Diagram& first) {
		if (this != &first) {
			delete[]arr;
			curq = first.curq;
			arr = nullptr;
			if (curq) {
				arr = new unit[curq];
				for (int i = 0; i < curq; ++i) {
					arr[i] = first.arr[i];
				}
			}
		}
		return *this;
	}
} 
