#include "TestBoostSerialization.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

void TestBoostSerialization()
{
	BoostSerializationDemoImport *p1 = new BoostSerializationDemoImport(1, L"Equip 1");
	p1->PushStream(1001);
	p1->PushStream(1002);
	BoostSerializationDemoImport *p2 = new BoostSerializationDemoImport(2, L"Equip 2");
	p2->PushStream(2001);
	p2->PushStream(2002);
	BoostSerializationDemoDesign design(L"TestDesign");
	design.PushEquip(BoostSerializationDemoDesign::EquipPtr(p1));
	design.PushEquip(BoostSerializationDemoDesign::EquipPtr(p2));

	std::string fileName("data.txt");

	std::ofstream fout(fileName.c_str());
	boost::archive::text_oarchive oa(fout);
	oa << design;
	fout.close();

	std::ifstream fin(fileName.c_str());
	boost::archive::text_iarchive ia(fin);
	BoostSerializationDemoDesign design2(L"New  Design");
	ia >> design2;
//    design2.print();
	fin.close();
}

int main()
{
	TestBoostSerialization();
	return 0;
}

