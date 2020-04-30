#include "stdafx.h"
#include "lemniscate.h"
#include <string.h>
#include <stdio.h>

namespace lemniscate {
	const double pi = 4 * atan(1.0);

	lemniscate::lemniscate(double c, double m):c(c), m(m) {}

	parameters lemniscate::trans() {
		double c = lemniscate::c;
		double m = lemniscate::m;
		parameters x;
		x.a = sqrt(fabsf(2 * m * m + c));
		x.b = sqrt(fabsf(c - 2 * m * m));
		if (c < 2 * m * m) x.b = -x.b;
		return x;
	}

	lemniscate& lemniscate::setcm(double c0, double m0) {
		c = c0; m = m0;
		return *this;
	}

	int lemniscate::type() {
		double c = lemniscate::c;
		double m = lemniscate::m;
		if ((m == 0) && (c == 0)) return 0;
		if (c > 2 * m * m) return 1;
		return -1;
	}

	double lemniscate::square() {
		double c = lemniscate::c;
		double m = lemniscate::m;
		double square;
		parameters x = trans();
		x.b = fabsf(x.b);
		int t = type();
		if (t == 0) return 0;
		else {
			if (t == 1) square = 0.5*pi*((x.a)*(x.a) + (x.b)*(x.b));
			if (t == -1) square = 0.5*((x.a)*(x.a) - (x.b)*(x.b))*atan(x.a / x.b) + (x.a)*(x.b) / 2;
		}
		return square;
	}

	double lemniscate::ro(double phi) {
		double c = lemniscate::c; double ro;
		double m = lemniscate::m;
		parameters x = trans();
		int t = type();
		double al = phi* pi / 180;
		double r1 = (x.a)*(x.a)*cos(al)*cos(al)+t*(x.b)*(x.b)*sin(al)*sin(al);
		if (r1 < 0) ro = 0;
		else ro = sqrt(r1);
		return ro;
	}

	char* lemniscate::text() {
		double c = lemniscate::c;
		double m = lemniscate::m;
		char num[20]; int l = 0; int k = 0;
		parameters x = trans();
		int t = type();
		if (t == 0) {
			char* s1 = "po^2 = 0";
			 l = strlen(s1) + 1;
			char* s = new char[l];
			sprintf_s(s, l, s1);
			return s;
		}
		else {
			char* s1 = "po^2 = ";
			char* s2 = " * (cos(a)) ^ 2";
			char* s3 = " * (sin(a)) ^ 2";
			sprintf_s(num, 20, s1);
			l += strlen(s1);
			sprintf_s(num, 20, "%.2f", x.a*x.a);
			l += strlen(num);
				if (x.b == 0) {
					sprintf_s(num, 20, s2);
					l += strlen(s2);
				}
				else {
					sprintf_s(num, 20, "%.2f", x.b*x.b);
					l += strlen(num);
					sprintf_s(num, 20, s3);
					l += strlen(s3);
					sprintf_s(num, 20, s2);
					l += strlen(s2);
					if (t == 1) {
						sprintf_s(num, 20, " + ");
						l += strlen(" + ");
					}
					else {
						sprintf_s(num, 20, " - ");
						l += strlen(" - ");
					}
				}
				l++;
			char* s = new char[l];
			sprintf_s(s, l, s1);
			k = strlen(s);
			sprintf_s(s + k, l - k, "%.2f", x.a*x.a);
			k = strlen(s);
			sprintf_s(s+k, l-k, s2);
			k = strlen(s);
			if (t == 1) {
				sprintf_s(s + k, l - k, " + ");
				k = strlen(s);
				sprintf_s(s + k, l - k, "%.2f", fabsf(x.b*x.b));
				k = strlen(s);
				sprintf_s(s + k, l - k, s3);

			}
			else {
				if (x.b != 0) sprintf_s(s+k, l-k, " - ");
				k = strlen(s);
				sprintf_s(s + k, l - k, "%.2f", fabsf(x.b*x.b));
				k = strlen(s);
				sprintf_s(s+k, l-k, s3);
			}
			return s;
		}
		return num;
	}
	
}