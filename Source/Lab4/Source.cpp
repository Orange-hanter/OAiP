#include <iostream>
#include <string>
using std::string;

int getHash( string str, const int max_hash_table_size = 255 ) 
{
	int hash = 0;
	for (auto charIndex = 0; charIndex < str.length(); charIndex++)
	{
		hash += int( str[charIndex] );
	}
	return hash % max_hash_table_size; // ���� ��� ������� ����� ������ ������� ��� �� � ������ ������
}

struct dataType
{
	int dataI;
	float  dataF;
};

dataType* GetDataByValue(string key, dataType* ptr)
{
	int shift = getHash(key);
	return (ptr + shift);
}

void SetDataByValue(string key, dataType* ptr, int DataI, float DataF)
{
	int shift = getHash(key); // �������� ����������� ������ � ������� �� ��������� ���������
	(ptr + shift)->dataF = DataF; // ����� ������ ������� � ������� �� �������� ��� ������ �� ������ ���
	(ptr + shift)->dataI = DataI;
}

void main()
{
	string str1 = "Hello", str2 = "Bie";
	//std::cout << getHash(str1) << "\n" << getHash(str2) << std::endl;
	const int max_hash_table_size = 255;
	dataType table[max_hash_table_size]{ 0 }; // ������ ��������, ���������� ����� � ������� �� ������ 255

	SetDataByValue(str1, table, 1, 1.1f);
	SetDataByValue(str2, table, 2, 2.2f);

	std::cout << GetDataByValue(str1, table)->dataI << std::endl; // � ����� ������ ����
	std::cout << GetDataByValue(str2, table)->dataI << std::endl;
}