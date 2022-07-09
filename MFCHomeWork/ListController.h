#pragma once
#include <vector>
using namespace std;

class ListController
{
private:
	vector <CString> list;

public:
	ListController(){};
	void AddCityData(CString _data);
	void DelCityData();
	CString GetCityData(int idx);
	int SizeofVector();
	bool VectorIs();
	vector <CString> GetVectorData();


	
};