// Testing.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\Library\Diagram.h"
//#include "gtest\gtest.h"
#include "..\..\googletest-master\googletest\include\gtest\gtest.h"

TEST(constructors, defaultconstructor)
{
	lab3::Diagram f;
	ASSERT_EQ(nullptr, f.getpointer());
	ASSERT_EQ(0, f.getcurq());
}


TEST(constructors, initconstructor)
{
	lab3::Diagram f('1');
	ASSERT_EQ(200, f.maxsigndur());
	ASSERT_EQ('1', f.maxsignval());
	ASSERT_ANY_THROW(lab3::Diagram t('4'));

}

TEST(constructors, init1constructor)
{
	lab3::Diagram a("10001111");
	ASSERT_EQ(3, a.getcurq());
	lab3::unit* ptr = a.getpointer();
	ASSERT_EQ('1', ptr[0].val);
	ASSERT_EQ(1, ptr[0].dur);
	ASSERT_EQ('0', ptr[1].val);
	ASSERT_EQ(3, ptr[1].dur);
	ASSERT_EQ('1', ptr[2].val);
	ASSERT_EQ(4, ptr[2].dur);
	ASSERT_ANY_THROW(lab3::Diagram d("122222"));

}

TEST(methods, parametres)
{
	char* s = nullptr;
	lab3::Diagram a("100011000111");
	lab3::Diagram b("11100011111001");
	lab3::Diagram c("0100010000110");
	ASSERT_STREQ("100011000111", a.OutStroka(s));
	delete[]s;
	s = nullptr;
	ASSERT_STREQ("11100011111001", b.OutStroka(s));
	delete[]s;
	s = nullptr;
	lab3::Diagram d = a + b;
	lab3::unit* ptr = d.getpointer();
	ASSERT_EQ(1, ptr[0].dur);
	ASSERT_EQ('1', ptr[0].val);
	ASSERT_EQ(3, ptr[1].dur);
	ASSERT_EQ('0', ptr[1].val);
	ASSERT_EQ(2, ptr[2].dur);
	ASSERT_EQ('1', ptr[2].val);
	ASSERT_EQ(3, ptr[3].dur);
	ASSERT_EQ('0', ptr[3].val);
	ASSERT_EQ(6, ptr[4].dur);
	ASSERT_EQ('1', ptr[4].val);
	ASSERT_EQ(3, ptr[5].dur);
	ASSERT_EQ('0', ptr[5].val);
	ASSERT_EQ(5, ptr[6].dur);
	ASSERT_EQ('1', ptr[6].val);
	ASSERT_EQ(2, ptr[7].dur);
	ASSERT_EQ('0', ptr[7].val);
	ASSERT_EQ(1, ptr[8].dur);
	ASSERT_EQ('1', ptr[8].val);

	lab3::Diagram e = b + c;
	lab3::unit* ptrr = e.getpointer();
	ASSERT_EQ(3, ptrr[0].dur);
	ASSERT_EQ('1', ptrr[0].val);
	ASSERT_EQ(3, ptrr[1].dur);
	ASSERT_EQ('0', ptrr[1].val);
	ASSERT_EQ(5, ptrr[2].dur);
	ASSERT_EQ('1', ptrr[2].val);
	ASSERT_EQ(2, ptrr[3].dur);
	ASSERT_EQ('0', ptrr[3].val);
	ASSERT_EQ(1, ptrr[4].dur);
	ASSERT_EQ('1', ptrr[4].val);
	ASSERT_EQ(1, ptrr[5].dur);
	ASSERT_EQ('0', ptrr[5].val);
	ASSERT_EQ(1, ptrr[6].dur);
	ASSERT_EQ('1', ptrr[6].val);
	ASSERT_EQ(3, ptrr[7].dur);
	ASSERT_EQ('0', ptrr[7].val);
	ASSERT_EQ(1, ptrr[8].dur);
	ASSERT_EQ('1', ptrr[8].val);
	ASSERT_EQ(4, ptrr[9].dur);
	ASSERT_EQ('0', ptrr[9].val);
	ASSERT_EQ(2, ptrr[10].dur);
	ASSERT_EQ('1', ptrr[10].val);
	ASSERT_EQ(1, ptrr[11].dur);
	ASSERT_EQ('0', ptrr[11].val);

	lab3::Diagram g = a.Invert();
	ptr = g.getpointer();
	ASSERT_EQ(1, ptr[0].dur);
	ASSERT_EQ('0', ptr[0].val);
	ASSERT_EQ(3, ptr[1].dur);
	ASSERT_EQ('1', ptr[1].val);
	ASSERT_EQ(2, ptr[2].dur);
	ASSERT_EQ('0', ptr[2].val);
	ASSERT_EQ(3, ptr[3].dur);
	ASSERT_EQ('1', ptr[3].val);
	ASSERT_EQ(3, ptr[4].dur);
	ASSERT_EQ('0', ptr[4].val);
	ASSERT_STREQ("011100111000", g.OutStroka(s));
	delete[]s;
	s = nullptr;
	lab3::Diagram h = a.Insert(4, b);
	ASSERT_STREQ("10001110001111100111000111", h.OutStroka(s));
	ASSERT_ANY_THROW(a.Insert(50, b));
	ASSERT_ANY_THROW(b.Insert(150, b));
	ASSERT_ANY_THROW(a.Insert(-1, b));
	delete[]s;
	s = nullptr;
	lab3::Diagram i = a.Insert(5, c);
	ASSERT_STREQ("1000101000100001101000111", i.OutStroka(s));
	delete[]s;
	s = nullptr;
	lab3::Diagram j = b.Copy(3);
	ASSERT_STREQ("111000111110011110001111100111100011111001", j.OutStroka(s));
	ASSERT_ANY_THROW(b.Copy(-5));
	ASSERT_ANY_THROW(b.Copy(20));
	delete[]s;
	s = nullptr;
	lab3::Diagram k = a.Delete(1, 3);
	ASSERT_STREQ("111000111", k.OutStroka(s));
	ASSERT_ANY_THROW(a.Delete(-1, 3));
	ASSERT_ANY_THROW(a.Delete(1, -3));
	ASSERT_ANY_THROW(a.Delete(9, 5));
	delete[]s;
	s = nullptr;
	lab3::Diagram l = b.Delete(4, 1);
	ASSERT_STREQ("1110011111001", l.OutStroka(s));
	delete[]s;
	s = nullptr;
}

int _tmain(int argc, _TCHAR* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
