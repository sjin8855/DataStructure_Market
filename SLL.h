#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include "ItemType.h"

/**
*	��ũ�� ����Ʈ�� ����ϱ� ���� ����ü
*/
template <typename T>
struct NodeType
{
	T data;	///< ������ ��尡 ������ �ִ� ������
	NodeType* next;	///< ���� ��尡 ����Ű�� ���� ���
};


/**
*	���õ��� ���� ����Ʈ Ŭ����
*/
template <typename T>
class LinkedList
{
public:
	/**
	*	����Ʈ ������
	*/
	LinkedList();     

	/**
	*	�ı���
	*/
	~LinkedList();   
	/**
	*	@brief  ����Ʈ�� ������ �ִ��� Ȯ��
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ� �ִ�. 
	*	@post	����Ʈ�� ������ �ִ��� Ȯ�εǾ���. 
	*   @return ����Ʈ�� ������ �ִٸ� true�� ��ȯ�ǰ� �ƴϸ� false �� ��ȯ�ȴ�. 
	*/
	bool IsFull();
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
	*	@return	�� �Լ��� ���� �����Ǿ��ٸ� 1�� ��ȯ �ƴϸ� 0 ��ȯ
	*/
	int Add(T item);

	/**
	*	@brief	�����̸Ӹ� Ű�� ���� ���� ����Ʈ�� �����Ѵٸ� �� Ű ���� ���� �������� ��ȯ
	*	@pre	�� Ű����� ������ �������� �ʱ�ȭ�Ǿ��ִ�. 
	*	@post	�� Ű ��ġ �׸��� Ű�� �� ���� ����� ���ڵ尡 �׸����� ���� ���ڰ��ִ� ���.
	*	@return	�� �Լ��� ���� �����Ǿ��ٸ� 1�� ��ȯ �ƴϸ� 0 ��ȯ
	*/
	int Get(T& item);
	/**
	*	@brief	����Ʈ�� ������ ����
	*	@pre	����Ʈ�� ������ ���� �ʰ� ����Ʈ �ȿ� �Էµ� �������� �ִ�. 
	*	@post	�� ����Ʈ�� �������� �����Ǿ���.
	*	@return	�� �Լ��� ���� �����Ǿ��ٸ� 1�� ��ȯ �ƴϸ� 0 ��ȯ
	*/
	int Delete(T item);
	/**
	*	@brief	����Ʈ�� ������ ��ü
	*	@pre	����Ʈ�� ������ ���� �ʰ� ����Ʈ �ȿ� �Էµ� �������� �ִ�. 
	*	@post	�� ����Ʈ�� �������� ��ü�Ǿ���.
	*	@return	�� �Լ��� ���� �����Ǿ��ٸ� 1�� ��ȯ �ƴϸ� 0 ��ȯ
	*/
	void Replace(T item);
	/**
	*	@brief	����Ʈ�� �ִ� ���� ������ ���� �ʱ�ȭ
	*	@pre	None.
	*	@post	���� ���� ����Ű�� ������ ���� �ʱ�ȭ�Ǿ���.
	*/
	void ResetList();

	/**
	*	@brief	����Ʈ�� ���� ��� ���� ��´�. 
	*	@pre	���� ������ ���� ���ǵǾ���. 
	*	@post	���� ���� ����Ű�� �����Ͱ��� ���� ���� ����Ű�� ������ ���� �� �����Ͱ��� ����Ű�� �����۰����� �ٲ����. 
	*/	
	void GetNextItem(T& item);
	
	/**
	*	@brief ��ǰ ���̵� �Է¹޾� �ִ� �� ���̵� �Ǹ��Ѵ�
	*	@pre ���̵� �ִ�.
	*	@post ���̵��� ������ �����ȴ�
	*/
	int Sell(T &data);	//��ǰ �Ǹ�


	int Cancel_Sell(T &data, int count);
	void Set(T data);
protected:
	NodeType<T>* m_pList;	///< ù��° ��带 ����Ű�� ������
	NodeType<T>* m_pCurPointer;	///< ���� ��带 ����Ű�� ������
	int m_nLength;	///< ����Ʈ�� �� ����
};


// Ŭ���� ������
template <typename T>
LinkedList<T>::LinkedList()
{
	m_nLength = 0;
	m_pList = NULL;
	m_pCurPointer = NULL;
}


// Ŭ���� �Ҹ���
template <typename T>
LinkedList<T>::~LinkedList()
{
	//����Ʈ���� ��� node ����
	MakeEmpty();
}

// ����Ʈ�� ����á���� Ȯ��
template<typename T>
bool LinkedList<T>::IsFull()
{
	NodeType<T>* location;
	try
	{
		location = new NodeType<T>;  // �޸� �Ҵ� �õ�
		delete location;
		return false;   // ������ �� false ���
	}
	catch(bad_alloc exception)  // ������ �� true ���
	{
		return true;
	}
}
// ����Ʈ�� ����ش�.
template <typename T>
void LinkedList<T>::MakeEmpty()
// Post: ��� �������� �Ҵ��� �����ǰ� �ʱ�ȭ
{
	// ����Ʈ���� ��� ��� ���� �ϰ� ����Ʈ�� length�� �ʱ�ȭ
	NodeType<T>* tempPtr;
	
    while (m_pList != NULL)
    {
        tempPtr = m_pList;
        m_pList = m_pList->next;
        delete tempPtr;
    }
    
	m_nLength = 0;
}


// ����Ʈ�� ���̸� ��ȯ
template <typename T>
int LinkedList<T>::GetLength() const
{
	return m_nLength;
}


