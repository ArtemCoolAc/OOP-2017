#pragma once
#include "Ship.h"
#include "Vector.h"
//#include "Iterator.h"
using std::string;
using vctr::vector;
//class Iterator;

namespace lab4{
	struct Element {
		Ship* ship;       // указатель на описатель судна
		string callsign;  // позывные судна
		double distance;  // расстояние

		Element(): ship(nullptr), distance(0) {}
		Element(Ship* ship, const string& callsign, double distance) : ship(ship), callsign(callsign), distance(distance) {}
		Element(const Element& el); // копирующий конструктор
		Element& operator = (const Element& el); // перегруженный оператор присваивания
		Element(Element&& el) : ship(el.ship), callsign(el.callsign), distance(el.distance) { el.ship = nullptr; } // перемещающий конструктор
		Element& operator = (Element&& el) // перегруженный оператор присваивания
		{ 
			callsign = el.callsign;
			distance = el.distance;
			Ship* tmp = ship;
			ship = el.ship;
			el.ship = tmp;
			return *this;
		}

	};
	
	class Table
	{	
	private:
		vector <Element> table;
		//std::vector <Element>::iterator it;
	public:
		Table();
		vector <Element>& getVec() { return table; }
		Table& includeElem(Element& elem);
		vector<Element>& deleteElem(int index);
		Table& setVec(vector<Element>& vector);
		Table& Allocate_memory(int quan);
		Ship* ReturnShip(int index);
		void PrintTable();
		Ship* GetShipUsingCallsign(const string& callsign);
		Element& getElem(int index);
		string& getCallsign(int index);
		double getDistance(int index);
		Table& setCallsign(const string& callsign, int index);
		Table& setDistance(double distance, int index);
		Table& setShip(Ship* ship, int index);
		Table& deleteShip(int index);
		//std::vector <Element>::iterator getIt() { return it; }
		int getSize() const { return table.size(); }
		~Table();
		Table(const Table& tab) : table(tab.table){};
		Table& operator = (const Table& tab);
		Table(Table&& tab) : table(tab.table){};
		Table& operator = (Table&& tab) {
			table = tab.table;
			return *this;
		}
		friend class TableIt;
		typedef TableIt Iterator;
		vector<Element>::iterator begin();
		vector<Element>::iterator end();
		vector<Element>::iterator cur(int index);
	};
		class TableIt {
		private:
			vector<Element>::iterator It;
		public:
			vector<Element>::iterator getIter(){ return It; }
			TableIt();
			~TableIt();
		};
	
}

