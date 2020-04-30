#pragma once
#include "Table.h"

//#include "Consts.h"
namespace lab4{
	class Convoy
	{
	private:
		Table table;        // таблица участников конвоя
		Person commander;   // инормация о командующем конвоя
		string departure;    // пункт отправления
		string destination;  // пункт назначения
	public:
		Convoy();
		int count(int type);
		int size();
		int writeType(int*& arr, int type);
		Ship* GetShipInConvoy(int index);
		Table& getTable() { return table; }
		Convoy& includeShip(Element& elem);
		Convoy& deleteShip(int index);
		Convoy& modern(int index1, int index2);
		Convoy& distribute(double mass);
		Convoy& shiftMass(int index1, int index2, double mass);
		const string& getDep()  const { return departure; }
		const string& getDest() const { return destination; }
		const Person& getCapitan() const { return commander; }
		Convoy& setDep(const string& departure) { this->departure = departure; return *this; }
		Convoy& setDest(const string& destination) { this->destination = destination; return *this; }
		Convoy& setCom(Person& commander) { this->commander = commander; return *this; }
		Convoy& ReadFromFile(const string& fname);
		Convoy(const Convoy& convoy) : table(convoy.table), commander(convoy.commander), departure(convoy.departure), destination(convoy.destination) {};
		Convoy& operator = (const Convoy& convoy);
		Convoy(Convoy&& convoy) : table(convoy.table), commander(convoy.commander), departure(convoy.departure), destination(convoy.destination) {};
		Convoy& operator = (Convoy&& convoy)
		{
			table = convoy.table;
			commander = convoy.commander;
			departure = convoy.departure;
			destination = convoy.destination;
			return *this;
		}

		int Save_Convoy_in_file(const string& path);
		~Convoy();
	};
}

