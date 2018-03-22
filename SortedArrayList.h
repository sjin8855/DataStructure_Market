#include "ArrayList.h"
#pragma once // 중복 방지
/**
*   매우 단순한 정렬 리스트 배열
*/
template<typename T>
class SortedArrayList : public ArrayList<T>
{
public : 
	/**
	*    디폴트 생성자
	*/
	SortedArrayList();
	/**
	*    소멸자
	*/
	~SortedArrayList();
	/**
	*	@brief	리스트에 새로운 데이터를 정렬하여 추가.
	*	@pre	리스트를 초기화 시킨다. 
	*	@post	리스트에 새로운 데이터가 추가.
	*	@param	data	새로운 데이터.
	*	@return	이 함수가 정상적으로 작동할 경우 1이 반환되고 아니면 0이 반환된다. 
	*/
	int Add(ItemType data);
	/**
	*	@brief	반복자에 현재 위치를 다음 위치로 이동 시키고 변수로 받은 데이터에 아이디와 그 반복자 위치에 있는 아이디를 비교하여 같은 곳에 위치를 반환한다. 
	*	@pre	리스트와 리스트 반복자는 초기화 되면 안된다. 
	*	@post	입력 받은 데이터와 같은 정보를 가진 반복자가 반환된다. 
	*	@param	data	현재 반복자의 아이템을 얻는다. 그것은 초기화 될 필요가 없다.
	*	@return	현재 반복자의 위치가 리스트에 끝이라면 -1을 반환하고 아니면 그 반복자의 위치를 반환.
	*/
	int Get(ItemType& target);
	/**
	*	@brief	반복자를 이동시켜 그 반복자 위치에 있는 정보와 입력 받은 데이터에 정보를 비교하여 같으면 그 반복자가 위치해 있는 정보를 삭제하고 리스트를 정렬시킨다. 
	*	@pre	리스트와 리스트 반복자는 초기화 되면 안된다. 
	*	@post	반복자의 위치에 있는 정보가 삭제된다. 
	*	@param	data	현재 반복자의 아이템을 얻는다. 그것은 초기화 될 필요가 없다.
	*   @return 이 함수가 정상 실행 될 경우 1이 리턴되고 아니면 0이 리턴된다. 
	*/
	int Delete(ItemType data);

	/**
	*	@brief 상품 아이디를 입력받아 있는 그 아이디를 판매한다
	*	@pre 아이디가 있다.
	*	@post 아이디의 정보가 수정된다
	*/
	void Sell(ItemType data);	//상품 판매

};



//디폴트 생성자
template<typename T>
SortedArrayList<T>::SortedArrayList()
{
	m_Length = 0;
}
// 소멸자
template<typename T>
SortedArrayList<T>::~SortedArrayList()
{
}
// 리스트에 원하는 데이터를 추가(정렬)
template<typename T>
int SortedArrayList<T>::Add(ItemType item)
{
	if(!IsFull()){ // 리스트가 가득차지 않았다면
		ResetList();
		ItemType data;
		GetNextItem(data);
		bool check ;
		check = (m_CurPointer < m_Length); // while 문을 돌리기위한 조건 변수

		if(m_Length == 0) // 첫번쨰 위치라면
		{
			m_Array[m_Length] = item;
			m_Length++;
		}
		else 
		{
			while(check){
				switch(item.CompareByID(m_Array[m_CurPointer])) // 아이디에 크기를 비교하여 소팅 시키기 위해서
				{
				case LESS :
					check = false;
					break;
				case GREATER :
					GetNextItem(data);
					check = (m_CurPointer < m_Length);
					break;
				}
			}
			for (int index = m_Length ; index > m_CurPointer ; index--) // 소팅
				m_Array[index] = m_Array[index-1];
			m_Array[m_CurPointer] = item;
			m_Length++ ;
			return 1;

		}
	}
	else
		return 0;
}
// 입력 받은 데이터와 같은 정보를 가진 반복자가 반환된다. 
template<typename T>
int SortedArrayList<T>::Get(ItemType& target)
{
	int midPoint; // 바이너리 서치를 하기 위해 사용될 변수
	int first = 0; // 첫번쨰 위치
	int last = m_Length -1 ; // 마지막 위치
	bool moreToSearch= (first<=last); // 비교를 위해 만들어준 변수
	while (moreToSearch)
	{
		midPoint= (first+last)/2;
		switch (target.CompareByID(m_Array[midPoint])) // 아이디 비교
		{
		case LESS :
			last = midPoint-1 ; // 마지막 위치를 앞으로 땡겨온다
			moreToSearch= ( first <= last ) ;
			break ;
		case GREATER : 
			first = midPoint+ 1 ; // 첫번째 위치를 뒤로 밀어준다.
			moreToSearch= ( first <= last ) ;
			break ;
		case EQUAL :
			target = m_Array[midPoint]; // 타겟을 찾았고 그 타겟 위치를 반환
			m_CurPointer = midPoint;
			return 1;
		}
	}
	return 0;
}
 // 반복자의 위치에 있는 정보가 삭제된다. 
template<typename T>
int SortedArrayList<T>::Delete(ItemType data)
{
	if(Get(data)) // 그 data 정보가 존재 한다면 
	{
		for(int i=m_CurPointer;i<m_Length -1;i++)
		{
			m_Array[i] = m_Array[i+1];
		}
		m_Length--;
	}
	else
	{
		cout << "\t No record in the list.." << endl;
		return 0;
	}
	return 1;
}


// 상품을 판매해준다. 
 template<typename T>
void SortedArrayList<T>::Sell(ItemType data)
{
	int location = 0;
	int count;
	while(data.CompareByID(m_Array[location])!=EQUAL) // 찾고자 하는 상품에 위치를 설정
		location++;
	cout<<"\t판매할 개수를 입력하세요 : ";
	cin >> count;
	if(m_Array[location].GetCount()-count>=0) // 수량이 사고 싶은 갯수보다 많을떄
	{
		m_Array[location].SetTotalPrice(m_Array[location].GetTotalPrice()+(count*m_Array[location].GetPrice())); // 총 판매 금액을 설정
		m_Array[location].SetCount(m_Array[location].GetCount()-count); // 남은 갯수 설정
	}
	else
		cout<<"\t재고가 부족합니다."<<endl;
}