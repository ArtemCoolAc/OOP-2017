#include "..\..\googletest-master\googletest-master\googletest\include\gtest\gtest_prod.h"
#include <math.h>

namespace lemniscate {

	struct parameters {
		double a;
		double b;
	};

	class lemniscate
	{
	private:
		double c, m;
	public:
		lemniscate(double c = 0, double m = 0);
		parameters trans();
		double getC() const { return c; }
		double getM() const { return m; }
		lemniscate& setcm(double c, double m);
		int type();
		double square();
		//parameters x = trans(3.0, 5.0)
		//~lemniscate();
		double ro(double phi);
		char* text();

	};
}

