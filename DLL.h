#pragma once
#include "SellItem.h"

// 더블링크드 리스트에 노드를 저장하는 구조체
template<typename T>
struct DoublyNodeType
{
	T data; // 현재 아이템값
	DoublyNodeType* prev; // 이전 노드를 가르키는 포인터변수
	DoublyNodeType* next; // 다음 노드를 가르키는 포인터변수
};

// friend 함수를 사용해주기 위해 선언
template<typename T> class DLL;
// 더블링크드 리스트에서 사용할 이터레이터를 구성하는 클래스
template<typename T>
class DoublyIterator
{
	// 더블링크드 리스트를 사용해주기 위해 프렌드함수 사용
	friend class DLL<T>;

public :
	/*
	*     기본생성자(초기화리스트 사용)
	*/
	DoublyIterator(const DLL<T>& list) : m_List(list),m_pCurPointer(list.m_pFirst)
	{}; 
	/**
	*	@brief  리스트에 현재 원소가 NULL이 아닌지 검사
	*	@pre	none.
	*	@post	none.
	*   @return 리스트에 현재 원소가 NULL 이라면 false 가 리턴 아니면 true 가 리턴
	*/
	bool NotNull(); 
	/**
	*	@brief  리스트에 다음 원소가 NULL 이 아닌지 검사
	*	@pre	none.
	*	@post	none.
	*   @return 리스트에 다음 원소가 NULL 이라면 false 가 리턴 아니면 true 가 리턴
	*/
	bool NextNotNull();
	/**
	*	@brief  리스트에 처음 노드의 아이템을 리턴
	*	@pre	none.
	*	@post	none.
	*   @return 리스트에 처음 노드
	*/
	T First();
	/**
	*	@brief  다음 노드로 이동하고 해당 노드의 아이템을 리턴
	*	@pre	리스트는 초기화되어있다. 
	*	@post	다음 노드로 포인터가 이동하고 해당 노드의 아이템이 리턴되었다.
	*   @return 해당 노드의 아이템을 리턴
	*/
	T Next(); 
	/**
	*	@brief  그 전 노드로 이동하고 해당 노드의 아이템을 리턴
	*	@pre	리스트는 초기화되어있다. 
	*	@post	다음 노드로 포인터가 이동하고 해당 노드의 아이템이 리턴되었다.
	*   @return 해당 노드의 아이템을 리턴
	*/
	T Prev();
	/**
	*	@brief  현재 노드를 리턴
	*	@pre	리스트는 초기화되어있다. 
	*	@post	현재 포인터가 가르키는 노드가 리턴됨
	*   @return 현재 포인터가 가르키는 노트 리턴
	*/
	DoublyNodeType<T>* GetCurrentNode();
	/**
	*	@brief  현재 노드를 가르키는 포인터를 처음 위치로 초기화시킨다. 
	*	@pre	리스트는 초기화되어있다. 
	*	@post	포인터가 처음 위치를 가르키게 된다. 
	*/
	void ResetList();

private :
	const DLL<T>& m_List; // 사용할 리스트의 참조 변수
	DoublyNodeType<T>* m_pCurPointer; // iterator 변수
};
// 더블링크드리스트 클래스
template<typename T>
class DLL
{
	// 이터레이터를 사용하기 위한 프렌드 함수 
	friend class DoublyIterator<T>;
public :
	/*
	*     기본생성자
	*/
	DLL();
	/*
	*    소멸자
	*/
	~DLL();
	/**
	*	@brief  리스트가 가득차 있는지 확인
	*	@pre	리스트는 초기화되어 있다. 
	*	@post	리스트가 가득차 있는지 확인되었다. 
	*   @return 리스트가 가득차 있다면 true가 반환되고 아니면 false 가 반환된다. 
	*/
	bool isFull();
	/**
	*	@brief	리스트를 비워준다.
	*	@pre	None
	*	@post	리스트는 비어졌다.
	*/
	void MakeEmpty();
	/**
	*	@brief	리스트에 총 길이를 얻는다.
	*	@pre	None.
	*	@post	함수값 = 리스트에 총 길이
	*	@return	이 리스트에 총 길이 반환
	*/
	int GetLength() const;
	/**
	*	@brief	리스트에 아이템 추가
	*	@pre	리스트는 가득차 있지 않고 리스트 안에 입력된 아이템이 없다. 
	*	@post	이 리스트에 아이템이 추가되었다.
	*   @prama  추가될 아이템
	*	@return	이 함수가 정상 구동되었다면 1이 반환 아니면 0 반환
	*/
	int Add(T item);
	/**
	*	@brief	리스트에 아이템 삭제
	*	@pre	리스트는 가득차 있지 않고 리스트 안에 입력된 아이템이 있다. 
	*	@post	이 리스트에 아이템이 삭제되었다.
	*   @param  삭제될 아이템에 이터레이터
	*/
	void Delete(DoublyIterator<T> file);

