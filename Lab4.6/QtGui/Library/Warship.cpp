#include "stdafx.h"
#include "Consts.h"

namespace lab4{
	Warship::Warship()
	{
		Ship::Ship();
		Transport::Transport();
		Guard::Guard();
		type = 3;
	}

	Warship& Warship::shot(int index)
	{
		vector<Armament_Description>& description = getVec();
		int ammunition = description[index].getAmm();
		ammunition--;
		description[index].setAmm(ammunition);
		return *this;
	}

	vector<Armament_Description>& Warship::getCannons()
	{
		vector<Armament_Description>& desc = getVec();
		return desc;
	}

	std::ostream& Warship::PrintShip(std::ostream& os)
	{
		//Ship::PrintShip(os);
		Transport::PrintShip(os);
		Guard::PrintShip(os);
		return os;
	}

	std::ostream& Warship::PrintCannons(std::ostream& os)
	{
		vector<Armament_Description>& Describer = getVec();
		vector<Armament_Description>::iterator iter = Describer.begin(); 
		vector<Armament_Description>::iterator end = Describer.end();
		int i = 0; int size = Describer.size();
		for (i = 0; i < size; ++iter) {
			os << "Орудие " << i << " имеет параметры" << std::endl;
			os << "Боезапас " << iter->getAmm() << std::endl;
			os << "Калибр " << iter->getCal() << std::endl;
			string loc; int locat = iter->getLoc();
			if (locat == stern) loc = "Корма";
			if (locat == nose) loc = "Нос";
			if (locat == left_side) loc = "Левый борт";
			if (locat == rigth_side) loc = "Правый борт";
			os << "Расположение: " << loc << std::endl;
			++i;
		}
		return os;
	}

	std::ostream& operator << (std::ostream& os, Warship* ship)
	{
		ship->PrintCannons(os);
		return os;
	}

	void Warship::InputShip(double mass, vector<Armament_Description>& Describer)
	{
		Guard::InputShip(Describer);
		Transport::InputShip(mass);
	}

	Warship::~Warship()
	{
	}
}
