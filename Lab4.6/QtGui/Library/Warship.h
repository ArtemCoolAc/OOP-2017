#pragma once
#include "Ship.h"
#include "Armament_Description.h"
#include "Vector.h"
//#include "Consts.h"

namespace lab4{
	class Warship : public Guard, public Transport
	{
	private:
	public:
		Warship();
		Warship& shot(int index);
		int getType() const override { return 3; }
		vctr::vector <Armament_Description>& getCannons();
		std::ostream& PrintShip(std::ostream& os) override;
		std::ostream& PrintCannons(std::ostream& os);
        friend std::ostream& operator << (std::ostream& os, Warship* ship);
		Ship* clone()  const override { return new Warship(*this); } 
		void InputShip(double mass, vctr::vector<Armament_Description>& Describer);
		~Warship();
	};
}

