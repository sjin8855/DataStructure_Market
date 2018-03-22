#include "SellItem.h"

SellItem::SellItem()
{
	item_name = "";
	item_count = 0; 
	sell_time = "";
	item_price = 0;
	total_price = 0;
}

void SellItem::DisplayAll()
{
	cout << "\t상품 이름   : " <<  item_name << endl;
	cout << "\t상품 가격  : " << item_price << endl;
	cout << "\t상품 갯수 : " << item_count << endl;
	cout << "\t판매 금액 : " << total_price << endl;
	cout << "\t판매된 시간 : " << sell_time << endl;
}