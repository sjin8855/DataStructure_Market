#pragma once
#include "SellItem.h"

// ����ũ�� ����Ʈ�� ��带 �����ϴ� ����ü
template<typename T>
struct DoublyNodeType
{
	T data; // ���� �����۰�
	DoublyNodeType* prev; // ���� ��带 ����Ű�� �����ͺ���
	DoublyNodeType* next; // ���� ��带 ����Ű�� �����ͺ���
};

// friend �Լ��� ������ֱ� ���� ����
template<typename T> class DLL;
// ����ũ�� ����Ʈ���� ����� ���ͷ����͸� �����ϴ� Ŭ����
template<typename T>
class DoublyIterator
{
	// ����ũ�� ����Ʈ�� ������ֱ� ���� �������Լ� ���
	friend class DLL<T>;

public :
	/*
	*     �⺻������(�ʱ�ȭ����Ʈ ���)
	*/
	DoublyIterator(const DLL<T>& list) : m_List(list),m_pCurPointer(list.m_pFirst)
	{}; 
	/**
	*	@brief  ����Ʈ�� ���� ���Ұ� NULL�� �ƴ��� �˻�
	*	@pre	none.
	*	@post	none.
	*   @return ����Ʈ�� ���� ���Ұ� NULL �̶�� false �� ���� �ƴϸ� true �� ����
	*/
	bool NotNull(); 
	/**
	*	@brief  ����Ʈ�� ���� ���Ұ� NULL �� �ƴ��� �˻�
	*	@pre	none.
	*	@post	none.
	*   @return ����Ʈ�� ���� ���Ұ� NULL �̶�� false �� ���� �ƴϸ� true �� ����
	*/
	bool NextNotNull();
	/**
	*	@brief  ����Ʈ�� ó�� ����� �������� ����
	*	@pre	none.
	*	@post	none.
	*   @return ����Ʈ�� ó�� ���
	*/
	T First();
	/**
	*	@brief  ���� ���� �̵��ϰ� �ش� ����� �������� ����
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ��ִ�. 
	*	@post	���� ���� �����Ͱ� �̵��ϰ� �ش� ����� �������� ���ϵǾ���.
	*   @return �ش� ����� �������� ����
	*/
	T Next(); 
	/**
	*	@brief  �� �� ���� �̵��ϰ� �ش� ����� �������� ����
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ��ִ�. 
	*	@post	���� ���� �����Ͱ� �̵��ϰ� �ش� ����� �������� ���ϵǾ���.
	*   @return �ش� ����� �������� ����
	*/
	T Prev();
	/**
	*	@brief  ���� ��带 ����
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ��ִ�. 
	*	@post	���� �����Ͱ� ����Ű�� ��尡 ���ϵ�
	*   @return ���� �����Ͱ� ����Ű�� ��Ʈ ����
	*/
	DoublyNodeType<T>* GetCurrentNode();
	/**
	*	@brief  ���� ��带 ����Ű�� �����͸� ó�� ��ġ�� �ʱ�ȭ��Ų��. 
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ��ִ�. 
	*	@post	�����Ͱ� ó�� ��ġ�� ����Ű�� �ȴ�. 
	*/
	void ResetList();

private :
	const DLL<T>& m_List; // ����� ����Ʈ�� ���� ����
	DoublyNodeType<T>* m_pCurPointer; // iterator ����
};
// ����ũ�帮��Ʈ Ŭ����
template<typename T>
class DLL
{
	// ���ͷ����͸� ����ϱ� ���� ������ �Լ� 
	friend class DoublyIterator<T>;
public :
	/*
	*     �⺻������
	*/
	DLL();
	/*
	*    �Ҹ���
	*/
	~DLL();
	/**
	*	@brief  ����Ʈ�� ������ �ִ��� Ȯ��
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ� �ִ�. 
	*	@post	����Ʈ�� ������ �ִ��� Ȯ�εǾ���. 
	*   @return ����Ʈ�� ������ �ִٸ� true�� ��ȯ�ǰ� �ƴϸ� false �� ��ȯ�ȴ�. 
	*/
	bool isFull();
	/**
	*	@brief	����Ʈ�� ����ش�.
	*	@pre	None
	*	@post	����Ʈ�� �������.
	*/
	void MakeEmpty();
	/**
	*	@brief	����Ʈ�� �� ���̸� ��´�.
	*	@pre	None.
	*	@post	�Լ��� = ����Ʈ�� �� ����
	*	@return	�� ����Ʈ�� �� ���� ��ȯ
	*/
	int GetLength() const;
	/**
	*	@brief	����Ʈ�� ������ �߰�
	*	@pre	����Ʈ�� ������ ���� �ʰ� ����Ʈ �ȿ� �Էµ� �������� ����. 
	*	@post	�� ����Ʈ�� �������� �߰��Ǿ���.
	*   @prama  �߰��� ������
	*	@return	�� �Լ��� ���� �����Ǿ��ٸ� 1�� ��ȯ �ƴϸ� 0 ��ȯ
	*/
	int Add(T item);
	/**
	*	@brief	����Ʈ�� ������ ����
	*	@pre	����Ʈ�� ������ ���� �ʰ� ����Ʈ �ȿ� �Էµ� �������� �ִ�. 
	*	@post	�� ����Ʈ�� �������� �����Ǿ���.
	*   @param  ������ �����ۿ� ���ͷ�����
	*/
	void Delete(DoublyIterator<T> file);