	/**
	*	@brief	프라이머리 키와 같은 값이 리스트에 존재한다면 그 키 값에 관한 아이템을 반환
	*	@pre	그 키멤버를 가지는 아이템은 초기화되어있다. 
	*	@post	그 키 일치 항목의 키와 그 다음 요소의 레코드가 항목으로 복사 소자가있는 경우.
	*   @param  변환될 아이템 (획득할)
	*	@return	이 함수가 정상 구동되었다면 1이 반환 아니면 0 반환
	*/
	int Get(T item);
	/**
	*	@brief	리스트에 다음 요소 값을 얻는다. 
	*	@pre	현재 포인터 값은 정의되었다. 
	*	@post	현재 값을 가르키는 포인터값은 다음 값을 가르키고 아이템 값은 그 포인터값이 가르키는 아이템값으로 바뀌었다. 또한 count 값은 1이 증가하게된다.
	*   @param  다음 노드가 가르키는 아이템값인 T& item 과 그 다음에 들어오게 될때 그 다음 인덱스를 정해줄 count 값
	*/
	void GetNextItem(T item,int& count);
	/**
	*	@brief  리스트에 첫번째 노드값을 반환
	*	@pre	리스트는 초기화되어 있다. 
	*	@post	리스트에 첫번쨰 노드값을 반환받았다.  
	*   @return 리스트에 첫번째 노드값 
	*/
	DoublyNodeType<T>* Get_first();

private :
	DoublyNodeType<T>* m_pFirst; // 리스트에 처음 노드를 가리키는 포인터
	DoublyNodeType<T>* m_pLast; // 리스트에 마지막 노드를 가리키는 포인터
	int m_nLength; // 리스트에 저장된 레코드 수
};

// 기본생성자
template<typename T>
DLL<T>::DLL()
{
	m_pFirst = NULL; // 초기화 
	m_pLast = NULL;
	m_pFirst = new DoublyNodeType<T>; // 동적할당
	m_pLast = new DoublyNodeType<T>;
	m_pFirst->next = m_pLast; // dummy node 를 만들어주는 과정 
	m_pLast->next = NULL;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_nLength = 0;
}
// 소멸자
template<typename T>
DLL<T>::~DLL()
{
	MakeEmpty(); // 리스트를 비워준다. 
}

