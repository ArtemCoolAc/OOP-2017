#pragma once
#include "Ship.h"
#include "Armament_Description.h"
#include "Vector.h"
//#include "Consts.h"

namespace lab4 {
	class Guard : virtual public Ship
	{
	private:
		vctr::vector <Armament_Description> Describer;
	public:
		Guard();
		void addmem  (); // расширить вектор на 1
		void setAmm  (int ammunition, int index);
		void setCal  (int calibre,    int index);
		void setRange(int range,      int index);
		void setLoc  (int location,   int index);
		void setGun  (vctr::vector<Armament_Description>& Guns);
		// методы изменения полей описателЕЙ вооружения 
		int    getAmm   (int index);
		double getCal   (int index);
		double getRange (int index);
		int    getLoc   (int index);
		// методы получения значений полей описателЕЙ вооружения
		vctr::vector <Armament_Description>& getVec() { return Describer; }
		int getType() const override { return 1; }
		std::ostream& PrintShip(std::ostream& os) override;
		Ship* clone() const override { return new Guard(*this); } 
		void InputShip(vctr::vector<Armament_Description>& Describer);
		virtual ~Guard();
	};
}