// ����Ʈ�� ���ο� ������ �߰�
template<typename T>
int LinkedList<T>::Add(T item)
{
	// ���� �����Ͱ� �ʱ�ȭ
	ResetList();
	// �߰��� ���ο� T ����(���)
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	NodeType<T>* save;
	NodeType<T>* head = m_pList;
	T dummy; // GetNextItem �� ������ֱ� ���� �׳� ����

	int count = 0; // ���� ������ ���� ��ġ�� �˱� ���� ����

	node->data = item;
	// ���� ����Ʈ�� �ƹ� ���� ���� ������ �ʴٸ�
	if(m_nLength == 0){
		node->next = NULL;
		m_pList = node;
		m_nLength++;

		return 1;
	}
	// ����Ʈ�� �ٸ� ���� ����� �ִٸ�
	else
	{
		while(1)
		{	
			GetNextItem(dummy); // �����Ͱ� �̵�
			pre = m_pCurPointer; // ���� �� ����(���� �����Ͱ�)
		
			if(item != pre->data && item > pre->data) // �����ε� ��� �Է¹��� ���� �ߺ� �ȵǰ� �ϰ� ���õǰ� �ϱ� ���� ����
			{
				if(m_pCurPointer->next == NULL) // ����Ʈ�� ���̶��
				{
					node->next = NULL;
					m_pCurPointer->next = node;
					m_nLength++;
					return 1;
				}
				count++; // ������ ���� ī���� ����(���� ������ ���� �̵���Ű�� ����)
			}
			else if(item < pre->data || pre == NULL){ // ������ ��ġ�� ã������
				break;
			}
			if(item == pre->data){ // �ߺ��� ���� ������ִٸ�
				cout << "����Ʈ�� �ߺ��� ���尪�� �����մϴ�. �ٸ� ���� �Է��Ͻʽÿ�. "<< endl;
				return 0;
			}
			
		}
		
		
	}
	// ���� ������ �� �ʱ�ȭ
	ResetList();

	for(int i=0;i<count;i++)
	{
		GetNextItem(dummy);
		pre = m_pCurPointer;
	} // ���� ������ �� �̵�

	save = pre->next;
	pre->next = node;
	node->next = save;
	 // ����
	m_nLength++;
	 // ����Ʈ ũ�� ����
	return 1;

}
// ����Ʈ�� �ִ� �����۰��� ����
template<typename T>
int LinkedList<T>::Delete(T item)
{
	// ���� ������ �� �ʱ�ȭ 
	ResetList();
	 // Add�Լ��� ����
	NodeType<T>* node = new NodeType<T>;
	NodeType<T>* pre;
	NodeType<T>* head = m_pList;
	T dummy;
	// ����Ʈ�� �ִ� ������ ���� ������ üũ���ֱ� ���� ����
	bool check = false;

	node->data = item;

	for(int i=0;i<m_nLength;i++)
	{
		GetNextItem(dummy);
		pre = m_pCurPointer;
		if(item == pre->data)
			check = true; // ���� �����Ѵٸ�
	}

	if(!check)
	{
		cout << "�� ����Ʈ�� ���� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է� ��Ź�帳�ϴ�. " << endl;
		return 0;
	}
	ResetList();

	if(m_nLength == 0){ // ����ִٸ�
		cout << "����Ʈ�� ���� �����Ͱ� �������� �ʽ��ϴ�. " << endl;
		return 0;
	}
	else
	{
		while(1)
		{		
			GetNextItem(dummy);
			pre = m_pCurPointer;
			if(pre == m_pList && item == pre->data) // �� ó�� �κ��̶��
			{
				m_pList = pre->next; // ó�� ���� ��ȭ
				delete pre; // �� ����
				break;
			}

			if(item == pre->data)
			{
				head->next = pre->next; // ������ ��� �տ� �ִ� ��忡 next���� ��ȭ
				delete pre; // ����
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
		cout << " �԰� ��ų ��ǰ�� ������ �Է��Ͻÿ� : ";
		cin >> count;
		if(m_pCurPointer->data.GetOrderCount() >= count)
		{
			m_pCurPointer->data.SetCount(m_pCurPointer->data.GetCount() + count);
			m_pCurPointer->data.SetOrderCount(m_pCurPointer->data.GetOrderCount() - count);
			break;
		}
		else 
		{
			cout << "�ֹ����� �Է°����� �����ϴ�. �ٽ� �Է� ��Ź�帳�ϴ�. " << endl<<endl;
		}
	}

	
}

template<typename T>
int LinkedList<T>::Get(T& item)
{ // ���ƼƮ Get�Լ��� ����

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


// ���� ���� ����Ű�� �����Ͱ��� �ʱ�ȭ
template <typename T>
void LinkedList<T>::ResetList()
{	
	// current pointer �ʱ�ȭ
	m_pCurPointer = NULL;
}


// ����Ʈ�� �������� ��ȯ(��)
template <typename T>
void LinkedList<T>::GetNextItem(T& item)
{
	// current pointer �� NULL�̶�� ó�� node�� ����Ŵ.
	if (m_pCurPointer == NULL)
	{
		m_pCurPointer = m_pList;
	}
	else
		//current position �� ���� ���� �̵�
		m_pCurPointer = m_pCurPointer->next;

	//item �� current position �� info �� ����
	item = m_pCurPointer->data;
}

// ��ǰ�� �Ǹ����ش�. 
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
			cout<<"\t�Ǹ��� ������ �Է��ϼ��� : ";
			cin >> count;
			if(pre->data.GetCount() - count >= 0)
			{
				pre->data.SetTotalPrice(pre->data.GetTotalPrice()+(count*pre->data.GetPrice())); // �� �Ǹ� �ݾ��� ����
				pre->data.SetCount(pre->data.GetCount()-count); // ���� ���� ����
			}
			else
				cout << "��� �����մϴ�. " << endl;
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
			pre->data.SetTotalPrice(pre->data.GetTotalPrice()-(count*pre->data.GetPrice())); // �� �Ǹ� �ݾ��� ����
			pre->data.SetCount(pre->data.GetCount()+count); // ���� ���� ����
		}
	}

	return count;
}

#endif	// LINKED_LIST