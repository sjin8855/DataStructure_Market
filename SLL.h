#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "ItemType.h"

/**
*	링크드 리스트에 사용하기 위한 구조체
*/
template <typename T>
struct NodeType
{
	T data;	///< 각각의 노드가 가지고 있는 데이터
	NodeType* next;	///< 현재 노드가 가르키는 다음 노드
};


/**
*	소팅되지 않은 리스트 클래스
*/
template <typename T>
class LinkedList
{
public:
	/**
	*	디폴트 생성자
	*/
	LinkedList();     

	/**
	*	파괴자
	*/
	~LinkedList();   
	/**
	*	@brief  리스트가 가득차 있는지 확인
	*	@pre	리스트는 초기화되어 있다. 
	*	@post	리스트가 가득차 있는지 확인되었다. 
	*   @return 리스트가 가득차 있다면 true가 반환되고 아니면 false 가 반환된다. 
	*/
	bool IsFull();
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
	*	@return	이 함수가 정상 구동되었다면 1이 반환 아니면 0 반환
	*/
	int Add(T item);

	/**
	*	@brief	프라이머리 키와 같은 값이 리스트에 존재한다면 그 키 값에 관한 아이템을 반환
	*	@pre	그 키멤버를 가지는 아이템은 초기화되어있다. 
	*	@post	그 키 일치 항목의 키와 그 다음 요소의 레코드가 항목으로 복사 소자가있는 경우.
	*	@return	이 함수가 정상 구동되었다면 1이 반환 아니면 0 반환
	*/
	int Get(T& item);
	/**
	*	@brief	리스트에 아이템 삭제
	*	@pre	리스트는 가득차 있지 않고 리스트 안에 입력된 아이템이 있다. 
	*	@post	이 리스트에 아이템이 삭제되었다.
	*	@return	이 함수가 정상 구동되었다면 1이 반환 아니면 0 반환
	*/
	int Delete(T item);
	/**
	*	@brief	리스트에 아이템 대체
	*	@pre	리스트는 가득차 있지 않고 리스트 안에 입력된 아이템이 있다. 
	*	@post	이 리스트에 아이템이 대체되었다.
	*	@return	이 함수가 정상 구동되었다면 1이 반환 아니면 0 반환
	*/
	void Replace(T item);
	/**
	*	@brief	리스트에 있는 현재 포인터 값을 초기화
	*	@pre	None.
	*	@post	현재 값을 가르키는 포인터 값은 초기화되었다.
	*/
	void ResetList();

	/**
	*	@brief	리스트에 다음 요소 값을 얻는다. 
	*	@pre	현재 포인터 값은 정의되었다. 
	*	@post	현재 값을 가르키는 포인터값은 다음 값을 가르키고 아이템 값은 그 포인터값이 가르키는 아이템값으로 바뀌었다. 
	*/	
	void GetNextItem(T& item);
	
	/**
	*	@brief 상품 아이디를 입력받아 있는 그 아이디를 판매한다
	*	@pre 아이디가 있다.
	*	@post 아이디의 정보가 수정된다
	*/
	int Sell(T &data);	//상품 판매


	int Cancel_Sell(T &data, int count);
	void Set(T data);
protected:
	NodeType<T>* m_pList;	///< 첫번째 노드를 가르키는 포인터
	NodeType<T>* m_pCurPointer;	///< 현재 노드를 가르키는 포인터
	int m_nLength;	///< 리스트에 총 길이
};


// 클래스 생성자
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// 클래스 소멸자
template <typename T>
LinkedList<T>::~LinkedList()
{
	//리스트내의 모든 node 제거
	MakeEmpty();
}

// 리스트가 가득찼는지 확인
template<typename T>
bool LinkedList<T>::IsFull()
{
	NodeType<T>* location;
	try
	{
		location = new NodeType<T>;  // 메모리 할당 시도
		delete location;
		return false;   // 성공할 시 false 출력
	}
	catch(bad_alloc exception)  // 실패할 시 true 출력
	{
		return true;
	}
}
// 리스트를 비워준다.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: 모든 아이템은 할당이 해제되고 초기화
{
	// 리스트내의 모든 노드 제거 하고 리스트의 length를 초기화
	NodeType<T>* tempPtr;
	
    while (m_pList != NULL)
    {
        tempPtr = m_pList;
        m_pList = m_pList->next;
        delete tempPtr;
    }
    
	m_nLength = 0;
}


// 리스트에 길이를 반환
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}


