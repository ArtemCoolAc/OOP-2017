#pragma once

namespace lab4 {
	class Armament_Description {
	private:
		int ammunition;       //боезапас
		double caliber;       //калибр
		double range_of_fire; //дальность стрельбы
		int location;         //расположение
	public:
		Armament_Description();

		Armament_Description& setAmm   (int ammunition);
		Armament_Description& setCal   (double calibre);
		Armament_Description& setRange (double range_of_fire);
		Armament_Description& setLoc   (int location);
		// методы изменения значений полей описателя вооружения
		int    getAmm()   { return ammunition;    }
		double getCal()   { return caliber;       }
		double getRange() { return range_of_fire; }
		int    getLoc()   { return location;      }
		// методы получения значений полей описателя вооружения
		~Armament_Description();
	};
}

