#include "stdafx.h"
#include "Consts.h"
using vctr::vector;

namespace lab4 {
	Guard::Guard()
	{
		Ship::Ship(); 
		type = 1;
	}

	void Guard::addmem()
	{	
		Armament_Description describe;
		Describer.push_back(describe);
	}

	void Guard::setAmm(int amm, int index)
	{
		Describer[index].setAmm(amm);
	}

	void Guard::setCal(int calibre, int index)
	{
		Describer[index].setCal(calibre);
	}

	void Guard::setRange(int range, int index)
	{
		Describer[index].setRange(range);
	}

	void Guard::setLoc(int location, int index)
	{	
		Describer[index].setLoc(location);
	}

	void Guard::setGun(vector<Armament_Description>& Guns)
	{
		Describer = Guns;
	}

	int Guard::getAmm(int index)
	{
		int value = Describer[index].getAmm();
		return value;
	}

	double Guard::getCal(int index)
	{
		double value = Describer[index].getCal();
		return value;
	}

	double Guard::getRange(int index)
	{
		double value = Describer[index].getRange();
		return value;
	}

	int Guard::getLoc(int index)
	{
		int value = Describer[index].getLoc();
		return value;
	}

	std::ostream& Guard::PrintShip(std::ostream& os)
	{
		Ship::PrintShip(os);
		for (int i = 0; i < Describer.size(); ++i) {
			os << "Орудие " << i << " имеет параметры" << std::endl;
			os << "Боезапас " << Describer[i].getAmm() << std::endl;
			os << "Калибр " << Describer[i].getCal() << std::endl;
			string loc; int locat = Describer[i].getLoc();
			if (locat == stern) loc = "Корма";
			if (locat == nose) loc = "Нос";
			if (locat == left_side) loc = "Левый борт";
			if (locat == rigth_side) loc = "Правый борт";
			os << "Расположение: " << loc << std::endl;
		}
		return os;
	}

	void Guard::InputShip(vector<Armament_Description>& Describer)
	{
		this->Describer = Describer;
	}


	Guard::~Guard()
	{
	}
}