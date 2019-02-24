#pragma once
#include <vector>


class Data_Ch
{
private:
	std::vector<int> input_read_dataTxt; //векторхранящий номера пакетов считанных из файла
public:
	//удаление дубликатов, сортировка
	int remove_dubl(std::vector<int> input_data);
	//получение количества элементов в векторе
	int getLeng();
	//получение нужного номера пакета
	int getElement(int number);
	//определение недостоющих пакетов
	int missing_pack(std::vector<int> data_set);
	//добавление в вектор объекта
	int addPack(std::string pack_curr);
};