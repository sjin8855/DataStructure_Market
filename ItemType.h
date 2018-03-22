
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*	�� ������ ���� ����(���̵�)
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	������ ���� Ŭ����
*/
class ItemType
{
public:
	/**
	*	����Ʈ ������
	*/
	ItemType()
	{
		m_Id = -1;
		m_sName = "";
		m_sManufacturer = "";
		price = 0;
		m_count = 0;
		m_order_count = 0;
		m_total_price = 0;
	}

	/**
	*	�Ҹ���
	*/
	~ItemType()	{}

	/**
	*	@brief	������ ���̵� ����
	*	@pre	������ ���̵� �Է�
	*	@post	none.
	*	@return	������ ���̵� ��ȯ.
	*/
	int GetId()
	{
		return m_Id;
	}

	/**
	*	@brief	������ �̸��� ����
	*	@pre	������ �̸� �Է�
	*	@post	none.
	*	@return	������ �̸�.
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	������ �̸� ����.
	*	@pre	������ �̸� �Է�.
	*	@post	none.
	*	@return	������ �̸� ��ȯ.
	*/
	string GetManufacturer()
	{
		return m_sManufacturer;
	}

	/**
	*	@brief	��ǰ ������ ����.
	*	@pre	��ǰ ������ �Է�.
	*	@post	none.
	*	@return	��ǰ ���� ��ȯ.
	*/
	int GetPrice()
	{
		return price;
	}

	/**
	*	@brief	��ǰ ������ ����.
	*	@pre	��ǰ ���� �Է�.
	*	@post	none.
	*	@return	��ǰ ���� ��ȯ.
	*/
	int GetCount()
	{
		return m_count;
	}

	/**
	*	@brief	�ֹ� ���� ����.
	*	@pre	�ֹ� ���� �Է�.
	*	@post	none.
	*	@return	�ֹ� ���� ��ȯ.
	*/
	int GetOrderCount()
	{
		return m_order_count;
	}

	/**
	*	@brief	�Ѱ踦 ����.
	*	@pre	�Ѱ� �Է�.
	*	@post	none.
	*	@return	�Ѱ� ��ȯ.
	*/
	int GetTotalPrice()
	{
		return m_total_price;
	}

	/**
	*	@brief	������ ���̵� �Է�.
	*	@pre	none.
	*	@post	������ ���̵� �Է�.
	*	@param	inId ������ ���̵�.
	*/
	void SetId(int inId)
	{
		m_Id = inId;
	}
	
	/**
	*	@brief	������ �̸� �Է�.
	*	@pre	none.
	*	@post	������ �̸� �Է�.
	*	@param	inName ������ �̸� .
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}
	
	/**
	*	@brief	������ �̸� �Է�.
	*	@pre	none.
	*	@post	������ �̸� �Է�.
	*	@param	inManufacturer ������ �̸�.
	*/
	void SetManufacturer(string inManufacturer)
	{
		m_sManufacturer = inManufacturer;
	}
	/**
	*	@brief	��ǰ ���� �Է�.
	*	@pre	none.
	*	@post	��ǰ ���� �Է�.
	*	@param	inPrice ���� .
	*/

	void SetPrice(int inPrice)
	{
		price = inPrice;
	}

	/**
	*	@brief	��ǰ ���� �Է�.
	*	@pre	none.
	*	@post	��ǰ ���� �Է�.
	*	@param	inCount ��ǰ ���� .
	*/
	void SetCount(int inCount)
	{
		m_count = inCount;
	}

	/**
	*	@brief	�Ѱ� �Է�.
	*	@pre	none.
	*	@post	�Ѱ� �Է�.
	*	@param	inPrice �Ѱ�.
	*/
	void SetTotalPrice(int inPrice)
	{
		m_total_price = inPrice;
	}

	/**
	*	@brief	�ֹ� ���� �Է�.
	*	@pre	none.
	*	@post	�ֹ� ���� �Է�.
	*	@param	inCount �ֹ� ����.
	*/
	void SetOrderCount(int inCount)
	{
		m_order_count = inCount;
	}
	

