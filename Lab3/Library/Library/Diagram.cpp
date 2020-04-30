#include "stdafx.h"
#include "Diagram.h"
#include "iostream"

namespace lab3 {
	Diagram::Diagram(char zn)
	{
		if (zn != 1 && zn != 0)
			throw std::invalid_argument::invalid_argument("Инициализировать сигнал можно только нулем или единицей");
		else {
			Diagram::ar[0].dur = Diagram::max_dur;
			Diagram::ar[0].val = zn;
		}
	}

	Diagram::Diagram()
	{
		Diagram::curq = 0;
		Diagram::ar[0].dur = 0;
	}

	int Diagram::getmax()
	{
		return (Diagram::max_dur);
	}

	/*Diagram::Diagram(char* s)
	{
	if (!s) throw std::invalid_argument::invalid_argument("Пустой сигнал");
	int len = strlen(s);

	int i, dur; int j = 0;
	dur = 1;
	for (i = 0; i < len; ++i) {
	if ((s[i + 1] != '\0') && (s[i + 1] == s[i])) dur++;
	else {
	Diagram::ar[j].dur = dur;
	Diagram::ar[j].val = s[i];
	++j;
	dur = 1;
	}
	}
	Diagram::curq = j - 1;
	} */

	Diagram::Diagram(char* s)
	{
		if (!s) throw std::invalid_argument::invalid_argument("Пустой сигнал");
		int len = strlen(s);
		int i, dur; int j = 0;
		for (i = 0; i < len; ++i) {
			if ((s[i + 1] != '\0') && (s[i + 1] == s[i])) { dur = 1; }
			else {
				++j;
			}
		}
		Diagram::curq = j - 1;
		Diagram::arr = new unit[Diagram::curq];
		j = 0;
		
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

	std::ostream& Diagram::Print(std::ostream &os) const
	{
		if (!Diagram::curq) os << "Сигнал отстутствует" << std::endl;
		else {
			for (int i = 0; i < Diagram::curq; ++i) {
				for (int j = 0; j < Diagram::ar[i].dur; ++j) {
					if (Diagram::arr[i].val == '1') os << ("-");
					else os << ("_");
				}
			}
			os << std::endl;
		}
		return os;
	}

	 Diagram Diagram::OutStroka(char* s)
	{

		//char* s = nullptr;
		int dur = Diagram::SumDur();
		s = new char[dur + 1];
		int alr = 0; int j;
		while (alr < dur) {
			for (int i = 0; i < Diagram::curq; ++i) {
				for (j = 0; j < Diagram::arr[i].dur; ++j) {
					s[j] = Diagram::arr[i].val;
				}
			}
			s[j] = '\0';
		}
		return s;
	}

	Diagram Diagram::Invert()
	{
		int i;

		Diagram inv = Diagram::Diagram();
		if (Diagram::curq == -1) throw std::logic_error("Пустой сигнал");
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

	/*Diagram Diagram::Add(const Diagram& second)
	{
	int k;
	Diagram Added = Diagram();
	int dur1 = Diagram::SumDur();
	int dur2 = second.SumDur();
	if (dur1 + dur2 > Diagram::max_dur) throw std::length_error("Суммарный сигнал будет слишком большим");
	else {
	unit a = Diagram::ar[Diagram::curq - 1];
	unit b = second.ar[0];
	if (a.val == b.val) { k = 1; }
	else { k = 0; }
	for (int f = 0; f < Diagram::curq; ++f) {
	Added.ar[f].dur = Diagram::ar[f].dur;
	Added.ar[f].val = Diagram::ar[f].val;
	}
	if (k == 1) {
	Added.ar[Diagram::curq - 1].dur = Diagram::ar[Diagram::curq - 1].dur + second.ar[0].dur;
	Added.ar[Diagram::curq - 1].val = second.ar[0].val;
	for (int i = 1; i < second.curq; ++i) {
	Added.ar[Diagram::curq - 1 + i].dur = second.ar[i].dur;
	Added.ar[Diagram::curq - 1 + i].val = second.ar[i].val;
	}
	}
	else {
	for (int i = 0; i < second.curq; ++i) {
	Added.ar[Diagram::curq - k + i].dur = second.ar[i].dur;
	Added.ar[Diagram::curq - k + i].val = second.ar[i].val;
	}
	}
	Added.curq = Diagram::curq + second.curq - k;
	}
	return Added;
	}*/

	Diagram Diagram::Add(Diagram& second)
	{
		int dur1 = Diagram::SumDur();
		int dur2 = second.SumDur();
		if (dur1 + dur2 > Diagram::max_dur) throw std::length_error("Суммарный сигнал будет слишком большим");
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

	/*Diagram Diagram::Insert(int time, const Diagram& second)
	{
	int sum = 0;
	Diagram EAdded = Diagram::Diagram();
	int dur2 = second.SumDur();
	if (time + dur2 > Diagram::max_dur) throw std::length_error("Слишком длинный сигнал получается");
	else {
	int dur1 = Diagram::SumDur();
	int l = 0; int k;
	if (time > dur1) throw std::length_error("Время вставки находится за пределами сигнала");
	else {
	while (sum <= time) {
	sum += Diagram::ar[l].dur;
	++l;
	}
	//l--;
	int prev = sum - Diagram::ar[l - 1].dur;
	int dl = time - prev;

	for (int i = 0; i < l - 1; ++i) {
	EAdded.ar[i].dur = Diagram::ar[i].dur;
	EAdded.ar[i].val = Diagram::ar[i].val;
	}

	int j;
	if (Diagram::ar[l - 1].val == second.ar[0].val) { k = 1; }
	else { k = 0; }
	if (k == 1) {
	EAdded.ar[l - 1].dur = Diagram::ar[l - 1].dur + second.ar[0].dur;
	EAdded.ar[l - 1].val = second.ar[0].val;
	for (j = 1; j < second.curq; ++j) {
	EAdded.ar[l - 1 + j].dur = second.ar[j].dur;
	EAdded.ar[l - 1 + j].val = second.ar[j].val;
	}
	--j;
	}
	else {
	EAdded.ar[l - 1].dur = dl;
	EAdded.ar[l - 1].val = Diagram::ar[l - 1].val;
	for (j = 0; j < second.curq; ++j) {
	EAdded.ar[l + j].dur = second.ar[j].dur;
	EAdded.ar[l + j].val = second.ar[j].val;
	}
	}
	if (k == 0) {
	EAdded.ar[l + j].dur = Diagram::ar[l - 1].dur - dl;
	EAdded.ar[l + j].val = Diagram::ar[l - 1].val;
	}
	for (int f = j; f < Diagram::curq - l - k + j; ++f) {
	EAdded.ar[l + f + !(k)].dur = Diagram::ar[l + f - j].dur;
	EAdded.ar[l + f + !(k)].val = Diagram::ar[l + f - j].val;
	}
	}
	EAdded.curq = Diagram::curq + second.curq + (!k);
	}
	return EAdded;
	} */

	Diagram Diagram::Insert(int time, Diagram& second)
	{
		int sum = 0;
		int dur2 = second.SumDur();
		if (time + dur2 > Diagram::max_dur) throw std::length_error("Слишком длинный сигнал получается");
		else {
			int dur1 = Diagram::SumDur();
			int l = 0; int k;
			if (time > dur1) throw std::length_error("Время вставки находится за пределами сигнала");
			else {

				char* s2 = nullptr; char* s1 = nullptr;
				second.OutStroka(s2);
				Diagram::OutStroka(s1);
				char* s1be = nullptr; char* s1af = nullptr;
				s1be = new char[time + 1];
				s1af = new char[strlen(s1) - time];
				int length = time + 1 + strlen(s1) - time;
				strncpy(s1be, s1, time);
				s1be[time] = '\0';
				char* ins = nullptr;
				ins = new char[strlen(s1) + strlen(s2)];
				strcat(ins, s1be);
				strcat(ins, s2);
				int f = 0; int p = (strlen(s1) + strlen(s2)); int t;
				for (t = time + strlen(s2); t < p; ++t, f++) {
					ins[t] = s1[time + f];
				}
				ins[t] = '\0';
				Diagram EAdded = Diagram::Diagram(ins);
				delete[] s1be;
				delete[] s1af;
				delete[] ins;
				return EAdded;
			}
		}
	}

	/*Diagram Diagram::Copy(int quan)
	{
		Diagram Copied = Diagram::Diagram();
		int k; int d = 0;
		int dur = Diagram::SumDur();
		dur *= quan;
		if (dur > Diagram::max_dur) throw std::length_error("Получается слишком длинный сигнал");
		else {
			if (Diagram::ar[0].val == Diagram::ar[Diagram::curq - 1].val) k = 1;
			else k = 0;
			if ((k == 0) || (k == 1)) {
				for (int i = 0; i < quan; ++i) {
					for (int j = 0; j < Diagram::curq; ++j) {
						Copied.ar[d].dur = Diagram::ar[j].dur;
						Copied.ar[d].val = Diagram::ar[j].val;
						++d;
					}
				}
				Copied.curq = d;
			}
			else {
				for (int i = 0; i < quan; ++i) {
					Copied.ar[0 + i*(Diagram::curq - 1)].dur = Diagram::ar[0].dur;
					Copied.ar[0 + i*(Diagram::curq - 1)].val = Diagram::ar[0].val;
					for (int j = 1; j < Diagram::curq - 1; ++j) {
						Copied.ar[d].dur = Diagram::ar[j].dur;
						Copied.ar[d].val = Diagram::ar[j].val;
						++d;
					}
					Copied.ar[d - 1].dur = Diagram::ar[0].dur + Diagram::ar[Diagram::curq - 1].dur;
					Copied.ar[d - 1].val = Diagram::ar[0].val;
					//++d;
				}
				for (int j = 1; j < Diagram::curq; ++j) {
					Copied.ar[d].dur = Diagram::ar[j].dur;
					Copied.ar[d].val = Diagram::ar[j].val;
					++d;
				}
				Copied.curq = d;
			}
		}
		return Copied;
	} */

	Diagram Diagram::Copy(int quan)
	{
		int k; int d = 0;
		int dur = Diagram::SumDur();
		dur *= quan;
		if (dur > Diagram::max_dur) throw std::length_error("Получается слишком длинный сигнал");
		else {
			char* s1 = nullptr;
			s1 = new char[dur/quan + 1];
			Diagram::OutStroka(s1);
			char* s2 = nullptr;
			s2 = new char[dur + 1];
			for (int i = 0; i < quan; ++i) {
				strcat_s(s2, strlen(s2), s1);
			}
			Diagram Copied = Diagram::Diagram(s2);
			return Copied;
		}
	}
	/* Diagram& Diagram::Delete(int time, int duration)
	{
	Diagram Deleted = Diagram::Diagram();
	int dur = Diagram::SumDur();
	int deleted = 0; int sum = 0; int n1 = 0; int newind;
	if ((time + duration) > dur) std::length_error("Вы хотите удалить слишком много, у него столько нет");
	else {
	while (sum < time) {
	sum += Diagram::ar[n1].dur;
	n1++;
	}
	int fut = sum;
	sum -= Diagram::ar[n1 - 1].dur;
	for (int i = 0; i < n1 - 1; ++i) {
	Deleted.ar[i].dur = Diagram::ar[i].dur;
	Deleted.ar[i].val = Diagram::ar[i].val;
	}
	int dl = time - sum;
	Deleted.ar[n1 - 1].dur = dl;
	Deleted.ar[n1 - 1].val = Diagram::ar[n1 - 1].val;
	char a = Diagram::ar[n1 - 1].val;
	deleted = Diagram::ar[n1 - 1].dur - dl;
	int n2 = n1;
	int fl = 0;
	if (deleted >= duration) {
	Deleted.ar[n1 - 1].dur = Diagram::ar[n1 - 1].dur - duration;
	for (int t = n1; t < Diagram::curq; ++t) {
	Deleted.ar[t].dur = Diagram::ar[t].dur;
	Deleted.ar[t].val = Diagram::ar[t].val;
	}
	Deleted.curq = Diagram::curq;
	}
	else {
	int skipped = 0;
	while (deleted < duration) {
	++skipped;
	++n2;
	deleted += Diagram::ar[n2].dur;
	}
	deleted -= Diagram::ar[n2].dur;
	//if (fl) deleted
	int delta = Diagram::ar[n2].dur - (duration - deleted);
	char b = Diagram::ar[n2].val;
	if (a == b) {
	Deleted.ar[n1].dur += delta;
	newind = n1 + 1;
	Deleted.curq = Diagram::curq - 1 - skipped;
	}
	else {
	Deleted.ar[n1 + 1].dur = delta;
	Deleted.ar[n1 + 1].val = Diagram::ar[n2].val;
	newind = n1 + 2;
	Deleted.curq = Diagram::curq - skipped;
	}
	for (int t = 1; (n2 + t) < Diagram::curq; ++t, ++newind) {
	Deleted.ar[newind].dur = Diagram::ar[n2 + t].dur;
	Deleted.ar[newind].val = Diagram::ar[n2 + t].val;
	}
	}
	}
	Deleted.Print();
	return *this;
	}
	*/

	Diagram Diagram::Delete(int time, int duration)
	{
		Diagram Deleted = Diagram::Diagram();
		int dur = Diagram::SumDur();
		int sum = 0; int n1 = 0;
		if ((time + duration) > dur) throw std::length_error("Вы хотите удалить слишком много, у него столько нет либо уже после диаграммы");
		else {
			while (sum < time) {
				sum += Diagram::ar[n1].dur;
				n1++;
			}
			for (int i = 0; i < n1 - 1; ++i) {
				Deleted.ar[i].dur = Diagram::ar[i].dur;
				Deleted.ar[i].val = Diagram::ar[i].val;
			}
			int prev = sum - Diagram::ar[n1 - 1].dur;
			int dif = time - prev;
			Deleted.ar[n1 - 1].dur = dif;
			Deleted.ar[n1 - 1].val = Diagram::ar[n1 - 1].val;
			int deleted = Diagram::ar[n1 - 1].dur - dif;
			int n2 = n1 + 1; int counter = 0;
			while (deleted < duration) {
				deleted += Diagram::ar[n1].dur;
				n1++;
				counter++;
			}
			int fdel = deleted;
			deleted -= Diagram::ar[n1 - 1].dur;
			Deleted.ar[n2 - 1].dur = (fdel - duration);
			Deleted.ar[n2 - 1].val = Diagram::ar[n2].val;
			for (int j = n2; j < Diagram::curq; ++j) {
				Deleted.ar[j].dur = Diagram::ar[j + counter - 1].dur;
				Deleted.ar[j].val = Diagram::ar[j + counter - 1].val;
			}
			Deleted.curq = Diagram::curq - (counter - 1);
			return Deleted;
		}
	}

	char *getstr(int &len)
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
				ptr = (char *)realloc(ptr, len + 2);
				strcat(ptr, buf);
				strcat(ptr, " ");
				len++;
			}
		} while (n > 0);
		if (len > (max = a.getmax())) throw std::length_error("Вы ввели слишком длинный сигнал");
		else {
			for (int i = 0; i < len - 1; ++i) {
				if ((ptr[i] != '1') && (ptr[i] != '0')) throw std::invalid_argument("В строке содержатся некорректные символы");
			}
		}
		return ptr;
	}

