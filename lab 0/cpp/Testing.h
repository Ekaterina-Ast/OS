#pragma once
#include <vector>

class Data_Ch
{
private:
	std::vector<int> input_read_dataTxt; //âåêòîðõðàíÿùèé íîìåðà ïàêåòîâ ñ÷èòàííûõ èç ôàéëà
public:
	//óäàëåíèå äóáëèêàòîâ, ñîðòèðîâêà
	int remove_dubl(std::vector<int> input_data);
	//ïîëó÷åíèå êîëè÷åñòâà ýëåìåíòîâ â âåêòîðå
	int getLeng();
	//ïîëó÷åíèå íóæíîãî íîìåðà ïàêåòà
	int getElement(int number);
	//îïðåäåëåíèå íåäîñòîþùèõ ïàêåòîâ
	int missing_pack(std::vector<int> data_set);
	//äîáàâëåíèå â âåêòîð îáúåêòà
	int addPack(std::string pack_curr);
};