// 리스트에 새로운 아이템 추가
template<typename T>
int LinkedList<T>::Add(T item)
{
	// 현재 포인터값 초기화
	ResetList();
	// 추가할 새로운 T 변수(노드)
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	NodeType<T>* save;
	NodeType<T>* head = m_pList;
	T dummy; // GetNextItem 을 사용해주기 위한 그냥 변수

	int count = 0; // 현재 포인터 값에 위치를 알기 위한 변수

	node->data = item;
	// 아직 리스트에 아무 값도 저장 되있지 않다면
	if(m_nLength == 0){
		node->next = NULL;
		m_pList = node;
		m_nLength++;

		return 1;
	}
	// 리스트에 다른 값이 저장되 있다면
	else
	{
		while(1)
		{	
			GetNextItem(dummy); // 포인터값 이동
			pre = m_pCurPointer; // 이전 값 저장(현재 포인터값)
		
			if(item != pre->data && item > pre->data) // 오버로딩 사용 입력받은 값과 중복 안되게 하고 소팅되게 하기 위한 구문
			{
				if(m_pCurPointer->next == NULL) // 리스트에 끝이라면
				{
					node->next = NULL;
					m_pCurPointer->next = node;
					m_nLength++;
					return 1;
				}
				count++; // 소팅을 위한 카운터 변수(현재 포인터 값을 이동시키기 위해)
			}
			else if(item < pre->data || pre == NULL){ // 들어가야할 위치를 찾았을때
				break;
			}
			if(item == pre->data){ // 중복된 값이 저장되있다면
				cout << "리스트에 중복된 저장값이 존재합니다. 다른 값을 입력하십시오. "<< endl;
				return 0;
			}
			
		}
		
		
	}
	// 현재 포인터 값 초기화
	ResetList();

	for(int i=0;i<count;i++)
	{
		GetNextItem(dummy);
		pre = m_pCurPointer;
	} // 현재 포인터 값 이동

	save = pre->next;
	pre->next = node;
	node->next = save;
	 // 저장
	m_nLength++;
	 // 리스트 크기 증가
	return 1;

}
// 리스트에 있는 아이템값을 삭제
template<typename T>
int LinkedList<T>::Delete(T item)
{
	// 현재 포인터 값 초기화 
	ResetList();
	 // Add함수와 동일
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	NodeType<T>* head = m_pList;
	T dummy;
	// 리스트에 있는 값인지 없는 값인지 체크해주기 위한 변수
	bool check = false;

	node->data = item;

	for(int i=0;i<m_nLength;i++)
	{
		GetNextItem(dummy);
		pre = m_pCurPointer;
		if(item == pre->data)
			check = true; // 값이 존재한다면
	}

	if(!check)
	{
		cout << "이 리스트에 없는 값을 입력하셨습니다. 다시 입력 부탁드립니다. " << endl;
		return 0;
	}
	ResetList();

	if(m_nLength == 0){ // 비어있다면
		cout << "리스트에 지울 데이터가 존재하지 않습니다. " << endl;
		return 0;
	}
	else
	{
		while(1)
		{		
			GetNextItem(dummy);
			pre = m_pCurPointer;
			if(pre == m_pList && item == pre->data) // 맨 처음 부분이라면
			{
				m_pList = pre->next; // 처음 값을 변화
				delete pre; // 값 삭제
				break;
			}

			if(item == pre->data)
			{
				head->next = pre->next; // 삭제될 노드 앞에 있는 노드에 next값을 변화
				delete pre; // 삭제
				break;
			}
			head = pre;
		}
	}
	m_nLength--;

	return 1;
}

template<typename T>
void LinkedList<T>::Replace(T item)
{
	NodeType<T>* node = new NodeType<T>;
	node->data = item;

	int count;

	while(1)
	{
		cout << " 입고 시킬 상품의 갯수를 입력하시오 : ";
		cin >> count;
		if(m_pCurPointer->data.GetOrderCount() >= count)
		{
			m_pCurPointer->data.SetCount(m_pCurPointer->data.GetCount() + count);
			m_pCurPointer->data.SetOrderCount(m_pCurPointer->data.GetOrderCount() - count);
			break;
		}
		else 
		{
			cout << "주문량이 입력값보다 적습니다. 다시 입력 부탁드립니다. " << endl<<endl;
		}
	}

	
}

template<typename T>
int LinkedList<T>::Get(T& item)
{ // 언소티트 Get함수랑 동일

	NodeType<T>* pre;
	NodeType<T>* node = new NodeType<T>;
	node->data = item;
	T dummy;
	ResetList();

	for(int i=0;i<m_nLength;i++)
	{
		GetNextItem(dummy);
		pre = m_pCurPointer;

		if(pre->data == item)
		{
			item = pre->data;
			return 1;
		}

	}

	return 0;

}


// 현재 값을 가르키는 포인터값을 초기화
template <typename T>
void LinkedList<T>::ResetList()
{	
	// current pointer 초기화
	m_pCurPointer = NULL;
}


// 리스트에 다음값을 반환(겟)
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	// current pointer 이 NULL이라면 처음 node를 가리킴.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position 을 다음 노드로 이동
		m_pCurPointer = m_pCurPointer->next;

	//item 에 current position 의 info 를 삽입
	item = m_pCurPointer->data;
}

// 상품을 판매해준다. 
 template<typename T>
int LinkedList<T>::Sell(T &data)
{
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	node->data = data;
	T dummy;
	int count;
	
	for(int i=0;i<m_nLength;i++)
	{
		GetNextItem(dummy);
		pre = m_pCurPointer;
		if(pre->data == data)
		{
			cout<<"\t판매할 개수를 입력하세요 : ";
			cin >> count;
			if(pre->data.GetCount() - count >= 0)
			{
				pre->data.SetTotalPrice(pre->data.GetTotalPrice()+(count*pre->data.GetPrice())); // 총 판매 금액을 설정
				pre->data.SetCount(pre->data.GetCount()-count); // 남은 갯수 설정
			}
			else
				cout << "재고가 부족합니다. " << endl;
		}
	}

	return count;
}

template<typename T>
void LinkedList<T>::Set(T data)
{
	m_pCurPointer->data = data;
}



template<typename T>
int LinkedList<T>::Cancel_Sell(T &data, int count)
{
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	node->data = data;
	T dummy;
	
	for(int i=0;i<m_nLength;i++)
	{
		GetNextItem(dummy);
		pre = m_pCurPointer;
		if(pre->data == data)
		{
			pre->data.SetTotalPrice(pre->data.GetTotalPrice()-(count*pre->data.GetPrice())); // 총 판매 금액을 설정
			pre->data.SetCount(pre->data.GetCount()+count); // 남은 갯수 설정
		}
	}

	return count;
}

#endif	// LINKED_LIST