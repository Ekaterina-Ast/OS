// Testing.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "windows.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Testing.h"
#include "algorithm"
#include <Strsafe.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "Hello, ready for work" << endl;
	std::string line;
	Data_Ch Dat_obj;

	//Для взятия файла из текущей директории data_checker.txt
	TCHAR buffer[MAX_PATH];
	TCHAR buffer2[MAX_PATH] = TEXT("\\data_checker.txt");
	GetCurrentDirectory(sizeof(buffer), buffer);
	StringCchCat(buffer, MAX_PATH, buffer2);

	// открытие файла
	std::ifstream in(buffer);
	if(in.is_open())
	{	
		//считывание построчно
		while (getline(in, line))
		{
			//для  отладки и визуализации при проверке результата
			//std::cout << line << std::endl;
			Dat_obj.addPack(line);
		}
	}

	in.close();

	for (int i = 1; i <= Dat_obj.getLeng(); i++)
	{
		std::vector<int> data_turn;
		for (int j = 0; j < i; j++)
		{
			data_turn.push_back(Dat_obj.getElement(j));
		}
		Dat_obj.remove_dubl(data_turn);
	}


	system("pause");
}

int Data_Ch::addPack(std::string pack_curr) {
	input_read_dataTxt.push_back(std::atoi(pack_curr.c_str()));
	return 0;
}

int Data_Ch::remove_dubl(std::vector<int> input_data) {
	//сортируем вектор 
	std::sort(input_data.begin(), input_data.end());
	//и удаляем дубликаты
	input_data.resize(unique(input_data.begin(), input_data.end()) - input_data.begin());
	//всё, теперь p содержит только уникальные packets
	//отправим на проверку недостающих пакетов
	missing_pack(input_data);
	return 0;
}

int Data_Ch::getLeng() {
	return input_read_dataTxt.size();
}

int Data_Ch::getElement(int number)
{
	return input_read_dataTxt[number];
}

int Data_Ch::missing_pack(std::vector<int> data_set) {
	std::vector<int> missing_pack;
	int curr_number_pack = data_set[0];
	int data_numb_index = 0;
	int k = data_set[data_set.size() - 1] - data_set[0];
	for(int i = 0; i < k; i++)
	{
		if ((data_set[data_numb_index] - curr_number_pack) >= 1){
			missing_pack.push_back(curr_number_pack);
			curr_number_pack++;
		}
		else
		{
			curr_number_pack++;
			data_numb_index++;
		}
	}
	if (missing_pack.empty())
	{
		std::cout << "Сообщение " << data_set[0] << " - " << data_set[data_set.size()-1]
			<< " получено полностью!" << std::endl;
	}
	else
	{
		std::cout << "Сообщение " << data_set[0] << " - " << data_set[data_set.size() - 1]
			<< " не хватает пакетов: ";
		for (int i = 0; i < missing_pack.size(); i++)
		{
			std::cout << missing_pack[i];
			if (i != missing_pack.size() - 1) cout << ",";
		}
			std::cout << std::endl;
	}
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
