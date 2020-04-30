#include "stdafx.h"
#include "Convoy.h"
#include "Consts.h"
#include <fstream>


namespace lab4{
	Convoy::Convoy() :table()
	{
//		Table::Table();
	}

	int Convoy::count(int type)
	{
		int q = 0;
		//Table& tabl = getTable();
		vector<Element>::iterator iter = table.begin();
		vector<Element>::iterator end = table.end();
		int size = table.getSize();
		for (int i = 0; i<size; ++iter) {
			if (iter->ship->getType() == type) q++;
			++i;
		}
		
		return q;
	}

	int Convoy::size()
	{
		int size = table.getSize();
		return size;
	}

	int Convoy::writeType(int*& array, int type)
	{
		int i = 0; int ind = 0;
		Table& tabl = getTable();
		vector<Element>::iterator iter = table.begin();
		vector<Element>::iterator end = table.end();
		int size = tabl.getSize();
		for (int i = 0; i<size; ++iter) {
			if (iter->ship->getType() == type)  {
				array[ind] = i;
				++ind;
			}
			++i;
		}
		return ind;
	}

	Ship* Convoy::GetShipInConvoy(int index)
	{
		vector<Element> tabl = table.getVec();
		vector<Element>::iterator iter = table.cur(index);
		return iter->ship;
	}

	Convoy& Convoy::includeShip(Element& elem)
	{
		table.includeElem(elem);
		return *this;
	}

	Convoy& Convoy::deleteShip(int index)
	{
		table.deleteElem(index);
		return *this;
	}

	Convoy& Convoy::modern(int index1, int index2)
	{
		vector<Element> tabl = table.getVec();
		vector<Element>::iterator iter1 = table.cur(index1);
		vector<Element>::iterator iter2 = table.cur(index2);
		Warship* warship = dynamic_cast <Warship*> (iter2->ship);
		Transport* transport = dynamic_cast <Transport*> (iter1->ship);
		vector<Armament_Description>& from = warship->getVec();
		Warship* war = new Warship;
		war->setGun(from);
		war->setMass(transport->getMass());
		war->setMax(transport->getMax());
		war->Speed();
		war->setDra(transport->getDra());
		war->setQuan(transport->getQuan());
		war->setShipName(transport->getShipName());
		war->setCap(transport->getCapRank(), transport->getCapName(), transport->getCapFamily(), transport->getCapPatronymic(), transport->getCapExperience());
		delete iter1->ship;
		table.setShip(war, index1);
		return *this;
	}

	Convoy& Convoy::distribute(double mass)
	{
		int size = count(2);
		double mps = mass / size;
		vector<Element>::iterator iter = table.begin();
		vector<Element>::iterator end = table.end(); int i = 0;
		Table& tabl = getTable();
		int size1 = tabl.getSize();
		for (int i = 0; i < size1; ++iter) {
		int type = iter->ship->getType();
			if (type == 2) {
				Transport* transport = dynamic_cast <Transport*> (iter->ship);
				double newmass = transport->getMass() + mps;
				transport->setMass(newmass);
				transport->Speed();
			}
			++i;
		}
		return *this;
	}

	Convoy& Convoy::shiftMass(int index1, int index2, double mass)
	{
		vector<Element>::iterator iter1 = table.cur(index1);
		vector<Element>::iterator iter2 = table.cur(index2);
		Transport* tran1 = dynamic_cast <Transport*> (iter1->ship);
		Transport* tran2 = dynamic_cast <Transport*> (iter2->ship);
		Ship* tran11 = tran1->clone();
		Ship* tran22 = tran2->clone();
		Transport* tran111 = dynamic_cast<Transport*> (tran11);
		Transport* tran222 = dynamic_cast<Transport*> (tran22);
		double s1 = tran1->getMass();
		s1 -= mass;
		if (s1 < 0) { 
			std::cout << "Нехорошо отбирать то, чего нет" << std::endl; 
			return *this;
		}
		tran111->setMass(s1);
		tran111->Speed();
		double s2 = tran222->getMass();
		s2 += mass;
		tran222->setMass(s2);
		tran222->Speed();
		table.deleteShip(index1);
		table.deleteShip(index2);
		table.setShip(tran111, index1);
		table.setShip(tran222, index2);
		return *this;
	}

