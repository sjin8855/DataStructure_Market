#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

#include "SLL.h"
#include "DLL.h"

#define FILENAMESIZE 1024
/**
*	어플리케이션 클래스는 아이템을 간단하게 관리.
*/
class Application
{
public:
	/**
	*	디폴트 생성자.
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	소멸자.
	*/
	~Application()	{}

	/**
	*	@brief	프로그램 작동부분.
	*	@pre	프로그램 시작.
	*	@post	프로그램 종료.
	*/
	void Run();

	/**
	*	@brief	화면에 입력해야할 명령을 보여주고 키보드로 입력해준다.
	*	@pre	none.
	*	@post	none.
	*	@return	사용자의 입력.
	*/
	int GetCommand();

	/**
	*	@brief	리스트에 새로운 정보을 추가한다.
	*	@pre	리스트는 초기화되어 있다. 
	*	@post	새로운 정보은 리스트에 추가됬다.
	*	@return	이 함수가 제대로 동작했다면 1이 반환되고 아니면 0이 반환된다.
	*/
	int AddItem();

	/**
	*	@brief	리스트에 있는 모든 정보들을 화면이 출력시킨다. 
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	상품 주문
	*	@pre	없음
	*	@post	상품 주문 메뉴가 호출된다.
	*/
	void OrderItem();
	
	/**
	*	@brief	리스트에 있는 정보를 삭제한다.
	*	@pre	리스트는 초기화되어 있다. 
	*	@post	삭제 하고자 하는 아이디 정보를 가진 정보가 삭제됬다.
	*	@return	이 함수가 제대로 동작했다면 1이 반환되고 아니면 0이 반환된다.
	*/
	int Deleteitem();
	
	/**
	*	@brief	리스트에 있는 정보를 갱신한다.
	*	@pre	리스트는 초기화되어 있다. 
	*	@post	갱신 하고자 하는 아이디 정보를 가진 정보가 갱신됬다.
	*	@return	이 함수가 제대로 동작했다면 1이 반환되고 아니면 0이 반환된다.
	*/
	int Warehouse();
	/**
	*	@brief	리스트에 있는 정보들을 비운다.
	*	@pre	리스트는 초기화되어 있다. 
	*	@post	리스트가 비워졌다.
	*/
	void empty_list();


	/**
	*	@brief	아이템을 판매해준다.
	*	@pre	리스트는 초기화 되어 있다. 주문량과 총 갯수 등을 비교해준다. 그 상품을 몇개를 팔것인지 설정해준다. 
	*	@post	찾고자 하는 상품에 아이디에 맞게 아이디를 입력 하고 입력받은 갯수만큼 상품을 판매해준다. 
	*/
	void Sellitem();

	/**
	*	@brief	현재 시간을 리턴해준다.
	*	@pre	현재 시간을 가지고있다.
	*	@post	현재 시간이 입력된다.
	*	@return 현재시간
	*/
	string CurrentTime();

	/**
	*	@brief	판매 아이템을 판매리스트에 추가해준다.
	*	@pre	아이템 판매 내역이 있다. 
	*	@post	판매내역에 아이템 추가
	*/
	void add_sell(ItemType data,int count);

	/**
	*	@brief	판매내역을 모두 출력해준다.
	*	@pre	없음 
	*	@post	판매내역들 출력
	*/
	void Display_Sell();

	/**
	*	@brief	시간을 확인하여 1분이 지난 것은 삭제시킨다.
	*	@pre	현재시간과 판매시간 비교
	*	@post	1분이 지났을 시 목록삭제
	*/
	void sell_check();

	/**
	*	@brief 판매상품을 관리한다.
	*	@pre 없음.
	*	@post 상품 관리 메뉴 출력
	*/
	void print_Management();
	
	/**
	*	@brief 직전상품을 취소한다.
	*	@pre 직전 상품 구매내역이 있을시.
	*	@post 1을 입력받으면 취소, 2를 입력받을시 가만히둔다.
	*/
	void cancel_product();

	/**
	*	@brief 상품을 아이디 검색을 통해반품한다.
	*	@pre 상품 내역이 존재할 때
	*	@post 아이디와 갯수를 입력받아 반품해준다. 0개가 되면 리스트에서 지운다.
	*/
	void return_product();

	void ReadDataFromFile();
	void WriteDataToFile();
private:
	LinkedList<ItemType> m_List;		///< 아이템 리스트.
	DLL<SellItem> se_List;       /// 판매 목록 리스트
	int m_Command;			///< 현재 명령 숫자.
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
};

#endif	// _APPLICATION_H