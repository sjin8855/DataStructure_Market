#include "ItemType.h"


// Ű����� ���� ���̵� �Է�
void ItemType::SetIdFromKB()
{
	cout << "\tID : ";
	cin >> m_Id;
}


// Ű����� ���� �̸��� �Է�
void ItemType::SetNameFromKB()
{
	cout << "\tName : ";
	cin >> m_sName;
}


// Ű����� ���� �������ڸ� �Է�
void ItemType::SetManufacturerFromKB()
{
	cout << "\tManufacturer : ";
	cin >> m_sManufacturer;
}

// Ű����� ���� ������ �Է�
void ItemType::SetPriceFromKB()
{
	cout << "\t���� : ";
	cin >> price;
}

// Ű����� ���� ������ �Է�
void ItemType::SetCountFromKB()
{
	cout << "\t���� : ";
	cin >> m_count;
}

void ItemType::SetOrderFromKB()
{
	cout << "\t�ֹ��� : ";
	cin >> m_order_count;
}

// Ű����� ���� ��� ������ �Է�
void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetManufacturerFromKB();
	SetPriceFromKB();
	SetCountFromKB();
}


// ���Ͽ� �������� ���
int ItemType::ReadDataFromFile(ifstream& fin)
{
	fin >> m_Id;
	fin >> m_sName;
	fin >> m_sManufacturer;

	return 1;
};


// ���Ͽ� �ִ� �������� ���
int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Id << " ";
	fout << m_sName << " ";
	fout << m_sManufacturer << " ";

	return 1;
}


// ���̵𳢸� �� 
RelationType ItemType::CompareByID(const ItemType &data)
{
	if(this->m_Id > data.m_Id)
		return GREATER;
	else if(this->m_Id < data.m_Id)
		return LESS;
	else
		return EQUAL;
}


// �񱳿�����(==)
bool ItemType::operator==(const ItemType& item)
{
	if(this->m_Id == item.m_Id)
		return true;
	else
		return false;
}
// �񱳿�����(!=)
bool ItemType::operator!=(const ItemType& item)
{
	if(this->m_Id != item.m_Id)
		return true;
	else
		return false;
}
// �񱳿�����(>)
bool ItemType::operator>(const ItemType& item)
{
	if(this->m_Id > item.m_Id)
		return true;
	else
		return false;
}
// �񱳿�����(<)
bool ItemType::operator<(const ItemType& item)
{
	if(this->m_Id < item.m_Id)
		return true;
	else
		return false;
}

