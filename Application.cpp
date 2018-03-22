#include "Application.h"


// ���α׷� �õ�
void Application::Run()
{
	while(1)
	{
		sell_check();
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// ��ǰ ���
			AddItem();
			break;	
		case 2:		// ��ǰ �԰�
			Warehouse();
			break;
		case 3:		// ��ǰ �ֹ�
			OrderItem();
			break;
		case 4:		// ��ǰ �Ǹ�
			Sellitem();
			break;
		case 5:     // ��ǰ ����.
			Deleteitem();
			break;
		case 6:     // ��� ��ǰ ���
			DisplayAllItem();
			system("pause");
			system("cls");
			break;
		case 7:  // �Ǹ� ���� ����Ʈ�� �ִ� ��� ���� ���
			print_Management();
			break;

		case 0:	// ����
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}


// ȭ�鿡 ��ɾ �����ְ� ����ڷκ��� Ű����� ����� �Է¹޴´�. 
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : ��ǰ ���" << endl;
	cout << "\t   2 : ��ǰ �԰�" << endl;
	cout << "\t   3 : ��ǰ �ֹ�" << endl;
	cout << "\t   4 : ��ǰ �Ǹ�" << endl; 
	cout << "\t   5 : ��ǰ ����" << endl; 
	cout << "\t   6 : ��� ��ǰ ���" << endl;
	cout << "\t����������������������������������������"<<endl;
	cout << "\t�� 7 : �Ǹŵ� ��ǰ �����޴��� �̵�    ��"<<endl;
	cout << "\t����������������������������������������"<<endl;
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// ����Ʈ�� ���ο� ������ �߰��Ѵ�.
int Application::AddItem()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if(m_List.IsFull())
	{
		cout << "\tList is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);
	system("cls");
	// ���� list ���
	DisplayAllItem();
	system("pause");
	system("cls");
	return 1;
}


// ȭ�鿡 ��� ����Ʈ�� �����͵��� ���
void Application::DisplayAllItem()
{
	ItemType data;
	
	cout << "\n\tCurrent list" << endl;

	m_List.ResetList();	// ����Ʈ �ʱ�ȭ
	// list�� ��� �����͸� ȭ�鿡 ���
	for(int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
	}
}




// ����Ʈ�� �ִ� �������� ã���� �ϴ� ���̵� �Է� �� �� ���̵� �˻��Ͽ� ã�´�.
void Application::OrderItem()
{
	system("cls");
	DisplayAllItem();

	int _id; // �ӽ� ���̵� ���� ����
	int count;
	int save_count; // ���� �ֹ��� ����
	cout << "\t�˻� �� ID�� �Է��ϼ���. " ;
	cin >> _id;
	ItemType data; // ã���� �ϴ� ������ Ÿ�� ����
	data.SetId(_id);
	
	m_List.ResetList(); // ����Ʈ�� �ݺ��� �ʱ�ȭ
	if(m_List.Get(data) == 0) // ����Ʈ�� ���̵� ���ٸ�
	{
		cout << "\t�������� �ʽ��ϴ�. " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\t�ֹ����� �Է��ϼ���. " ;
		cin >> count;
		save_count = data.GetOrderCount();
		data.SetOrderCount(save_count+count);
		m_List.Set(data);
		system("cls");
		
		DisplayAllItem();// �ִٸ� ���
		
		system("pause");
		system("cls");
	}	
}
// ����Ʈ�� �ִ� ������ �� �����ϰ��� �ϴ� ���̵� �Է� �� �� ���̵� �˻��Ͽ� �� ���̵� �����ϴ� ��ġ�� �ִ� ������ �����Ѵ�.
int Application::Deleteitem()
{
	if(m_List.IsFull())
	{
		cout << "\tList is full" << endl;
		system("pause");
		system("cls");
		return 0;
	}

	ItemType item; // ������ �ӽ� ����
	int _id; // �ӽ� ���̵� ���� ����
	
	system("cls");
	
	// ���� list ���
	DisplayAllItem();
	cout << "\t�����Ϸ��� ���̵� �Է��ϼ��� : " ;
	cin >> _id;
	item.SetId(_id);
	m_List.ResetList(); // �ݺ��� ��ġ �ʱ�ȭ
	m_List.Delete(item); // ������ ����
	
	system("cls");

	// ���� �� list���
	DisplayAllItem();
	system("pause");
	system("cls");

	return 1;
}
// ����Ʈ�� �ִ� ������ �� ���� ��Ű���� �ϴ� ���̵� �Է��� �� �� ���̵� ��ġ�� �ִ� �������� �Է� ���� ������ ���Ž�Ų��.
int Application::Warehouse()
{
	system("cls");
	// ���� list ���
	DisplayAllItem();
	int _id; // �ӽ� ���̵� ���� ����
	ItemType item; // ������ ����.
	cout << "\t�԰��� ��ǰ ID�� �Է��ϼ���." ;
	cin >> _id;
	item.SetId(_id);
	m_List.ResetList(); // �ݺ��� �ʱ�ȭ
	if(m_List.Get(item) == 0){ // ����Ʈ�� ���̵� ���ٸ�
		cout << "\t������ �������� �ʽ��ϴ�." << endl;
		system("pause");
		system("cls");
		return 0;
	}
	else{

	//item.SetRecordFromKB(); // ���ο� ������ �Է�
	m_List.Replace(item); // ������ ����

	system("cls");
	//���� �� list ���
	DisplayAllItem();

	system("pause");
	system("cls");
	return 1;
	}
}
// ����Ʈ�� ����ش�.
void Application::empty_list()
{
	// ����Ʈ ���
	m_List.MakeEmpty();
}



void Application::Sellitem()
{
	int count;

	system("cls");
	DisplayAllItem();
	ItemType data;
	// ã���� �ϴ� �̸��� ���� �����͸� �Ѱ��ֱ� ���� �ӽ� ����
	int _id;
	cout << "\t�Ǹ��� ��ǰ ID�� �Է��ϼ��� :";
	cin >> _id;
	data.SetId(_id); // data�� �̸� �Է�
	if(m_List.Get(data) == 0) // ����Ʈ�� ���̵� ���ٸ�
	{
		cout << "\t������ �����ϴ�. " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		m_List.ResetList(); // ���� ������ �ʱ�ȭ
		count = m_List.Sell(data);
		
		add_sell(data,count);
		
		DisplayAllItem();

		system("pause");
		system("cls");
	}
}

//���� �ð� ���ϴ� �Լ�
string Application::CurrentTime()
{
	time_t timer;
	struct tm t;

	timer = time(NULL);
	localtime_s(&t,&timer); 

	string currentTime;
	int buf;
	char target[10];

	//��
	//buf = t.tm_year + 1900;
	//itoa(buf,target,10);   // int���� char������ ��ȯ
	//currentTime.append(target);	// currentTime���� �ڿ� append���ش�.


	// ��
	//buf = t.tm_mon + 1;
	//if(buf < 10) //  �ڸ����� ���ڸ� ������ ��� �տ� 0�� �ٿ��ش�
	//{
	//	currentTime.push_back('0');
	//	itoa(buf,target,10);
	//	currentTime.append(target);
	//}else{
	//	itoa(buf,target,10);
	//	currentTime.append(target);
	//}

	//��
	/*buf = t.tm_mday;
	if(buf < 10)
	{
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}else{
		itoa(buf,target,10);
		currentTime.append(target);
	}*/

	//��
	buf = t.tm_hour;
	if(buf < 10)
	{
		//�ð��� 10���� ������(���ڸ���) �ϰ�� 0���߰����ش�.
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	//��
	buf = t.tm_min;
	if(buf < 10)
	{
		//�ð��� 10���� ������(���ڸ���) �ϰ�� 0���߰����ش�.
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}else{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	//��
	buf = t.tm_sec;
	if(buf < 10)
	{
		//�ð��� 10���� ������(���ڸ���) �ϰ�� 0���߰����ش�.
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}else{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	return currentTime;
}

void Application::add_sell(ItemType data,int count)
{
	//����ð��� �ǸŻ�ǰ �ð��� ���Ѵ�.
	sell_check();

	bool check;
	SellItem item; // item �� ����
	item.set_name(data.GetName());
	item.set_count(count);
	item.set_time(CurrentTime());
	item.set_price(data.GetPrice());
	item.set_total_price(data.GetTotalPrice()+item.get_price()*item.get_count());
	item.set_id(data.GetId());
	//Add ���������� 1 �ƴϸ� 0
	check = se_List.Add(item);
	//Add ����������
	if(check)
	{
		cout << endl;
		system("cls");
		item.DisplayAll();
	}
	return ;

}


void Application::Display_Sell()
{
	//����ð��� �ǸŽð��� ���� �� ����Ʈ���� ����
	sell_check();
	DoublyIterator<SellItem> itor(se_List);

	//��� �Ǹ� ��ǰ ���
	cout << "\n\tCurrent list" << endl;

	for(int i = 0;i < se_List.GetLength(); i++)
	{
		cout << "\n\t< " << i+1 << " >" << endl;
		itor.Next();
		itor.GetCurrentNode()->data.DisplayAll();
		cout << endl;
	}

	//cout<<"\t������ǰ�� �߸� �Ǹ��ϼ̽��ϱ�?"<<endl;
	//cout<<"\t1. Yes"<<endl;
	//cout<<"\t2. No"<<endl<<"\t";
	//cin >> val;
	//switch(val)
	//{
	//case 1:
	//	cout<<"\t� �߸� �Ǹ��ϼ̽��ϱ�?  ";
	//	cin >>count;
	//	if(count<=itor.GetCurrentNode()->data.get_count())
	//	{
	//		itor.GetCurrentNode()->data.set_count(itor.GetCurrentNode()->data.get_count()-count);
	//		itor.GetCurrentNode()->data.set_total_price(itor.GetCurrentNode()->data.get_total_price()-itor.GetCurrentNode()->data.get_price()*count);
	//		id = itor.GetCurrentNode()->data.get_id();
	//		item.SetId(id);
	//		m_List.Get(item);
	//		m_List.ResetList(); // ���� ������ �ʱ�ȭ
	//		m_List.Cancel_Sell(item, count);
	//		cout<<"\t���� ��ҵǾ����ϴ�."<<endl;
	//	}
	//	else
	//		cout<<"\t���ŷ����� ��ҷ��� ���� �� �����ϴ�."<<endl;

	//	break;
	//	
	//case 2:
	//	break;
	//	
	//default:
	//	cout<<"�߸� �Է��ϼ̽��ϴ�."<<endl;
	//	return ;
	//}
}

//����ð��� ��ǰ�Ǹ� �ð� ��
void Application::sell_check()
{
	DoublyIterator<SellItem> itor(se_List);
	itor.ResetList();
	
	string cur_time = CurrentTime();
	int current_time = atoi(cur_time.c_str());
	int item_time; // ����ð��� ����Ʈ���ð�

	for(int i=0;i<se_List.GetLength();i++)
	{
		itor.Next();
		item_time = atoi(itor.GetCurrentNode()->data.get_time().c_str());
		if(current_time - item_time > 60) // 1���� ������ �Ǹ� �������� ����
		{
			se_List.Delete(itor);
			cout<<"\t"<<"1���� ������ ���� �Ǹų�����ǰ�� < "<<itor.GetCurrentNode()->data.get_name()<<" >��(��) �����Ǿ����ϴ�."<<endl;
		}
	}

}

//�ǸŻ�ǰ �����޴� 
void Application::print_Management()
{
	system("cls");
	while(true)
	{
		sell_check();
		int command;
		cout << endl << endl;
		cout << "\t---ID -- Command ----- " << endl;
		cout << "\t   1 : �Ǹ� ��� ���" << endl;
		cout << "\t   2 : ���� ��ǰ �������"<<endl;
		cout << "\t   3 : ��ǰ ��ǰ" << endl;
		cout << "\t   0 : Quit" << endl; 

		cout << endl << "\t Choose a Command--> ";
		cin >> command;
		system("cls");
		switch(command)
		{
		case 0:
			return ;

		case 1:
			Display_Sell();	// �Ǹű�� ���
			system("pause");
			system("cls");
			break;
		
		case 2:
			cancel_product();	// ���� ��ǰ �������
			system("pause");
			system("cls");
			break;

		case 3:
			return_product();	// ��ǰ ��ȯ
			break;

		default:
			cout<<"\t�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//������ǰ ���
void Application::cancel_product()
{
	sell_check();
	DoublyIterator<SellItem> itor(se_List);
	ItemType item;
	int id;
	int val;
	int count;

	//������ǰ ���
	cout << "\t���� ��ǰ" << endl;

	for(int i = 0;i < se_List.GetLength(); i++)
		itor.Next();
	itor.GetCurrentNode()->data.DisplayAll();
	cout << endl;

	cout<<"\t������ǰ�� �߸� �Ǹ��ϼ̽��ϱ�?"<<endl;
	cout<<"\t1. Yes"<<endl;
	cout<<"\t2. No"<<endl<<"\t";
	cin >> val;
	count = itor.GetCurrentNode()->data.get_count();
	switch(val)
	{
	case 1:
		/*cout<<"\t� �߸� �Ǹ��ϼ̽��ϱ�?  ";
		cin >>count;
		if(count<=itor.GetCurrentNode()->data.get_count())
		{*/
			/*itor.GetCurrentNode()->data.set_count(itor.GetCurrentNode()->data.get_count()-count);
			itor.GetCurrentNode()->data.set_total_price(itor.GetCurrentNode()->data.get_total_price()-itor.GetCurrentNode()->data.get_price()*count);*/
			id = itor.GetCurrentNode()->data.get_id();
			item.SetId(id);
			m_List.Get(item);
			m_List.ResetList(); // ���� ������ �ʱ�ȭ
			m_List.Cancel_Sell(item, count);
			se_List.Delete(itor);
			cout<<"\t���� ��ҵǾ����ϴ�."<<endl;
		/*}
		else
			cout<<"\t���ŷ����� ��ҷ��� ���� �� �����ϴ�."<<endl;*/
		break;
		
	case 2:
		break;
		
	default:
		cout<<"�߸� �Է��ϼ̽��ϴ�."<<endl;
		return ;
	}
}

//��ǰ ��ǰ
void Application::return_product()
{
	//����ð��� �ǸŽð� ���� 1���� �������� �����Ѵ�.
	sell_check();
	
	DoublyIterator<SellItem> itor(se_List);
	DoublyIterator<SellItem> check_itor(se_List);
	ItemType item;
	int id;
	int count;
	int length;

	// �ǸŻ�ǰ ���� ���
	cout << "\n\tCurrent list" << endl;

	for(int i = 0;i < se_List.GetLength(); i++)
	{
		cout << "\n\t< " << i+1 << " >" << endl;
		itor.Next();
		itor.GetCurrentNode()->data.DisplayAll();
		cout << endl;
	}

	cout<<"\t��ǰ �� ��Ϲ�ȣ�� �Է����ּ��� : ";
	cin >> length;
	
	//����Ʈ ���̸�ŭ�� �Է��� �� �ִ�.(��Ϲ�ȣ)
	if(length-1<se_List.GetLength() && length>0)
	{
		for(int i = 0;i < length; i++)
			check_itor.Next();

		cout<<"\t��ǰ�� ������ �Է����ּ��� ";
		cin >> count;
		if(count<=itor.GetCurrentNode()->data.get_count())
		{
			//���� ���̱�
			check_itor.GetCurrentNode()->data.set_count(check_itor.GetCurrentNode()->data.get_count()-count);
			//���� ���̱�
			check_itor.GetCurrentNode()->data.set_total_price(check_itor.GetCurrentNode()->data.get_total_price()-check_itor.GetCurrentNode()->data.get_price()*count);
			//��ǰ��� ������
			id = check_itor.GetCurrentNode()->data.get_id();
			item.SetId(id);
			m_List.Get(item);
			m_List.ResetList(); // ���� ������ �ʱ�ȭ
			m_List.Cancel_Sell(item, count);
			
			if(check_itor.GetCurrentNode()->data.get_count()==0)
				se_List.Delete(check_itor);
			
			cout<<"\t��ǰ�Ǿ����ϴ�."<<endl;
		}
		else
			cout<<"\t���ŷ����� ��ǰ���� ���� �� �����ϴ�."<<endl;
	}
	else
	{
		cout<<"�߸��� ����� �Է��ϼ̽��ϴ�"<<endl;
		system("pause");
		system("cls");
	}

}


// ���� �б�
void Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	
	ifstream fin;
	fin.open("SaveFile.txt");
	
	int m_Id;
	string m_sName;
	string m_sManufacturer;
	int count;
	int price;
	// ������ ��� ������ �о� list�� �߰�
	while(!fin.eof())
	{
		fin >> m_Id;
		fin >> m_sName;
		fin >> m_sManufacturer;
		fin >> count;
		fin >> price;
		data.SetCount(count);
		data.SetId(m_Id);
		data.SetManufacturer(m_sManufacturer);
		data.SetName(m_sName);
		data.SetPrice(price);
		m_List.Add(data);
	}

	fin.close();	// file �ݱ�

}


// ���� ����
void Application::WriteDataToFile()
{
//	ItemType data;	
//	ofstream ofs;
//	ofs.open("SaveFile.txt");
//
//	
//
//	// list �����͸� �ʱ�ȭ
//	m_List.ResetList();
//	
//	while(m_List.GetNextItem(data) != 0)
//	{
//		data.WriteDataToFile(m_OutFile);
//	}
//
//	m_OutFile.close();	// file �ݱ�
}