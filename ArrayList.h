#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
#include <time.h>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 100

/** 
*	매우 단순한 비정렬 리스트 배열
*/
template<typename T>
class ArrayList
{
public:
	/**
	*	디폴트 생성자
	*/
	ArrayList()
	{
		m_Length = 0;
		ResetList();
		m_Array = new T [MAXSIZE];
	}

	/**
	*	소멸자
	*/
	~ArrayList()	{}

	/**
	*	@brief	리스트를 비운다.
	*	@pre	none.
	*	@post	리스트 비움.
	*/
	void MakeEmpty();

	/**
	*	@brief	현재 리스트에 길이를 얻는다. 
	*	@pre	none.
	*	@post	none.
	*	@return	현재 리스트에 길이를 반환
	*/
	int GetLength();

	/**
	*	@brief	리스트에 용량이 가득 찼는지 확인.
	*	@pre	none.
	*	@post	none.
	*	@return	리스트에 아직 공간이 있다면 true를 반환, 아니면 false를 반환.
	*/
	bool IsFull();

	/**
	*	@brief	리스트에 새로운 데이터를 추가.
	*	@pre	리스트를 초기화 시킨다. 
	*	@post	리스트에 새로운 데이터가 추가.
	*	@param	data	새로운 데이터.
	*	@return	이 함수가 정상적으로 작동할 경우 1이 반환되고 아니면 0이 반환된다. 
	*/
	virtual int Add(ItemType data);

	/**
	*	@brief	리스트 반복자 초기화.
	*	@pre	리스트는 초기화 되어야 한다. 
	*	@post	반복자가 리셋됨.
	*/
	void ResetList();

	/**
	*	@brief	반복자에 현재 위치를 다음 위치로 이동 시키고 그 위치에 있는 데이터를 얻는다. 
	*	@pre	리스트와 리스트 반복자는 초기화 되면 안된다. 
	*	@post	반복자는 다음 아이템 위치로 이동한다. 
	*	@param	data	현재 반복자의 아이템을 얻는다. 그것은 초기화 될 필요가 없다.
	*	@return	현재 반복자의 위치가 리스트에 끝이라면 -1을 반환하고 아니면 그 반복자의 위치를 반환.
	*/
	int GetNextItem(ItemType& data);

	/**
	*	@brief	반복자에 현재 위치를 다음 위치로 이동 시키고 변수로 받은 데이터에 아이디와 그 반복자 위치에 있는 아이디를 비교하여 같은 곳에 위치를 반환한다. 
	*	@pre	리스트와 리스트 반복자는 초기화 되면 안된다. 
	*	@post	입력 받은 데이터와 같은 정보를 가진 반복자가 반환된다. 
	*	@param	data	현재 반복자의 아이템을 얻는다. 그것은 초기화 될 필요가 없다.
	*	@return	현재 반복자의 위치가 리스트에 끝이라면 -1을 반환하고 아니면 그 반복자의 위치를 반환.
	*/
	virtual int Get(ItemType& data);

	/**
	*	@brief	반복자를 이동시켜 그 반복자 위치에 있는 정보와 입력 받은 데이터에 정보를 비교하여 같으면 그 반복자가 위치해 있는 정보를 삭제하고 리스트를 정렬시킨다. 
	*	@pre	리스트와 리스트 반복자는 초기화 되면 안된다. 
	*	@post	반복자의 위치에 있는 정보가 삭제된다. 
	*	@param	data	현재 반복자의 아이템을 얻는다. 그것은 초기화 될 필요가 없다.
	*   @return 이 함수가 정상 실행 될 경우 1이 리턴되고 아니면 0이 리턴된다. 
	*/
	virtual int Delete(ItemType data);

	/**
	*	@brief	반복자에 위치에 있는 정보를 입력 받은 데이터에 정보로 갱신시킨다.
	*	@pre	리스트와 리스트 반복자는 초기화 되면 안된다. 
	*	@post	반복자에 위치에 있는 정보가 갱신된다. 
	*	@param	data	현재 반복자의 아이템을 얻는다. 그것은 초기화 될 필요가 없다.
	*/
	void Replace(ItemType data);

