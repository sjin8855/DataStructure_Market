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
	cout << "\t��ǰ �̸�   : " <<  item_name << endl;
	cout << "\t��ǰ ����  : " << item_price << endl;
	cout << "\t��ǰ ���� : " << item_count << endl;
	cout << "\t�Ǹ� �ݾ� : " << total_price << endl;
	cout << "\t�Ǹŵ� �ð� : " << sell_time << endl;
}