	/**
	*	@brief	�����̸Ӹ� Ű�� ���� ���� ����Ʈ�� �����Ѵٸ� �� Ű ���� ���� �������� ��ȯ
	*	@pre	�� Ű����� ������ �������� �ʱ�ȭ�Ǿ��ִ�. 
	*	@post	�� Ű ��ġ �׸��� Ű�� �� ���� ����� ���ڵ尡 �׸����� ���� ���ڰ��ִ� ���.
	*   @param  ��ȯ�� ������ (ȹ����)
	*	@return	�� �Լ��� ���� �����Ǿ��ٸ� 1�� ��ȯ �ƴϸ� 0 ��ȯ
	*/
	int Get(T item);
	/**
	*	@brief	����Ʈ�� ���� ��� ���� ��´�. 
	*	@pre	���� ������ ���� ���ǵǾ���. 
	*	@post	���� ���� ����Ű�� �����Ͱ��� ���� ���� ����Ű�� ������ ���� �� �����Ͱ��� ����Ű�� �����۰����� �ٲ����. ���� count ���� 1�� �����ϰԵȴ�.
	*   @param  ���� ��尡 ����Ű�� �����۰��� T& item �� �� ������ ������ �ɶ� �� ���� �ε����� ������ count ��
	*/
	void GetNextItem(T item,int& count);
	/**
	*	@brief  ����Ʈ�� ù��° ��尪�� ��ȯ
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ� �ִ�. 
	*	@post	����Ʈ�� ù���� ��尪�� ��ȯ�޾Ҵ�.  
	*   @return ����Ʈ�� ù��° ��尪 
	*/
	DoublyNodeType<T>* Get_first();

private :
	DoublyNodeType<T>* m_pFirst; // ����Ʈ�� ó�� ��带 ����Ű�� ������
	DoublyNodeType<T>* m_pLast; // ����Ʈ�� ������ ��带 ����Ű�� ������
	int m_nLength; // ����Ʈ�� ����� ���ڵ� ��
};

// �⺻������
template<typename T>
DLL<T>::DLL()
{
	m_pFirst = NULL; // �ʱ�ȭ 
	m_pLast = NULL;
	m_pFirst = new DoublyNodeType<T>; // �����Ҵ�
	m_pLast = new DoublyNodeType<T>;
	m_pFirst->next = m_pLast; // dummy node �� ������ִ� ���� 
	m_pLast->next = NULL;
	m_pFirst->prev = NULL;
	m_pLast->prev = m_pFirst;
	m_nLength = 0;
}
// �Ҹ���
template<typename T>
DLL<T>::~DLL()
{
	MakeEmpty(); // ����Ʈ�� ����ش�. 
}

