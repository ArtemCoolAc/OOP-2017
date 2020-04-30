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
		static const int max_dur = 100;
		unit ar[max_dur];
		unit* arr;
		int curq = 0; //текущее кол-во массивов простых сигнальчиков
	public:
		Diagram();
		explicit Diagram(char zn);
		int getmax();
		Diagram(char* s);
		std::ostream& Print(std::ostream&)const;
		Diagram OutStroka(char*);
		//const Diagram OutStroka(char*)const;
		Diagram Invert();
		int SumDur() const;
		Diagram Add(Diagram& second);
		Diagram Insert(int time, Diagram& second);
		Diagram Copy(int quan);
		Diagram Delete(int time, int duration);
		char* getstr(int length);
		friend Diagram operator + (const Diagram& first, const Diagram& second);
		//friend Diagram& operator * (int n, const Diagram& first);
		friend std::ostream& operator << (std::ostream &os, const Diagram& first);
		friend std::istream& operator >> (std::istream &is, Diagram& first);
		//~Diagram();
	};
}