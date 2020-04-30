// Testing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Library\lemniscate.h"
#include "..\..\googletest-master\googletest-master\googletest\include\gtest\gtest.h"

TEST(lemniscateconstructors, DefaultConstructor) {
	lemniscate::lemniscate l;
	ASSERT_EQ(0, l.getC());
	ASSERT_EQ(0, l.getM());
}

TEST(lemniscateconstructorm, Initconstructor) {
	lemniscate::lemniscate l1(2,4);
	ASSERT_EQ(2, l1.getC());
	ASSERT_EQ(4, l1.getM());
}

TEST(lemniscateMethods, Setters) {
	lemniscate::lemniscate l2(3, 4);
	l2.setcm(5, 6);
	ASSERT_EQ(5, l2.getC());
	ASSERT_EQ(6, l2.getM());
	l2.setcm(-5, -6);
	ASSERT_EQ(-5, l2.getC());
	ASSERT_EQ(-6, l2.getM());
}

TEST(lemniscateMethods, Parametres) {
	lemniscate::lemniscate l3(1, 1);
	const double pi = 4 * atan(1.0); double err = 0.000001;
	ASSERT_EQ(-1, l3.type());
	ASSERT_NEAR(pi / 3 + 0.5*sqrt(3), l3.square(), err);
	lemniscate::lemniscate l4(5, sqrt(2));
	ASSERT_NEAR(5 * pi, l4.square(), err);
	ASSERT_EQ(1, l4.type());
	lemniscate::lemniscate l5;
	ASSERT_NEAR(0, l5.square(), err);
	ASSERT_EQ(0, l5.type());
	ASSERT_NEAR(9, (l4.trans().a)*(l4.trans().a), err);
	ASSERT_NEAR(1, (l4.trans().b)*(l4.trans().b), err);
	ASSERT_NEAR(3, (l3.trans().a)*(l3.trans().a), err);
	ASSERT_NEAR(1, (l3.trans().b)*(l3.trans().b), err);
	lemniscate::lemniscate l6(1/sqrt(2),2);
	ASSERT_NEAR(0, l6.ro(60), err);
	lemniscate::lemniscate l7(5, 6);
	ASSERT_STREQ("po^2 = 77.00 * (cos(a)) ^ 2 - 67.00 * (sin(a)) ^ 2", l7.text());
	ASSERT_STREQ("po^2 = 0", l5.text());
}


int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	
}