// ���� ��尡 ����Ű�� �����۰��� ��´�. 
template<typename T>
void DLL<T>::GetNextItem(T item,int& count)
{
	DoublyIterator<T> itor(*this);
	itor.ResetList(); // ���� ��� �ʱ�ȭ
	if(count == 0){ // ù��° ��ġ��� 
		itor.Next();
		item = itor.GetCurrentNode()->data; // ù��° ��ġ�� �ִ� �����۰����� ��ȯ
		count++; // ī��Ʈ�� ����
		return ;
	}
	else
	{
		int i=0;
		while(i<count)
		{
			itor.Next(); // ī��Ʈ��ŭ �����带 �̵������ش�. 
			i++;
		}
		count = i+1;
		itor.Next();
		item = itor.GetCurrentNode()->data; // ���� ��尡 ����Ű�� ���������� ��ȯ
		return ;
	}
}
// ����Ʈ�� ����á���� Ȯ��
template<typename T>
bool DLL<T>::isFull()
{
	DoublyNodeType<T>* location;
	try
	{
		location = new DoublyNodeType<T>;  // �޸� �Ҵ� �õ�
		delete location;
		return false;   // ������ �� false ���
	}
	catch(bad_alloc exception)  // ������ �� true ���
	{
		return true;
	}
}
// ����Ʈ�� ���ο� ������ �߰�
template<typename T>
int DLL<T>::Add(T item)
{
	if(isFull()) // �������ִٸ�
	{
		cout << " ����Ʈ�� �������ֽ��ϴ�. " << endl;
	}
	else // �ƴ϶��
	{
		DoublyNodeType<T>* pItem  = new DoublyNodeType<T>; // �Է¹��� �������� ������ ���ο� ����ũ�尴ü
		DoublyIterator<T> itor(*this);
		pItem->data = item;

		itor.ResetList(); // ���� ��� �ʱ�ȭ

		if(m_nLength == 0) // ����Ʈ�� ����� ���� ���ٸ�
		{
			DoublyNodeType<T>* save; // ��忡 ���ο� ���� �����ϴ� ����
			save = itor.GetCurrentNode();
			pItem->prev = save;
			pItem->next = save->next;
			save->next->prev = pItem;
			save->next = pItem;
			m_nLength++;
			return 1;
		}

		while(itor.GetCurrentNode()->next != m_pLast) // ���õ��� �ʾ����Ƿ� �� ������ ��ġ�� ���ͷ����� �̵�
		{
			itor.Next();
		}

		DoublyNodeType<T>* save; // ������ �߰�
		save = itor.GetCurrentNode();
		pItem->prev = save;
		pItem->next = save->next;
		save->next->prev = pItem;
		save->next = pItem;


		m_nLength++;
		return 1;
	}
}
// ����Ʈ�� ������ ����
template<typename T>
void DLL<T>::Delete(DoublyIterator<T> file)
{
	file.GetCurrentNode()->prev->next = file.GetCurrentNode()->next;
	file.GetCurrentNode()->next->prev = file.GetCurrentNode()->prev;

	//�ش� node�� ����
	m_nLength--;


}
// ���̵� ������ ������ �ִ� �����۰��� ��ġ�� ã�Ƽ� �� ��������ġ�� ������ ��ȯ���ش�. 
template<typename T>
int DLL<T>::Get(T item)
{
	DoublyIterator<T> itor(*this);
	itor.ResetList();
	DoublyNodeType<T>* pItem  = new DoublyNodeType<T>;
	pItem->data = item;
	int i=0;
	while(i<m_nLength){
		itor.Next(); // ���� ����� ��ġ �̵�
		if(itor.GetCurrentNode()->data == pItem->data)
			break;
		i++;
	}

	if(i == m_nLength)
		return 0;

	item = itor.GetCurrentNode()->data;
	return 1;

}

// ����Ʈ�� ���� ��ȯ
template<typename T>
int DLL<T>::GetLength() const
{
	return m_nLength;
}
// ����Ʈ�� ����ش�. 
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
// ���� ��尪�� NULL ���� �ƴ��� ��
template<typename T>
bool DoublyIterator<T>::NotNull()
{
	if(m_pCurPointer == NULL) // NULL �̸� false ����
		return false;
	else
		return true;
}
// ���� ��尪��  NULL ���� �ƴ��� ��
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
// ����Ʈ�� ù��° ��尪�� �ִ� �����Ͱ� ����
template<typename T>
T DoublyIterator<T>::First()
{
	return m_List.m_pFirst->data;
}
// ���� ��带 ���� ���� �̵�
template<typename T>
T DoublyIterator<T>::Next()
{
	if(m_pCurPointer == NULL)
		m_pCurPointer = m_List.m_pFirst;
	else
		m_pCurPointer = m_pCurPointer->next;

	return m_pCurPointer->data;
}
// ���� ��带 ���� ���� �̵� 
template<typename T>
T DoublyIterator<T>::Prev()
{
	if(m_pCurpointer == NULL)
		m_pCurPointer = m_List.m_pFirst;
	else
		m_pCurPointer = m_pCurPointer->prev;

	return m_pCurPointer->data;
}
// ���� ��尪�� ����
template<typename T>
DoublyNodeType<T>* DoublyIterator<T>::GetCurrentNode()
{
	return m_pCurPointer;
}
// ���� ��尪�� ó�� ��ġ�� �̵�
template<typename T>
void DoublyIterator<T>::ResetList()
{
	m_pCurPointer = m_List.m_pFirst;
}

