#include "stdafx.h"
#include "Consts.h"

namespace lab4{
	Table::Table()
	{
		
	}

	Table& Table::includeElem(Element& elem)
	{
		table.push_back(elem);
		return *this;
	}

	vector<Element>& Table::deleteElem(int index)
	{
		vector<Element>::iterator iter = cur(index);
		if (index != 0) {
			delete iter->ship;
			iter->ship = nullptr;
			table.erase(iter);
		}
		else {
			if (index == 0) {
				vector<Element> tab(table.size() - 1);
				for (int i = 0; i < table.size() - 1; ++i) {
					tab[i] = table[i + 1];
				}
				this->table = tab;
			}
		}
		
		return table;
	}

	Table& Table::Allocate_memory(int quan)
	{
		table.reserve(quan);
		return *this;
	}

	Table& Table::setVec(vector<Element>& vector)
	{
		table = vector;
		return *this;
	}

	void Table::PrintTable()
	{
		vector<Element>& table = getVec();
		vector<Element>::iterator iter1 = begin();
		vector<Element>::iterator iter2 = end();
		int size = table.size();
		for (int i = 0; i<size; ++iter1) {
			std::cout << " Позывные корабля:" << iter1->callsign << std::endl;
			std::cout << " Расстояние до пункта назначения" << iter1->distance << std::endl;
			std::cout << iter1->ship;
			++i;
		}
	}

	Ship* Table::ReturnShip(int index)
	{
		vector<Element>& table = getVec();
		vector<Element>::iterator iter = cur(index);
		return iter->ship;
	}

	Ship* Table::GetShipUsingCallsign(const string& call)
	{
		vector<Element>& table = getVec();
		vector<Element>::iterator iter = begin();
		vector<Element>::iterator iter1 = end();
		int size = table.size();
		for (int i = 0; i<size; ++iter1) {
			if (iter->callsign == call)
			{
				return iter->ship;
			}
			++i;
		}
		return nullptr;
	}

	Element& Table::getElem(int index)
	{
		vector<Element>& tabl = getVec();
		vector<Element>::iterator iter = cur(index);
		return *iter;
	}

	string& Table::getCallsign(int index)
	{
		vector<Element>::iterator iter = cur(index);
		return iter->callsign;
	}

	double Table::getDistance(int index)
	{
		vector<Element>::iterator iter = cur(index);
		return iter->distance;
	}

	Table& Table::setCallsign(const string& callsing, int index)
	{
		vector<Element>::iterator iter = cur(index);
		iter->callsign = callsing;
		return *this;
	}

	Table& Table::setDistance(double distance, int index)
	{
		vector<Element>::iterator iter = cur(index);
		iter->distance = distance;
		return *this;
	}

	Table& Table::setShip(Ship* ship, int index)
	{
		vector<Element>::iterator iter = cur(index);
		iter->ship = ship;
		return *this;
	}

	Table& Table::deleteShip(int index)
	{
		vector<Element>::iterator iter = cur(index);
		delete(iter->ship);
		iter->ship = nullptr;
		return *this;
	}

	/*Table::Iterator::TableIt()
	{
		
	}*/

	vector<Element>::iterator Table::begin()
	{
		vector<Element>::iterator It = table.begin();
		return It;
	}

	vector<Element>::iterator Table::end()
	{
		vector<Element>::iterator It = table.end();
		return It;
	}

	vector<Element>::iterator Table::cur(int index)
	{
		vector<Element>::iterator Cur = table.begin() + index;
		return Cur;
	}

	Table::Iterator::~TableIt()
	{
	
	}

	Table& Table::operator=(const Table& tab)
	{
		table = tab.table;
		return *this;
	}
	
	Table::~Table()
	{
		vector<Element>::iterator Iter = table.begin();
		vector<Element>::iterator End = table.end();
		int size = table.size();	
		for (; Iter != End; ++Iter) {
				delete Iter->ship;
				Iter->ship = nullptr;
		}
	}

	Element::Element(const Element& el) : ship(nullptr), callsign(el.callsign), distance(el.distance)
	{
		if (el.ship == nullptr) ship = nullptr;
		else {
			int type = el.ship->getType();
			if (type == 1) {
				ship = new Guard;
			}
			if (type == 2) {
				ship = new Transport;
			}
			if (type == 3) {
				ship = new Warship;
			}
			ship = el.ship;
		}
	}
	
	Element& Element::operator=(const Element& el)
	{
		if (this != &el) {
			delete ship;
			ship = nullptr;
			callsign = el.callsign;
			distance = el.distance;
			int type = el.ship->getType();
			if (type == 1) {
				Guard* guard = dynamic_cast<Guard*> (el.ship);
				ship = new Guard(*guard);
			}
			if (type == 2) {
				Transport* transport = dynamic_cast<Transport*> (el.ship);
				ship = new Transport(*transport);
			}
			if (type == 3) {
				Warship* warship = dynamic_cast<Warship*> (el.ship);
				ship = new Warship(*warship);
			}
			//ship = el.ship;
		}

		return *this;
	}
}