	Convoy& Convoy::ReadFromFile(const string& fname)
	{
		std::ifstream file;
		file.open(fname);
		Person commander;
		string buf1, buf2, buf3, buf4, buf5, buf6; int exp;
		getline(file, buf1);
		setDep(buf1);
		getline(file, buf2);
		setDest(buf2);
		getline(file, buf3);
		commander.setFamily(buf3);
		getline(file, buf4);
		commander.setName(buf4);
		getline(file, buf5);
		commander.setPatronymic(buf5);
		getline(file, buf6);
		commander.setRank(buf6);
		file >> exp;
		commander.setExp(exp);
		setCom(commander);
		int size;
		file >> size; file.ignore(1, '\n');
		for (int i = 0; i < size; ++i)
		{
			string buf; double dist;
			getline(file, buf);
			file >> dist;
			Ship* ship = nullptr;
			int type;
			file >> type;
			int draught; int quantity; double max_speed; string ship_name; Person capitan;
			file >> draught;
			file >> quantity;
			file >> max_speed; file.ignore(1, '\n');
			getline(file, ship_name);
			string family, name, patr, rank; int exp;
			getline(file, family);
			getline(file, name);
			getline(file, patr);
			getline(file, rank);
			file >> exp;
			capitan.setFamily(family);
			capitan.setName(name);
			capitan.setPatronymic(patr);
			capitan.setRank(rank);
			capitan.setExp(exp);
			if (type == 1) {
				ship = new Guard;
				ship->InputShip(draught, quantity, max_speed, ship_name, capitan);
				Guard* ship1 = dynamic_cast <Guard*> (ship);
				int num; file >> num;
				vector<Armament_Description> describer(num);
				vector<Armament_Description>::iterator iter = describer.begin();
				for (int i = 0; i < num; ++i) {
					int amm; double cal, range; int loc;
					file >> amm;
					iter->setAmm(amm);
					file >> cal;
					iter->setCal(cal);
					file >> range;
					iter->setRange(range);
					file >> loc;
					iter->setLoc(loc);
					++iter;
				}
				ship1->setGun(describer);
			}
			if (type == 2) {
				ship = new Transport;
				ship->InputShip(draught, quantity, max_speed, ship_name, capitan);
				Transport* ship2 = dynamic_cast <Transport*> (ship);
				double mass;
				file >> mass;
				ship2->InputShip(mass);
			}

			if (type == 3) {
				ship = new Warship;
				ship->InputShip(draught, quantity, max_speed, ship_name, capitan);
				Warship* ship3 = dynamic_cast <Warship*> (ship);
				int num; file >> num;
				vector<Armament_Description> describer(num);
				vector<Armament_Description>::iterator iter = describer.begin();
				for (int i = 0; i < num; ++i) {
					int amm; double cal, range; int loc;
					file >> amm;
					iter->setAmm(amm);
					file >> cal;
					iter->setCal(cal);
					file >> range;
					iter->setRange(range);
					file >> loc;
					iter->setLoc(loc);
					++iter;
				}
				double mass;
				file >> mass;
				ship3->InputShip(mass, describer);
			}
			Ship* shipTo = nullptr;
			shipTo = ship->clone();
			delete ship;

			Element elem(shipTo, buf, dist);
			table.includeElem(elem);
			file.ignore(1, '\n');
		}
		file.close();
		return *this;
	}

	Convoy& Convoy::operator=(const Convoy& convoy)
	{
		table = convoy.table;
		commander = convoy.commander;
		departure = convoy.departure;
		destination = convoy.destination;
		return *this;
	}

	int Convoy::Save_Convoy_in_file(const string&str1)
	{
			std::ofstream file;
			string str; int exp;
			file.open(str1);
			str = getDep();
			file << str << '\n';
			str = getDest();
			file << str << '\n';
			Person cap = getCapitan();
			str = cap.getFamily();
			file << str << '\n';
			str = cap.getName();
			file << str << '\n';
			str = cap.getPatr();
			file << str << '\n';
			str = cap.getRank();
			file << str << '\n';
			exp = cap.getExperience();
			file << exp << '\n';
			int size = this->size();
			file << size << '\n';
			for (int i = 0; i < size; ++i)
			{
				string buf; double dist;
				buf = getTable().cur(i)->callsign;
				file << buf << '\n';
				dist = getTable().cur(i)->distance;
				file << dist << '\n';
				Ship* ship = nullptr;
				ship = getTable().cur(i)->ship;
				int type = ship->getType();
				file << type << '\n';
				int draught; int quantity; double max_speed; string ship_name; Person capitan;
				draught = ship->getDra();
				file << draught << '\n';
				quantity = ship->getQuan();
				file << quantity << '\n';
				max_speed = ship->getMax();
				file << max_speed << '\n';
				ship_name = ship->getShipName();
				file << ship_name << '\n';
				capitan = ship->getCap();
				string family, name, patr, rank; int exp;
				file << capitan.getFamily() << '\n';
				file << capitan.getName() << '\n';
				file << capitan.getPatr() << '\n';
				file << capitan.getRank() << '\n';
				file << capitan.getExperience() << '\n';
				if (type == 1) {
					Guard* ship1 = dynamic_cast <Guard*> (ship);
					int num = ship1->getVec().size();
					file << num << '\n';
					vector<Armament_Description> Describer = ship1->getVec();
					vector<Armament_Description>::iterator iter = Describer.begin();
					for (int i = 0; i < num; ++i) {
						int amm; double cal, range; int loc;
						amm = iter->getAmm();
						file << amm << '\n';
						cal = iter->getCal();
						file << cal << '\n';
						range = iter->getRange();
						file << range << '\n';
						loc = iter->getLoc();
						file << loc << '\n';
						++iter;
					}
				}
				if (type == 2) {
					Transport* ship2 = dynamic_cast <Transport*> (ship);
					double mass = ship2->getMass();
					file << mass << '\n';
				}

				if (type == 3) {
					Warship* ship3 = dynamic_cast <Warship*> (ship);
					int num = ship3->getVec().size();
					file << num << '\n';
					vector<Armament_Description> Describer = ship3->getVec();
					vector<Armament_Description>::iterator iter = Describer.begin();
					for (int i = 0; i < num; ++i) {
						int amm; double cal, range; int loc;
						amm = iter->getAmm();
						file << amm << '\n';
						cal = iter->getCal();
						file << cal << '\n';
						range = iter->getRange();
						file << range << '\n';
						loc = iter->getLoc();
						file << loc << '\n';
						++iter;
					}
					double mass = ship3->getMass();
					file << mass << '\n';
				}
			}
			file.close();
			return 1;
		}


	Convoy::~Convoy()
	{
	}
}