	/**
	*	@brief	iteration 을 이용해 list를 검색한다.
	*	@pre	리스트는 초기화되어 있다. 
	*	@post	찾고자 하는 이름을 가진 정보들이 출력된다. 
	*   @param inData 찾고자 하는 이름을 가진 Itemtype 이 들어온다. 
	*/
	void SearchListByName(ItemType& inData);

	void Set(ItemType data);

protected:
	T* m_Array;  ///< 리스트 배열.
	int m_Length;				///< 리스트의 길이 .
	int m_CurPointer;			///< 반복자 포인터.
};

// 리스트를 비운다.
template<typename T>
void ArrayList<T>::MakeEmpty()
{
	m_Length = 0;
}


//현재 리스트에 길이 반환
template<typename T>
int ArrayList<T>::GetLength()
{
	return m_Length;
}


// 리스트가 가득 찼는지 안 찼는지 비교
template<typename T>
bool ArrayList<T>::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// 리스트에 새로운 데이터 추가
template<typename T>
int ArrayList<T>::Add(ItemType inData)
{
	if(!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

	return 1;
}


// 리스트에 반복자 초기화
template<typename T>
void ArrayList<T>::ResetList()
{
	m_CurPointer = -1;
}


// 반복자를 다음 위치에 아이템으로 이동시킨다.
template<typename T>
int ArrayList<T>::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer 증가
	if(m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}
// 입력 받은 데이터에 반복자를 위치 시킨다.
template<typename T>
int ArrayList<T>::Get(ItemType& data)
{
	
	for(int i=0;i<m_Length;i++)
	{
		m_CurPointer++;
		if(m_Array[i].CompareByID(data) == EQUAL)
			break;
		if(i == m_Length-1)
			return -1;
	}
	data = m_Array[m_CurPointer];
	return m_CurPointer;
}
// 입력 받은 데이터가 있는 곳으로 반복자를 이동시키고 그 정보를 삭제시킨다.
template<typename T>
int ArrayList<T>::Delete(ItemType data)
{
	for(int i=0;i<m_Length;i++)
	{
		m_CurPointer++;
		if(m_Array[i].CompareByID(data) == EQUAL)
			break;
		if(i==m_Length-1)
			return 0;
	}
	for(int i=m_CurPointer;i<m_Length-1;i++)
	{
		m_Array[i].SetRecord(m_Array[i+1].GetId(),m_Array[i+1].GetName(),m_Array[i+1].GetManufacturer(),m_Array[i+1].GetPrice(),m_Array[i+1].GetCount(),m_Array[i+1].GetOrderCount(),m_Array[i+1].GetOrderCount()*m_Array[i+1].GetPrice());
	}
	m_Array[m_Length].SetRecord(0,"","",0,0,0,0);
	m_Length--;
	return 1;
}
// 현재 반복자가 위치에 있는 곳에 정보를 갱신시킨다. 
template<typename T>
void ArrayList<T>::Replace(ItemType data)
{
	int count; // 입고 시킬 총 갯수 


	while(1){
		cout << " 입고 시킬 상품의 갯수를 입력하시오 : ";
		cin >> count;
		if(m_Array[m_CurPointer].GetOrderCount() >= count ){
			m_Array[m_CurPointer].SetCount(m_Array[m_CurPointer].GetCount() + count);
			m_Array[m_CurPointer].SetOrderCount(m_Array[m_CurPointer].GetOrderCount() - count);
			break;
		}
		else
		{
			cout << "주문량이 입력값보다 적습니다 다시 입력 부탁드립니다. " << endl;
		}
	}

}
// 입력받은 data와 같은 이름을 가진 아이디들을 출력
template<typename T>
void ArrayList<T>::SearchListByName(ItemType& inData)
{
	while(m_CurPointer != m_Length) // 리스트에 끝에 도달할떄까지
	{
		m_CurPointer++;
		if(m_Array[m_CurPointer].GetName().find(inData.GetName()) != string::npos) // string 비교문 조건에 맞는 string이 있다면 들어가고 아니면 패스
		{
			m_Array[m_CurPointer].DisplayIdOnScreen();
		}
	}
}

template<typename T>
void ArrayList<T>::Set(ItemType data)
{
	m_Array[m_CurPointer] = data;
}

#endif	// _UNSORTEDLIST_H