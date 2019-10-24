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
	return hash % max_hash_table_size; // если мне выдадут номер €чейки которой нет то € получу ошибку
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
	int shift = getHash(key); // получаем фактический адресс в таблице по ключевому параметру
	(ptr + shift)->dataF = DataF; // найд€ нужный элемент в массиве мы измен€ем его €чейки на нужные нам
	(ptr + shift)->dataI = DataI;
}

void main()
{
	string str1 = "Hello", str2 = "Bie";
	//std::cout << getHash(str1) << "\n" << getHash(str2) << std::endl;
	const int max_hash_table_size = 255;
	dataType table[max_hash_table_size]{ 0 }; // обрати внимание, количество €чеек в таблице не больше 255

	SetDataByValue(str1, table, 1, 1.1f);
	SetDataByValue(str2, table, 2, 2.2f);

	std::cout << GetDataByValue(str1, table)->dataI << std::endl; // € мен€ю только ключ
	std::cout << GetDataByValue(str2, table)->dataI << std::endl;
}