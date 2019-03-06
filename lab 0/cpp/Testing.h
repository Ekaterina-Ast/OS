#pragma once
#include <vector>

class Data_Ch
{
private:
	std::vector<int> input_read_dataTxt; //вектор хранящий номера пакетов считанных из файла
public:
	//удаление дубликатов, сортироввка
	int remove_dubl(std::vector<int> input_data);
	//получение количества элементов в векторе
	int getLeng();
	//получение нужного номера пакета
	int getElement(int number);
	//определение недостающих пакетов
	int missing_pack(std::vector<int> data_set);
	//добавление в вектор объекта
	int addPack(std::string pack_curr);
};
