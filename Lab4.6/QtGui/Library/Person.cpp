#include "stdafx.h"
#include "Person.h"

namespace lab4 {
	Person::Person()
	{
		experience = 0;
	}

	Person::Person(const string& name, const string& family, const string& patronymic, const string& ran, int exp)
	{
		Full_Name.name = name;
		Full_Name.family = family;
		Full_Name.patronymic = patronymic;
		rank = ran;
		experience = exp;
	}

	Person& Person::setRank(const string& ran)
	{
		rank = ran;
		return *this;
	}
	Person& Person::setName(const string& name)
	{
		Full_Name.name = name;
		return *this;
	}
	Person& Person::setFamily(const string& family)
	{
		Full_Name.family = family;
		return *this;
	}
	Person& Person::setPatronymic(const string& patronymmic)
	{
		Full_Name.patronymic = patronymmic;
		return *this;
	}
	Person& Person::setExp(int exp)
	{
		experience = exp;
		return *this;
	}

	Person::~Person()
	{
	}
}
