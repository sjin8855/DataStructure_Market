
#ifndef _ITEMTYPE_H
#define _ITEMTYPE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
*	두 아이템 간에 관계(아이디)
*/
enum RelationType {LESS, GREATER, EQUAL};


/**
*	아이템 정보 클래스
*/
class ItemType
{
public:
	/**
	*	디폴트 생성자
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
	*	소멸자
	*/
	~ItemType()	{}

	/**
	*	@brief	아이템 아이디를 얻음
	*	@pre	아이템 아이디 입력
	*	@post	none.
	*	@return	아이템 아이디 반환.
	*/
	int GetId()
	{
		return m_Id;
	}

	/**
	*	@brief	아이템 이름을 얻음
	*	@pre	아이템 이름 입력
	*	@post	none.
	*	@return	아이템 이름.
	*/
	string GetName()
	{
		return m_sName;
	}

	/**
	*	@brief	제조업 이름 얻음.
	*	@pre	제조업 이름 입력.
	*	@post	none.
	*	@return	제조업 이름 반환.
	*/
	string GetManufacturer()
	{
		return m_sManufacturer;
	}

	/**
	*	@brief	상품 가격을 얻음.
	*	@pre	상품 가격을 입력.
	*	@post	none.
	*	@return	상품 가격 반환.
	*/
	int GetPrice()
	{
		return price;
	}

	/**
	*	@brief	상품 수량을 얻음.
	*	@pre	상품 수량 입력.
	*	@post	none.
	*	@return	상품 수량 반환.
	*/
	int GetCount()
	{
		return m_count;
	}

	/**
	*	@brief	주문 갯수 얻음.
	*	@pre	주문 갯수 입력.
	*	@post	none.
	*	@return	주문 갯수 반환.
	*/
	int GetOrderCount()
	{
		return m_order_count;
	}

	/**
	*	@brief	총계를 얻음.
	*	@pre	총계 입력.
	*	@post	none.
	*	@return	총계 반환.
	*/
	int GetTotalPrice()
	{
		return m_total_price;
	}

	/**
	*	@brief	아이템 아이디 입력.
	*	@pre	none.
	*	@post	아이템 아이디 입력.
	*	@param	inId 아이템 아이디.
	*/
	void SetId(int inId)
	{
		m_Id = inId;
	}
	
	/**
	*	@brief	아이템 이름 입력.
	*	@pre	none.
	*	@post	아이템 이름 입력.
	*	@param	inName 아이템 이름 .
	*/
	void SetName(string inName)
	{
		m_sName = inName;
	}
	
	/**
	*	@brief	제조업 이름 입력.
	*	@pre	none.
	*	@post	제조업 이름 입력.
	*	@param	inManufacturer 제조업 이름.
	*/
	void SetManufacturer(string inManufacturer)
	{
		m_sManufacturer = inManufacturer;
	}
	/**
	*	@brief	상품 가격 입력.
	*	@pre	none.
	*	@post	상품 가격 입력.
	*	@param	inPrice 가격 .
	*/

	void SetPrice(int inPrice)
	{
		price = inPrice;
	}

	/**
	*	@brief	상품 갯수 입력.
	*	@pre	none.
	*	@post	상품 갯수 입력.
	*	@param	inCount 상품 갯수 .
	*/
	void SetCount(int inCount)
	{
		m_count = inCount;
	}

	/**
	*	@brief	총계 입력.
	*	@pre	none.
	*	@post	총계 입력.
	*	@param	inPrice 총계.
	*/
	void SetTotalPrice(int inPrice)
	{
		m_total_price = inPrice;
	}

	/**
	*	@brief	주문 갯수 입력.
	*	@pre	none.
	*	@post	주문 갯수 입력.
	*	@param	inCount 주문 갯수.
	*/
	void SetOrderCount(int inCount)
	{
		m_order_count = inCount;
	}
	

	/**
	*	@brief	아이템 정보 저장.
	*	@pre	none.
	*	@post	아이템 정보 입력.
	*	@param	inId 아이템 아이디.
	*	@param	inName 아이템 이름.
	*	@param	inManufacturer 제조업 이름.
	*	@param	inCount 상품 갯수 .
	*	@param	inPrice 가격 .
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
	*	@brief	화면에 아이템 아이디 출력.
	*	@pre	아이템 아이디 입력.
	*	@post	화면에 아이템 아이디 출력.
	*/
	void DisplayIdOnScreen() 
	{
		cout << "\tID   : " << m_Id << endl; 
	};

	/**
	*	@brief	화면에 아이템 이름 출력.
	*	@pre	아이템 이름 입력.
	*	@post	화면에 아이템 이름 출력.
	*/
	void DisplayNameOnScreen() 
	{
		cout << "\tName : " << m_sName << endl; 
	};

	/**
	*	@brief	화면에 제조업 이름 출력.
	*	@pre	제조업 이름 입력.
	*	@post	화면에 제조업 이름 출력.
	*/
	void DisplayManufacturerOnScreen() 
	{
		cout << "\tManufacturer : " << m_sManufacturer << endl; 
	};

