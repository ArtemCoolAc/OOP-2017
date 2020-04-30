#pragma once
#include <vector>
#include <string>
#include "Person.h"
using std::string;

namespace lab4 {
	
	class Ship
	{
	protected:
		int type;
		int draught;       // водоизмещение
		int quantity;      // количество членов экипажа
		double max_speed;  // максимальная скорость
		string ship_name;  // имя корабля
		Person capitan;    // информация о капитане

	public:

		Ship();
		Ship(int draught, int quantity, double max_speed, string ship_name, Person& capitan) :draught(draught), quantity(quantity), max_speed(max_speed), ship_name(ship_name), capitan(capitan) { };
		const Person getCap(){ return capitan; }
		Ship& setCap(const string& rank, const string& name, const string& family, const string& patronymic, int experience);
		// методы получения и изменения полной информации о капитане
		const string& getCapName(){ return (capitan.getName());}
		const string& getCapFamily(){ return (capitan.getFamily());}
	    const string& getCapPatronymic(){ return (capitan.getPatr());}
		const string& getCapRank(){ return (capitan.getRank());}
		int getCapExperience(){ return (capitan.getExperience()); }
		// методы получения отдельных полей информации о капитане
		Ship& setRank       (const string& rank);
		Ship& setName       (const string& name);
		Ship& setFamily     (const string& family);
		Ship& setPatronymic (const string& patronymic);
		Ship& setExperience(int experience);
		// методы изменения отдельных полей информации о капитане
		int    getDra()      { return draught;   }
		int    getQuan()     { return quantity;  }
		double getMax()      { return max_speed; }
		const string& getShipName() { return ship_name; }
		// методы получения значений переменных класса Ship	
		Ship& setDra  (int draught);
		Ship& setQuan (int quantity);
		Ship& setMax  (double max_speed);
		Ship& setShipName (const string& ship_name);
		// методы изменения значений переменных класса Ship
		virtual int getType() const;
		void setType(int typ) { type = typ; }
		virtual std::ostream& PrintShip(std::ostream& os);
		friend std::ostream& operator << (std::ostream& os, Ship* ship);
		void InputShip(int draught, int quantity, double max_speed, const string& ship, const Person& capitan);
		virtual Ship* clone() const { return new Ship(*this); }
		virtual ~Ship(); 
	};

}

