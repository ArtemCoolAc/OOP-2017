#pragma once
#include "Ship.h"
//#include "Consts.h"

namespace lab4 {
	class Transport : virtual public Ship
	{
	private:
		double mass;
		double speed;
	public:
		Transport();
		Transport& Speed(); // метод расчета (или пересчета) скорости судна в зависимости от массы груза
		double getMass() const  { return mass;  }
		double getSpeed() const { return speed; }
		// методы получения значений полей транспортного судна
		Transport& setSpeed (double speed);
		Transport& setMass  (double mass);
		// методы изменения значений полей транспортного судна
		int getType() const override { return 2; }
		std::ostream& PrintShip(std::ostream& os) override;
		void InputShip(double mass);
		//Ship* clone(Ship* shipFrom, Ship* shipTo) override;
		Ship* clone() const override { return new Transport(*this); } 
		virtual ~Transport();
	};
}

