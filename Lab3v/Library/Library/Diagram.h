#pragma once
#include <iostream>

namespace lab3 {
	struct unit {
		char val;
		int dur;
	};

	class Diagram
	{
	private:
		static const int max_dur = 200;
		unit ar[max_dur];
		unit* arr;
		int curq = 0; //текущее кол-во массивов простых сигнальчиков
	public:
		Diagram();
		explicit Diagram(char zn);
		int getmax();
		Diagram(char* s);
		std::ostream& Print(std::ostream&)const;
		char* OutStroka(char*);
		//const Diagram OutStroka(char*)const;
		Diagram Invert();
		int SumDur() const;
		Diagram Add(Diagram& second);
		Diagram Insert(int time, Diagram& second);
		Diagram Copy(int quan);
		Diagram Delete(int time, int duration);
		//char* getstr(int length);
		friend Diagram operator + (Diagram& first, Diagram& second);
		//friend Diagram& operator * (int n, const Diagram& first);
		friend std::ostream& operator << (std::ostream &os, const Diagram& first);
		friend std::istream& operator >> (std::istream &is, Diagram& first);
		Diagram(const Diagram& first);
		Diagram& operator = (const Diagram&);
		~Diagram() { delete[]Diagram::arr; }
		int maxsigndur() { return (Diagram::arr[0].dur); }
		int maxsignval() { return (Diagram::arr[0].val); }
		int getcurq() { return (Diagram::curq); }
		unit* getpointer() { return (Diagram::arr); }
		Diagram(Diagram&& first) : arr(first.arr), curq(first.curq) { first.arr = nullptr; }
		Diagram& operator = (Diagram&& first) {
			curq = first.curq;
			unit* tmp = arr;
			arr = first.arr;
			first.arr = tmp;
			return *this;
		}
	};
}