// 다음 노드가 가르키는 아이템값을 얻는다. 
template<typename T>
void DLL<T>::GetNextItem(T item,int& count)
{
	DoublyIterator<T> itor(*this);
	itor.ResetList(); // 현재 노드 초기화
	if(count == 0){ // 첫번째 위치라면 
		itor.Next();
		item = itor.GetCurrentNode()->data; // 첫번째 위치에 있는 아이템값으로 변환
		count++; // 카운트값 증가
		return ;
	}
	else
	{
		int i=0;
		while(i<count)
		{
			itor.Next(); // 카운트만큼 현재노드를 이동시켜준다. 
			i++;
		}
		count = i+1;
		itor.Next();
		item = itor.GetCurrentNode()->data; // 현재 노드가 가르키는 아이템으로 변환
		return ;
	}
}
// 리스트가 가득찼는지 확인
template<typename T>
bool DLL<T>::isFull()
{
	DoublyNodeType<T>* location;
	try
	{
		location = new DoublyNodeType<T>;  // 메모리 할당 시도
		delete location;
		return false;   // 성공할 시 false 출력
	}
	catch(bad_alloc exception)  // 실패할 시 true 출력
	{
		return true;
	}
}
// 리스트에 새로운 아이템 추가
template<typename T>
int DLL<T>::Add(T item)
{
	if(isFull()) // 가득차있다면
	{
		cout << " 리스트가 가득차있습니다. " << endl;
	}
	else // 아니라면
	{
		DoublyNodeType<T>* pItem  = new DoublyNodeType<T>; // 입력받은 아이템을 저장할 새로운 더블링크드객체
		DoublyIterator<T> itor(*this);
		pItem->data = item;

		itor.ResetList(); // 현재 노드 초기화

		if(m_nLength == 0) // 리스트에 저장된 값이 없다면
		{
			DoublyNodeType<T>* save; // 노드에 새로운 값을 저장하는 과정
			save = itor.GetCurrentNode();
			pItem->prev = save;
			pItem->next = save->next;
			save->next->prev = pItem;
			save->next = pItem;
			m_nLength++;
			return 1;
		}

		while(itor.GetCurrentNode()->next != m_pLast) // 소팅되지 않았으므로 맨 마지막 위치로 이터레이터 이동
		{
			itor.Next();
		}

		DoublyNodeType<T>* save; // 아이템 추가
		save = itor.GetCurrentNode();
		pItem->prev = save;
		pItem->next = save->next;
		save->next->prev = pItem;
		save->next = pItem;


		m_nLength++;
		return 1;
	}
}
// 리스트에 아이템 삭제
template<typename T>
void DLL<T>::Delete(DoublyIterator<T> file)
{
	file.GetCurrentNode()->prev->next = file.GetCurrentNode()->next;
	file.GetCurrentNode()->next->prev = file.GetCurrentNode()->prev;

	//해당 node를 삭제
	m_nLength--;


}
// 아이디 정보만 가지고 있는 아이템값에 위치를 찾아서 그 아이템위치에 정보를 반환해준다. 
template<typename T>
int DLL<T>::Get(T item)
{
	DoublyIterator<T> itor(*this);
	itor.ResetList();
	DoublyNodeType<T>* pItem  = new DoublyNodeType<T>;
	pItem->data = item;
	int i=0;
	while(i<m_nLength){
		itor.Next(); // 현재 노드의 위치 이동
		if(itor.GetCurrentNode()->data == pItem->data)
			break;
		i++;
	}

	if(i == m_nLength)
		return 0;

	item = itor.GetCurrentNode()->data;
	return 1;

}

// 리스트의 길이 반환
template<typename T>
int DLL<T>::GetLength() const
{
	return m_nLength;
}
// 리스트를 비워준다. 
template<typename T>
void DLL<T>::MakeEmpty()
{
	if(m_nLength != 0){
		DoublyNodeType<T>* pItem;
		DoublyIterator<T> itor(*this);
		itor.ResetList();
		itor.Next();
		while(itor.NotNull())
		{
			pItem = itor.GetCurrentNode();
			itor.Next();
			delete pItem;
		}

		m_pFirst = m_pLast = NULL;
		return ;
	}

	m_pFirst = m_pLast = NULL;

}
// 현재 노드값이 NULL 인지 아닌지 비교
template<typename T>
bool DoublyIterator<T>::NotNull()
{
	if(m_pCurPointer == NULL) // NULL 이면 false 리턴
		return false;
	else
		return true;
}
// 다음 노드값이  NULL 인지 아닌지 비교
template<typename T>
bool DoublyIterator<T>::NextNotNull()
{
	DoublyNodeType<T>* pre;
	pre = m_pCurPointer;
	if(pre->next == NULL)
		return false;
	else
		return true;
}
// 리스트에 첫번째 노드값에 있는 데이터값 리턴
template<typename T>
T DoublyIterator<T>::First()
{
	return m_List.m_pFirst->data;
}
// 현재 노드를 다음 노드로 이동
template<typename T>
T DoublyIterator<T>::Next()
{
	if(m_pCurPointer == NULL)
		m_pCurPointer = m_List.m_pFirst;
	else
		m_pCurPointer = m_pCurPointer->next;

	return m_pCurPointer->data;
}
// 현재 노드를 이전 노드로 이동 
template<typename T>
T DoublyIterator<T>::Prev()
{
	if(m_pCurpointer == NULL)
		m_pCurPointer = m_List.m_pFirst;
	else
		m_pCurPointer = m_pCurPointer->prev;

	return m_pCurPointer->data;
}
// 현재 노드값을 리턴
template<typename T>
DoublyNodeType<T>* DoublyIterator<T>::GetCurrentNode()
{
	return m_pCurPointer;
}
// 현재 노드값을 처음 위치로 이동
template<typename T>
void DoublyIterator<T>::ResetList()
{
	m_pCurPointer = m_List.m_pFirst;
}

