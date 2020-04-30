#include "stdafx.h"
#include "Ship.h"
#include "Person.h"
#include "Consts.h"

namespace lab4 {
	Ship::Ship()
	{
		draught = 0;
		quantity = 0;
		max_speed = 0;
	}
	
	Ship& Ship::setRank(const string& a)
	{
		capitan.setRank(a);
		return *this;
	}

	Ship& Ship::setName(const string& a)
	{
		capitan.setName(a);
		return *this;
	}

	Ship& Ship::setFamily(const string& a)
	{
		capitan.setFamily(a);
		return *this;
	}

	Ship& Ship::setPatronymic(const string& a)
	{
		capitan.setPatronymic(a);
		return *this;
	}
	
	Ship& Ship::setExperience(int a)
	{
		capitan.setExp(a);
		return *this;
	}

	Ship& Ship::setCap(const string& a, const string& b, const string& c, const string& d, int e)
	{
		capitan.setRank(a);
		capitan.setName(b);
		capitan.setFamily(c);
		capitan.setPatronymic(d);
		capitan.setExp(e);
		return *this;
	}

	Ship& Ship::setDra(int a)
	{
		draught = a;
		return *this;
	}

	Ship& Ship::setQuan(int a)
	{
		quantity = a;
		return *this;
	}

	Ship& Ship::setMax(double a)
	{
		max_speed = a;
		return *this;
	}

	Ship& Ship::setShipName(const string& a)
	{
		ship_name = a;
		return *this;
	}

	int Ship::getType() const
	{
		return 0;
	}

	std::ostream& Ship::PrintShip(std::ostream& os)
	{
		os << "Водоизмещение " << draught << std::endl;
		os << "Количество членов экипажа " << quantity << std::endl;
		os << "Максимальная скорость " << max_speed << std::endl;
		os << "Имя корабля " << ship_name << std::endl;
		string buf1 = capitan.getFamily();
		string buf2 = capitan.getName();
		string buf3 = capitan.getPatr();
		string buf4 = capitan.getRank();
		int exp = capitan.getExperience();
		os << "Капитан (ФИО): " << buf1 << " " << buf2 << " " << buf3 << ". Звание '" << buf4 << "', стаж " << exp << std::endl;
		return os;
	}

	std::ostream& operator << (std::ostream& os, Ship* ship)
	{
		int typ = ship->getType();
		if (typ == 1) { Guard* ship1 = dynamic_cast <Guard*> (ship); ship1->PrintShip(os); }
		if (typ == 2) { Transport* ship1 = dynamic_cast <Transport*> (ship); ship1->PrintShip(os); }
		if (typ == 3) { Warship* ship1 = dynamic_cast <Warship*> (ship); ship1->PrintShip(os); }
		return os;
	}

	void Ship::InputShip(int draught, int quantity, double max_speed, const string& ship_name, const Person& capitan)
	{
		this->draught = draught;
		this->quantity = quantity;
		this->max_speed = max_speed;
		this->ship_name = ship_name;
		this->capitan = capitan;
	}

	Ship* operator >> (std::istream& is, Ship* ship)
	{
		int type = ship->getType();
		if (type == 1) {
			Guard* ship1 = dynamic_cast<Guard*> (ship); 
			Ship* ship2 = dynamic_cast<Ship*> (ship1);
			*ship2 = *ship;
		}
		if (type == 2) {
			
		}
		return ship;
	}

	Ship::~Ship()
	{
	}
}