	/**
	*	@brief	화면에 아이템 가격 출력.
	*	@pre	아이템 가격 입력.
	*	@post	화면에 아이템 가격 출력.
	*/
	void DisplayPriceOnScreen() 
	{
		cout << "\t가격   : " << price << endl; 
	};
	/**
	*	@brief	화면에 아이템 수량 출력.
	*	@pre	아이템 아이디 입력.
	*	@post	화면에 아이템 수량 출력.
	*/
	void DisplayCountOnScreen() 
	{
		cout << "\t수량   : " << m_count << endl; 
	};
	/**
	*	@brief	화면에 주문량 출력.
	*	@pre	주문량 입력.
	*	@post	화면에 주문량 출력.
	*/
	void DisplayOrderOnScreen() 
	{
		cout << "\t주문량   : " << m_order_count << endl; 
	};
	/**
	*	@brief	화면에 총계 출력.
	*	@pre	총계 입력.
	*	@post	화면에 총계 출력.
	*/
	void DisplayTotalPriceOnScreen() 
	{
		cout << "\t총계   : " << m_total_price << endl; 
	};
	/**
	*	@brief	화면에 아이템 모든 정보들 출력.
	*	@pre	아이템 정보들 입력.
	*	@post	화면에 아이템 모든 정보들 출력.
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
	*	@brief	키보드로부터 아이템 아이디 입력.
	*	@pre	none.
	*	@post	아이템 아이디 입력.
	*/
	void SetIdFromKB();

	/**
	*	@brief	키보드로부터 아이템 이름 입력.
	*	@pre	none.
	*	@post	아이템 이름 입력.
	*/
	void SetNameFromKB();

	/**
	*	@brief	키보드로부터 제조업 이름 입력.
	*	@pre	none.
	*	@post	제조업 이름 입력.
	*/
	void SetManufacturerFromKB();
	/**
	*	@brief	키보드로부터 아이템 가격 입력.
	*	@pre	none.
	*	@post	아이템 가격 입력.
	*/
	void SetPriceFromKB();
	/**
	*	@brief	키보드로부터 아이템 수량 입력.
	*	@pre	none.
	*	@post	아이템 수량 입력.
	*/
	void SetCountFromKB();

	/**
	*	@brief	키보드로부터 주문량 입력.
	*	@pre	none.
	*	@post	주문량 입력.
	*/
	void SetOrderFromKB();
	/**
	*	@brief	키보드로부터 아이템 모든 정보 입력.
	*	@pre	none.
	*	@post	아이템 모든 정보 입력.
	*/

	void SetRecordFromKB();

	/**
	*	@brief	파일로부터 정보 읽기.
	*	@pre	타겟 파일을 연다.
	*	@post	아이템 정보 입력.
	*	@param	fin 파일 기입자.
	*	@return	이 함수가 정상 작동 될경우 1 반환 아니면 0반환.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	파일에 정보들을 기록.
	*	@pre	타겟 파일을 연 후, 리스트를 초기화.
	*	@post	타겟 파일은 새로운 정보들이 포함되있다..
	*	@param	fout 파일 기입자.
	*	@return	이 함수가 정상 작동 될경우 1 반환 아니면 0반환.
	*/
	int WriteDataToFile(ofstream& fout);
	
	/**
	*	두개의 아이템 타입을 가진 아이템 아이디 비교.
	*	@brief	2개의 아이템 아이디를 비교.
	*	@pre	두개의 아이템 타입을 초기화.
	*	@post	타겟 파일은 새로운 리스트 정보들을 포함하고 있다.
	*	@param	data 비교할 타겟 아이템.
	*	@return	만약 this.id < data.id라면 LESS반환, 
	*			만약 this.id > data.id라면 GREATER 반환
	*			나머지라면 EQUAL 반환.
	*/
	RelationType CompareByID(const ItemType &data);

	/**
	*	@brief	id값을 비교하는 연산자 오버로딩(==)
	*	@pre	none.
	*	@post	두 id값은 비교되었다.
	*	@param	const ItemType 에 레퍼런스 변수 item
	*	@return	이 함수가 정상 작동 될경우 1(true) 반환 아니면 0(false)반환.
	*/
	bool operator==(const ItemType& item);
	/**
	*	@brief	id값을 비교하는 연산자 오버로딩(!=)
	*	@pre	none.
	*	@post	두 id값은 비교되었다.
	*	@param	const ItemType 에 레퍼런스 변수 item
	*	@return	이 함수가 정상 작동 될경우 1(true) 반환 아니면 0(false)반환.
	*/
	bool operator!=(const ItemType& item);
	/**
	*	@brief	id값을 비교하는 연산자 오버로딩(>)
	*	@pre	none.
	*	@post	두 id값은 비교되었다.
	*	@param	const ItemType 에 레퍼런스 변수 item
	*	@return	이 함수가 정상 작동 될경우 1(true) 반환 아니면 0(false)반환.
	*/
	bool operator>(const ItemType& item);
	/**
	*	@brief	id값을 비교하는 연산자 오버로딩(<)
	*	@pre	none.
	*	@post	두 id값은 비교되었다.
	*	@param	const ItemType 에 레퍼런스 변수 item
	*	@return	이 함수가 정상 작동 될경우 1(true) 반환 아니면 0(false)반환.
	*/
	bool operator<(const ItemType& item);
	


protected:
	int m_Id;				///< 아이템 아이디.
	string m_sName;			///< 아이템 이름.
	string m_sManufacturer;	///< 제조업 이름.
	int price;              /// 가격
	int m_count;            /// 수량
	int m_order_count;		///< 주문 갯수
	int m_total_price;		///< 총계
};

#endif	// _ITEMTYPE_H
