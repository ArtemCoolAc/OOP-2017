#include "stdafx.h"
#include "Transport.h"
#include <iostream>
#include <cmath>

namespace lab4 {
	Transport::Transport()
	{
		Ship::Ship();
		mass = 0;
		speed = Transport::getMax();
		type = 2;
	}

	Transport& Transport::Speed()
	{
		double Speed;
		double max = getMax();
		double mass = getMass();
		if (mass < 1) {
			Speed = max - mass;
		}
		else {
			Speed = max - 2*log(mass);
		}
		setSpeed(Speed);
		return *this;
	}

	Transport& Transport::setSpeed(double Speed)
	{
		speed = Speed;
		return *this;
	}

	Transport& Transport::setMass(double Mass)
	{
		mass = Mass;
		return *this;
	}

	std::ostream& Transport::PrintShip(std::ostream& os)
	{
		Ship::PrintShip(os);
		os << "Масса груза " << mass << std::endl;
		os << "Реальная скорость (зависит от массы) " << speed << std::endl;
		return os;
	}

	void Transport::InputShip(double mass)
	{
		this->mass = mass;
		Speed();
	}

	Transport::~Transport()
	{
	}
}
