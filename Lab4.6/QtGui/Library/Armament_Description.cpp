#include "stdafx.h"
#include "Armament_Description.h"

namespace lab4 {
	Armament_Description::Armament_Description()
	{
		ammunition = 0;
		caliber = 0;
		range_of_fire = 0;
		location = 0;
	}

	Armament_Description& Armament_Description::setAmm(int a)
	{
		ammunition = a;
		return *this;
	}

	Armament_Description& Armament_Description::setCal(double a)
	{
		caliber = a;
		return *this;
	}

	Armament_Description& Armament_Description::setRange(double a)
	{
		range_of_fire = a;
		return *this;
	}

	Armament_Description& Armament_Description::setLoc(int a)
	{
		location = a;
		return *this;
	}

	Armament_Description::~Armament_Description()
	{
	}
}
