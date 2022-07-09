#include "pch.h"
#include "ListController.h"


void ListController::AddCityData(CString _data)
{
	list.push_back(_data);
}

void ListController::DelCityData()
{
	//list.erase(list.begin(), list.end());
	list.clear();
}

CString ListController::GetCityData(int idx)
{
	return list.at(idx);
}

int ListController::SizeofVector()
{
	return list.size();
}

vector<CString> ListController::GetVectorData()
{
	return list;
	
}

bool ListController::VectorIs()
{
	return (bool)list.empty();
}