#include "Application.h"


// 프로그램 시동
void Application::Run()
{
	while(1)
	{
		sell_check();
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// 상품 등록
			AddItem();
			break;	
		case 2:		// 상품 입고
			Warehouse();
			break;
		case 3:		// 상품 주문
			OrderItem();
			break;
		case 4:		// 상품 판매
			Sellitem();
			break;
		case 5:     // 상품 삭제.
			Deleteitem();
			break;
		case 6:     // 등록 상품 출력
			DisplayAllItem();
			system("pause");
			system("cls");
			break;
		case 7:  // 판매 내역 리스트에 있는 모든 정보 출력
			print_Management();
			break;

		case 0:	// 종료
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}


// 화면에 명령어를 보여주고 사용자로부터 키보드로 명령을 입력받는다. 
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : 상품 등록" << endl;
	cout << "\t   2 : 상품 입고" << endl;
	cout << "\t   3 : 상품 주문" << endl;
	cout << "\t   4 : 상품 판매" << endl; 
	cout << "\t   5 : 상품 삭제" << endl; 
	cout << "\t   6 : 등록 상품 출력" << endl;
	cout << "\t┌──────────────────┐"<<endl;
	cout << "\t│ 7 : 판매된 상품 관리메뉴로 이동    │"<<endl;
	cout << "\t└──────────────────┘"<<endl;
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// 리스트에 새로운 정보를 추가한다.
int Application::AddItem()
{
	// 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if(m_List.IsFull())
	{
		cout << "\tList is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);
	system("cls");
	// 현재 list 출력
	DisplayAllItem();
	system("pause");
	system("cls");
	return 1;
}


// 화면에 모든 리스트에 데이터들을 출력
void Application::DisplayAllItem()
{
	ItemType data;
	
	cout << "\n\tCurrent list" << endl;

	m_List.ResetList();	// 리스트 초기화
	// list의 모든 데이터를 화면에 출력
	for(int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		data.DisplayRecordOnScreen();
	}
}




// 리스트에 있는 정보들중 찾고자 하는 아이디를 입력 후 그 아이디를 검색하여 찾는다.
void Application::OrderItem()
{
	system("cls");
	DisplayAllItem();

	int _id; // 임시 아이디 저장 변수
	int count;
	int save_count; // 원래 주문량 저장
	cout << "\t검색 할 ID를 입력하세요. " ;
	cin >> _id;
	ItemType data; // 찾고자 하는 아이템 타입 변수
	data.SetId(_id);
	
	m_List.ResetList(); // 리스트에 반복자 초기화
	if(m_List.Get(data) == 0) // 리스트에 아이디가 없다면
	{
		cout << "\t존재하지 않습니다. " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\t주문량을 입력하세요. " ;
		cin >> count;
		save_count = data.GetOrderCount();
		data.SetOrderCount(save_count+count);
		m_List.Set(data);
		system("cls");
		
		DisplayAllItem();// 있다면 출력
		
		system("pause");
		system("cls");
	}	
}
// 리스트에 있는 정보들 중 삭제하고자 하는 아이디를 입력 후 그 아이디를 검색하여 그 아이디가 존재하는 위치에 있는 정보를 삭제한다.
int Application::Deleteitem()
{
	if(m_List.IsFull())
	{
		cout << "\tList is full" << endl;
		system("pause");
		system("cls");
		return 0;
	}

	ItemType item; // 아이템 임시 변수
	int _id; // 임시 아이디 저장 변수
	
	system("cls");
	
	// 현재 list 출력
	DisplayAllItem();
	cout << "\t삭제하려는 아이디를 입력하세요 : " ;
	cin >> _id;
	item.SetId(_id);
	m_List.ResetList(); // 반복자 위치 초기화
	m_List.Delete(item); // 아이템 삭제
	
	system("cls");

	// 삭제 후 list출력
	DisplayAllItem();
	system("pause");
	system("cls");

	return 1;
}
// 리스트에 있는 정보들 중 갱신 시키고자 하는 아이디를 입력한 후 그 아이디에 위치에 있는 정보들을 입력 받은 정보로 갱신시킨다.
int Application::Warehouse()
{
	system("cls");
	// 현재 list 출력
	DisplayAllItem();
	int _id; // 임시 아이디 저장 변수
	ItemType item; // 아이템 변수.
	cout << "\t입고할 상품 ID를 입력하세요." ;
	cin >> _id;
	item.SetId(_id);
	m_List.ResetList(); // 반복자 초기화
	if(m_List.Get(item) == 0){ // 리스트에 아이디가 없다면
		cout << "\t정보가 존재하지 않습니다." << endl;
		system("pause");
		system("cls");
		return 0;
	}
	else{

	//item.SetRecordFromKB(); // 새로운 아이템 입력
	m_List.Replace(item); // 아이템 갱신

	system("cls");
	//갱신 후 list 출력
	DisplayAllItem();

	system("pause");
	system("cls");
	return 1;
	}
}
// 리스트를 비워준다.
void Application::empty_list()
{
	// 리스트 비움
	m_List.MakeEmpty();
}



void Application::Sellitem()
{
	int count;

	system("cls");
	DisplayAllItem();
	ItemType data;
	// 찾고자 하는 이름을 가진 데이터를 넘겨주기 위한 임시 변수
	int _id;
	cout << "\t판매할 상품 ID를 입력하세요 :";
	cin >> _id;
	data.SetId(_id); // data에 이름 입력
	if(m_List.Get(data) == 0) // 리스트에 아이디가 없다면
	{
		cout << "\t정보가 없습니다. " << endl;
		system("pause");
		system("cls");
	}
	else
	{
		m_List.ResetList(); // 현재 포인터 초기화
		count = m_List.Sell(data);
		
		add_sell(data,count);
		
		DisplayAllItem();

		system("pause");
		system("cls");
	}
}

//현재 시간 구하는 함수
string Application::CurrentTime()
{
	time_t timer;
	struct tm t;

	timer = time(NULL);
	localtime_s(&t,&timer); 

	string currentTime;
	int buf;
	char target[10];

	//년
	//buf = t.tm_year + 1900;
	//itoa(buf,target,10);   // int형을 char형으로 변환
	//currentTime.append(target);	// currentTime변수 뒤에 append해준다.


	// 월
	//buf = t.tm_mon + 1;
	//if(buf < 10) //  자리수가 한자리 숫자인 경우 앞에 0을 붙여준다
	//{
	//	currentTime.push_back('0');
	//	itoa(buf,target,10);
	//	currentTime.append(target);
	//}else{
	//	itoa(buf,target,10);
	//	currentTime.append(target);
	//}

	//일
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

	//시
	buf = t.tm_hour;
	if(buf < 10)
	{
		//시간이 10보다 작을떄(한자리수) 일경우 0을추가해준다.
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}else
	{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	//분
	buf = t.tm_min;
	if(buf < 10)
	{
		//시간이 10보다 작을떄(한자리수) 일경우 0을추가해준다.
		currentTime.push_back('0');
		itoa(buf,target,10);
		currentTime.append(target);
	}else{
		itoa(buf,target,10);
		currentTime.append(target);
	}

	//초
	buf = t.tm_sec;
	if(buf < 10)
	{
		//시간이 10보다 작을떄(한자리수) 일경우 0을추가해준다.
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
	//현재시간과 판매상품 시간을 비교한다.
	sell_check();

	bool check;
	SellItem item; // item 값 설정
	item.set_name(data.GetName());
	item.set_count(count);
	item.set_time(CurrentTime());
	item.set_price(data.GetPrice());
	item.set_total_price(data.GetTotalPrice()+item.get_price()*item.get_count());
	item.set_id(data.GetId());
	//Add 성공했으면 1 아니면 0
	check = se_List.Add(item);
	//Add 성공했을시
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
	//현재시간과 판매시간을 비교한 후 리스트에서 제거
	sell_check();
	DoublyIterator<SellItem> itor(se_List);

	//모든 판매 상품 출력
	cout << "\n\tCurrent list" << endl;

	for(int i = 0;i < se_List.GetLength(); i++)
	{
		cout << "\n\t< " << i+1 << " >" << endl;
		itor.Next();
		itor.GetCurrentNode()->data.DisplayAll();
		cout << endl;
	}

	//cout<<"\t직전상품을 잘못 판매하셨습니까?"<<endl;
	//cout<<"\t1. Yes"<<endl;
	//cout<<"\t2. No"<<endl<<"\t";
	//cin >> val;
	//switch(val)
	//{
	//case 1:
	//	cout<<"\t몇개 잘못 판매하셨습니까?  ";
	//	cin >>count;
	//	if(count<=itor.GetCurrentNode()->data.get_count())
	//	{
	//		itor.GetCurrentNode()->data.set_count(itor.GetCurrentNode()->data.get_count()-count);
	//		itor.GetCurrentNode()->data.set_total_price(itor.GetCurrentNode()->data.get_total_price()-itor.GetCurrentNode()->data.get_price()*count);
	//		id = itor.GetCurrentNode()->data.get_id();
	//		item.SetId(id);
	//		m_List.Get(item);
	//		m_List.ResetList(); // 현재 포인터 초기화
	//		m_List.Cancel_Sell(item, count);
	//		cout<<"\t구매 취소되었습니다."<<endl;
	//	}
	//	else
	//		cout<<"\t구매량보다 취소량이 많을 수 없습니다."<<endl;

	//	break;
	//	
	//case 2:
	//	break;
	//	
	//default:
	//	cout<<"잘못 입력하셨습니다."<<endl;
	//	return ;
	//}
}

//현재시간과 상품판매 시간 비교
void Application::sell_check()
{
	DoublyIterator<SellItem> itor(se_List);
	itor.ResetList();
	
	string cur_time = CurrentTime();
	int current_time = atoi(cur_time.c_str());
	int item_time; // 현재시간과 리스트에시간

	for(int i=0;i<se_List.GetLength();i++)
	{
		itor.Next();
		item_time = atoi(itor.GetCurrentNode()->data.get_time().c_str());
		if(current_time - item_time > 60) // 1분이 지나면 판매 내역에서 삭제
		{
			se_List.Delete(itor);
			cout<<"\t"<<"1분이 지나서 이전 판매내역상품인 < "<<itor.GetCurrentNode()->data.get_name()<<" >이(가) 삭제되었습니다."<<endl;
		}
	}

}

//판매상품 관리메뉴 
void Application::print_Management()
{
	system("cls");
	while(true)
	{
		sell_check();
		int command;
		cout << endl << endl;
		cout << "\t---ID -- Command ----- " << endl;
		cout << "\t   1 : 판매 기록 출력" << endl;
		cout << "\t   2 : 직전 상품 구매취소"<<endl;
		cout << "\t   3 : 상품 반품" << endl;
		cout << "\t   0 : Quit" << endl; 

		cout << endl << "\t Choose a Command--> ";
		cin >> command;
		system("cls");
		switch(command)
		{
		case 0:
			return ;

		case 1:
			Display_Sell();	// 판매기록 출력
			system("pause");
			system("cls");
			break;
		
		case 2:
			cancel_product();	// 직전 상품 구매취소
			system("pause");
			system("cls");
			break;

		case 3:
			return_product();	// 상품 반환
			break;

		default:
			cout<<"\t잘못된 값을 입력하셨습니다. 다시 입력해주세요"<<endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//직전상품 취소
void Application::cancel_product()
{
	sell_check();
	DoublyIterator<SellItem> itor(se_List);
	ItemType item;
	int id;
	int val;
	int count;

	//직전상품 출력
	cout << "\t직전 상품" << endl;

	for(int i = 0;i < se_List.GetLength(); i++)
		itor.Next();
	itor.GetCurrentNode()->data.DisplayAll();
	cout << endl;

	cout<<"\t직전상품을 잘못 판매하셨습니까?"<<endl;
	cout<<"\t1. Yes"<<endl;
	cout<<"\t2. No"<<endl<<"\t";
	cin >> val;
	count = itor.GetCurrentNode()->data.get_count();
	switch(val)
	{
	case 1:
		/*cout<<"\t몇개 잘못 판매하셨습니까?  ";
		cin >>count;
		if(count<=itor.GetCurrentNode()->data.get_count())
		{*/
			/*itor.GetCurrentNode()->data.set_count(itor.GetCurrentNode()->data.get_count()-count);
			itor.GetCurrentNode()->data.set_total_price(itor.GetCurrentNode()->data.get_total_price()-itor.GetCurrentNode()->data.get_price()*count);*/
			id = itor.GetCurrentNode()->data.get_id();
			item.SetId(id);
			m_List.Get(item);
			m_List.ResetList(); // 현재 포인터 초기화
			m_List.Cancel_Sell(item, count);
			se_List.Delete(itor);
			cout<<"\t구매 취소되었습니다."<<endl;
		/*}
		else
			cout<<"\t구매량보다 취소량이 많을 수 없습니다."<<endl;*/
		break;
		
	case 2:
		break;
		
	default:
		cout<<"잘못 입력하셨습니다."<<endl;
		return ;
	}
}

//상품 반품
void Application::return_product()
{
	//현재시간과 판매시간 비교후 1분이 지난것은 제거한다.
	sell_check();
	
	DoublyIterator<SellItem> itor(se_List);
	DoublyIterator<SellItem> check_itor(se_List);
	ItemType item;
	int id;
	int count;
	int length;

	// 판매상품 내역 출력
	cout << "\n\tCurrent list" << endl;

	for(int i = 0;i < se_List.GetLength(); i++)
	{
		cout << "\n\t< " << i+1 << " >" << endl;
		itor.Next();
		itor.GetCurrentNode()->data.DisplayAll();
		cout << endl;
	}

	cout<<"\t반품 할 목록번호를 입력해주세요 : ";
	cin >> length;
	
	//리스트 길이만큼만 입력할 수 있다.(목록번호)
	if(length-1<se_List.GetLength() && length>0)
	{
		for(int i = 0;i < length; i++)
			check_itor.Next();

		cout<<"\t반품할 갯수를 입력해주세요 ";
		cin >> count;
		if(count<=itor.GetCurrentNode()->data.get_count())
		{
			//갯수 줄이기
			check_itor.GetCurrentNode()->data.set_count(check_itor.GetCurrentNode()->data.get_count()-count);
			//가격 줄이기
			check_itor.GetCurrentNode()->data.set_total_price(check_itor.GetCurrentNode()->data.get_total_price()-check_itor.GetCurrentNode()->data.get_price()*count);
			//상품목록 복구용
			id = check_itor.GetCurrentNode()->data.get_id();
			item.SetId(id);
			m_List.Get(item);
			m_List.ResetList(); // 현재 포인터 초기화
			m_List.Cancel_Sell(item, count);
			
			if(check_itor.GetCurrentNode()->data.get_count()==0)
				se_List.Delete(check_itor);
			
			cout<<"\t반품되었습니다."<<endl;
		}
		else
			cout<<"\t구매량보다 반품량이 많을 수 없습니다."<<endl;
	}
	else
	{
		cout<<"잘못된 목록을 입력하셨습니다"<<endl;
		system("pause");
		system("cls");
	}

}


// 파일 읽기
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
	// 파일의 모든 내용을 읽어 list에 추가
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

	fin.close();	// file 닫기

}


// 파일 쓰기
void Application::WriteDataToFile()
{
//	ItemType data;	
//	ofstream ofs;
//	ofs.open("SaveFile.txt");
//
//	
//
//	// list 포인터를 초기화
//	m_List.ResetList();
//	
//	while(m_List.GetNextItem(data) != 0)
//	{
//		data.WriteDataToFile(m_OutFile);
//	}
//
//	m_OutFile.close();	// file 닫기
}