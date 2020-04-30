#pragma once
#include <string>
using std::string;

namespace lab4 {

	struct FIO {
		string name;       // имя 
		string family;     // фамилия
		string patronymic; // отчество
	};
	class Person
	{
	private:
		string rank;     // звание
		FIO Full_Name;   // ФИО
		int experience;  // стаж
	public:
		Person();
		Person(const string& rank, const string& name, const string& family, const string& patronymic, int experience);
		const string& getRank() const   { return rank;                 }
		const string& getName() const   { return Full_Name.name;       }
		const string& getFamily() const { return Full_Name.family;     }
		const string& getPatr() const   { return Full_Name.patronymic; }
		int getExperience() { return experience;           }
		// методы получения значений полей информации о капитане
		Person& setRank       (const string& rank);
		Person& setName       (const string& name);
		Person& setFamily     (const string& family);
		Person& setPatronymic (const string& patronymic);
		Person& setExp        (int experience);
		// методы измненения значений полей информации о капитане
		~Person();
	};
}


