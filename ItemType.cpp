#include "ItemType.h"


// 키보드로 부터 아이디를 입력
void ItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> m_Id;
}


// 키보드로 부터 이름을 입력
void ItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}


// 키보드로 부터 제조업자를 입력
void ItemType::SetManufacturerFromKB()
{
	cout << "\tManufacturer : ";
	cin >> m_sManufacturer;
}

// 키보드로 부터 가격을 입력
void ItemType::SetPriceFromKB()
{
	cout << "\t가격 : ";
	cin >> price;
}

// 키보드로 부터 수량을 입력
void ItemType::SetCountFromKB()
{
	cout << "\t수량 : ";
	cin >> m_count;
}

void ItemType::SetOrderFromKB()
{
	cout << "\t주문량 : ";
	cin >> m_order_count;
}

// 키보드로 부터 모든 정보를 입력
void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetManufacturerFromKB();
	SetPriceFromKB();
	SetCountFromKB();
}


// 파일에 정보들을 기록
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Id;
	fin >> m_sName;
	fin >> m_sManufacturer;

	return 1;
};


// 파일에 있는 정보들을 출력
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Id << " ";
	fout << m_sName << " ";
	fout << m_sManufacturer << " ";

	return 1;
}


// 아이디끼리 비교 
RelationType ItemType::CompareByID(const ItemType &data)
{
	if(this->m_Id > data.m_Id)
		return GREATER;
	else if(this->m_Id < data.m_Id)
		return LESS;
	else
		return EQUAL;
}


// 비교연산자(==)
bool ItemType::operator==(const ItemType& item)
{
	if(this->m_Id == item.m_Id)
		return true;
	else
		return false;
}
// 비교연산자(!=)
bool ItemType::operator!=(const ItemType& item)
{
	if(this->m_Id != item.m_Id)
		return true;
	else
		return false;
}
// 비교연산자(>)
bool ItemType::operator>(const ItemType& item)
{
	if(this->m_Id > item.m_Id)
		return true;
	else
		return false;
}
// 비교연산자(<)
bool ItemType::operator<(const ItemType& item)
{
	if(this->m_Id < item.m_Id)
		return true;
	else
		return false;
}

