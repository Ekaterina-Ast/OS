#pragma once
#include <vector>


class Data_Ch
{
private:
	std::vector<int> input_read_dataTxt; //�������������� ������ ������� ��������� �� �����
public:
	//�������� ����������, ����������
	int remove_dubl(std::vector<int> input_data);
	//��������� ���������� ��������� � �������
	int getLeng();
	//��������� ������� ������ ������
	int getElement(int number);
	//����������� ����������� �������
	int missing_pack(std::vector<int> data_set);
	//���������� � ������ �������
	int addPack(std::string pack_curr);
};