	Diagram operator + (const Diagram& first, const Diagram& second)
	{
		/*Diagram s;
		s = first;
		s = s.Add(second); */
		int k;
		Diagram Added = Diagram();
		//Diagram second = Diagram(s);
		int dur1 = first.SumDur();
		int dur2 = second.SumDur();
		if (dur1 + dur2 > Diagram::max_dur) throw std::length_error("Суммарный сигнал будет слишком большим");
		else {
			unit a = first.ar[first.curq - 1];
			unit b = second.ar[0];
			if (a.val == b.val) { k = 1; }
			else { k = 0; }
			for (int f = 0; f < first.curq; ++f) {
				Added.ar[f].dur = first.ar[f].dur;
				Added.ar[f].val = first.ar[f].val;
			}
			if (k == 1) {
				Added.ar[first.curq - 1].dur = first.ar[first.curq - 1].dur + second.ar[0].dur;
				Added.ar[first.curq - 1].val = second.ar[0].val;
				for (int i = 1; i < second.curq; ++i) {
					Added.ar[first.curq - 1 + i].dur = second.ar[i].dur;
					Added.ar[first.curq - 1 + i].val = second.ar[i].val;
				}
			}
			else {
				for (int i = 0; i < second.curq; ++i) {
					Added.ar[first.curq - k + i].dur = second.ar[i].dur;
					Added.ar[first.curq - k + i].val = second.ar[i].val;
				}
			}
			Added.curq = first.curq + second.curq - k;
		}
		return Added;
	}

	std::ostream& operator << (std::ostream &os, const Diagram& first)
	{
		first.Print(os);
		return os;
	}

	std::istream& operator >> (std::istream &is, Diagram& first)
	{
		int len;// char* s;
				/* s = getstr(len);
				first = Diagram(s); */
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
				ptr = (char *)realloc(ptr, len + 2);
				strcat(ptr, buf);
				strcat(ptr, " ");
				len++;
			}
		} while (n > 0);
		if (len > (max = a.getmax())) throw std::length_error("Вы ввели слишком длинный сигнал");
		else {
			for (int i = 0; i < len - 1; ++i) {
				if ((ptr[i] != '1') && (ptr[i] != '0')) throw std::invalid_argument("В строке содержатся некорректные символы");
			}
		}
		first = Diagram(ptr);
		//free(ptr);
		return is;
	}

	//Diagram::~Diagram()
	//{
	//}

}