	/**
	*	@brief	������ ���� ����.
	*	@pre	none.
	*	@post	������ ���� �Է�.
	*	@param	inId ������ ���̵�.
	*	@param	inName ������ �̸�.
	*	@param	inManufacturer ������ �̸�.
	*	@param	inCount ��ǰ ���� .
	*	@param	inPrice ���� .
	*/
	void SetRecord(int inId, string inName, string inManufacturer, int inPrice, int inCount,int order_count,int total_price)
	{
		SetId(inId);
		SetName(inName);
		SetManufacturer(inManufacturer);
		SetPrice(inPrice);
		SetCount(inCount);
		SetOrderCount(order_count);
		SetTotalPrice(total_price);
	}

	/**
	*	@brief	ȭ�鿡 ������ ���̵� ���.
	*	@pre	������ ���̵� �Է�.
	*	@post	ȭ�鿡 ������ ���̵� ���.
	*/
	void DisplayIdOnScreen() 
	{
		cout << "\tID   : " << m_Id << endl; 
	};

	/**
	*	@brief	ȭ�鿡 ������ �̸� ���.
	*	@pre	������ �̸� �Է�.
	*	@post	ȭ�鿡 ������ �̸� ���.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\tName : " << m_sName << endl; 
	};

	/**
	*	@brief	ȭ�鿡 ������ �̸� ���.
	*	@pre	������ �̸� �Է�.
	*	@post	ȭ�鿡 ������ �̸� ���.
	*/
	void DisplayManufacturerOnScreen() 
	{
		cout << "\tManufacturer : " << m_sManufacturer << endl; 
	};

	/**
	*	@brief	ȭ�鿡 ������ ���� ���.
	*	@pre	������ ���� �Է�.
	*	@post	ȭ�鿡 ������ ���� ���.
	*/
	void DisplayPriceOnScreen() 
	{
		cout << "\t����   : " << price << endl; 
	};
	/**
	*	@brief	ȭ�鿡 ������ ���� ���.
	*	@pre	������ ���̵� �Է�.
	*	@post	ȭ�鿡 ������ ���� ���.
	*/
	void DisplayCountOnScreen() 
	{
		cout << "\t����   : " << m_count << endl; 
	};
	/**
	*	@brief	ȭ�鿡 �ֹ��� ���.
	*	@pre	�ֹ��� �Է�.
	*	@post	ȭ�鿡 �ֹ��� ���.
	*/
	void DisplayOrderOnScreen() 
	{
		cout << "\t�ֹ���   : " << m_order_count << endl; 
	};
	/**
	*	@brief	ȭ�鿡 �Ѱ� ���.
	*	@pre	�Ѱ� �Է�.
	*	@post	ȭ�鿡 �Ѱ� ���.
	*/
	void DisplayTotalPriceOnScreen() 
	{
		cout << "\t�Ѱ�   : " << m_total_price << endl; 
	};
	/**
	*	@brief	ȭ�鿡 ������ ��� ������ ���.
	*	@pre	������ ������ �Է�.
	*	@post	ȭ�鿡 ������ ��� ������ ���.
	*/
	void DisplayRecordOnScreen()
	{
		DisplayIdOnScreen();
		DisplayNameOnScreen();
		DisplayManufacturerOnScreen();
		DisplayPriceOnScreen();
		DisplayCountOnScreen();
		DisplayOrderOnScreen();
		DisplayTotalPriceOnScreen();
		cout << endl;
	};

	/**
	*	@brief	Ű����κ��� ������ ���̵� �Է�.
	*	@pre	none.
	*	@post	������ ���̵� �Է�.
	*/
	void SetIdFromKB();

	/**
	*	@brief	Ű����κ��� ������ �̸� �Է�.
	*	@pre	none.
	*	@post	������ �̸� �Է�.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Ű����κ��� ������ �̸� �Է�.
	*	@pre	none.
	*	@post	������ �̸� �Է�.
	*/
	void SetManufacturerFromKB();
	/**
	*	@brief	Ű����κ��� ������ ���� �Է�.
	*	@pre	none.
	*	@post	������ ���� �Է�.
	*/
	void SetPriceFromKB();
	/**
	*	@brief	Ű����κ��� ������ ���� �Է�.
	*	@pre	none.
	*	@post	������ ���� �Է�.
	*/
	void SetCountFromKB();

	/**
	*	@brief	Ű����κ��� �ֹ��� �Է�.
	*	@pre	none.
	*	@post	�ֹ��� �Է�.
	*/
	void SetOrderFromKB();
	/**
	*	@brief	Ű����κ��� ������ ��� ���� �Է�.
	*	@pre	none.
	*	@post	������ ��� ���� �Է�.
	*/

	void SetRecordFromKB();

	/**
	*	@brief	���Ϸκ��� ���� �б�.
	*	@pre	Ÿ�� ������ ����.
	*	@post	������ ���� �Է�.
	*	@param	fin ���� ������.
	*	@return	�� �Լ��� ���� �۵� �ɰ�� 1 ��ȯ �ƴϸ� 0��ȯ.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	���Ͽ� �������� ���.
	*	@pre	Ÿ�� ������ �� ��, ����Ʈ�� �ʱ�ȭ.
	*	@post	Ÿ�� ������ ���ο� �������� ���Ե��ִ�..
	*	@param	fout ���� ������.
	*	@return	�� �Լ��� ���� �۵� �ɰ�� 1 ��ȯ �ƴϸ� 0��ȯ.
	*/
	int WriteDataToFile(ofstream& fout);
	
	/**
	*	�ΰ��� ������ Ÿ���� ���� ������ ���̵� ��.
	*	@brief	2���� ������ ���̵� ��.
	*	@pre	�ΰ��� ������ Ÿ���� �ʱ�ȭ.
	*	@post	Ÿ�� ������ ���ο� ����Ʈ �������� �����ϰ� �ִ�.
	*	@param	data ���� Ÿ�� ������.
	*	@return	���� this.id < data.id��� LESS��ȯ, 
	*			���� this.id > data.id��� GREATER ��ȯ
	*			��������� EQUAL ��ȯ.
	*/
	RelationType CompareByID(const ItemType &data);

	/**
	*	@brief	id���� ���ϴ� ������ �����ε�(==)
	*	@pre	none.
	*	@post	�� id���� �񱳵Ǿ���.
	*	@param	const ItemType �� ���۷��� ���� item
	*	@return	�� �Լ��� ���� �۵� �ɰ�� 1(true) ��ȯ �ƴϸ� 0(false)��ȯ.
	*/
	bool operator==(const ItemType& item);
	/**
	*	@brief	id���� ���ϴ� ������ �����ε�(!=)
	*	@pre	none.
	*	@post	�� id���� �񱳵Ǿ���.
	*	@param	const ItemType �� ���۷��� ���� item
	*	@return	�� �Լ��� ���� �۵� �ɰ�� 1(true) ��ȯ �ƴϸ� 0(false)��ȯ.
	*/
	bool operator!=(const ItemType& item);
	/**
	*	@brief	id���� ���ϴ� ������ �����ε�(>)
	*	@pre	none.
	*	@post	�� id���� �񱳵Ǿ���.
	*	@param	const ItemType �� ���۷��� ���� item
	*	@return	�� �Լ��� ���� �۵� �ɰ�� 1(true) ��ȯ �ƴϸ� 0(false)��ȯ.
	*/
	bool operator>(const ItemType& item);
	/**
	*	@brief	id���� ���ϴ� ������ �����ε�(<)
	*	@pre	none.
	*	@post	�� id���� �񱳵Ǿ���.
	*	@param	const ItemType �� ���۷��� ���� item
	*	@return	�� �Լ��� ���� �۵� �ɰ�� 1(true) ��ȯ �ƴϸ� 0(false)��ȯ.
	*/
	bool operator<(const ItemType& item);
	


protected:
	int m_Id;				///< ������ ���̵�.
	string m_sName;			///< ������ �̸�.
	string m_sManufacturer;	///< ������ �̸�.
	int price;              /// ����
	int m_count;            /// ����
	int m_order_count;		///< �ֹ� ����
	int m_total_price;		///< �Ѱ�
};

#endif	// _ITEMTYPE_H
