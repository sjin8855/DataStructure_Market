#pragma once
#include <iostream>
#include <string>
using namespace std;

class SellItem
{
public :
	/**
	*	�⺻ ������.
	*/
	SellItem();

	/**
	*	�Ҹ���.
	*/
	~SellItem(){}

	/**
	*	@brief	��ǰ �̸��� �����Ѵ�.
	*	@pre	��ǰ �̸��� �������ִ�.
	*	@post	��ǰ �̸��� ��ȯ�ȴ�.
	*	@return	��ǰ �̸�
	*/
	string get_name(){return item_name;}

	/**
	*	@brief	��ǰ ������ �����Ѵ�.
	*	@pre	��ǰ ������ �������ִ�.
	*	@post	��ǰ ������ ��ȯ�ȴ�.
	*	@return	��ǰ ����
	*/
	int get_count(){return item_count;}

	/**
	*	@brief	���� �ð��� �����Ѵ�.
	*	@pre	���� �ð��� �������ִ�.
	*	@post	���� �ð��� ��ȯ�ȴ�..
	*	@return	���� �ð�
	*/
	string get_time(){return sell_time;}

	/**
	*	@brief	��ǰ ������ �����Ѵ�.
	*	@pre	��ǰ ������ �������ִ�.
	*	@post	��ǰ ������ ��ȯ�ȴ�..
	*	@return	��ǰ ����
	*/
	int get_price(){return item_price;}

	/**
	*	@brief	��ǰ �Ѿ��� �����Ѵ�.
	*	@pre	��ǰ �Ѿ��� �������ִ�.
	*	@post	��ǰ �Ѿ��� ��ȯ�ȴ�..
	*	@return	��ǰ �Ѿ�
	*/
	int get_total_price(){return total_price;}

	/**
	*	@brief	��ǰ �ڵ带 �����Ѵ�.
	*	@pre	��ǰ �ڵ带 �������ִ�.
	*	@post	��ǰ �ڵ尡 ��ȯ�ȴ�..
	*	@return	��ǰ �ڵ�
	*/
	int get_id(){return item_id;}

	/**
	*	@brief	��ǰ �̸��� �Է��Ѵ�.
	*	@pre	����.
	*	@post	��ǰ �̸� ����
	*/
	void set_name(string name){item_name = name;}

	/**
	*	@brief	��ǰ �̸��� �Է��Ѵ�.
	*	@pre	����.
	*	@post	��ǰ �̸� ����
	*/
	void set_count(int count){item_count = count;}

	/**
	*	@brief	��ǰ �ǸŽð��� �Է��Ѵ�.
	*	@pre	����.
	*	@post	��ǰ �ǸŽð� ����
	*/
	void set_time(string time){sell_time = time;}

	/**
	*	@brief	��ǰ ������ �Է��Ѵ�.
	*	@pre	����.
	*	@post	��ǰ ���� ����
	*/
	void set_price(int price){item_price = price;}

	/**
	*	@brief	��ǰ �Ѿ��� �Է��Ѵ�.
	*	@pre	����.
	*	@post	��ǰ �Ѿ� ����
	*/
	void set_total_price(int price){total_price = price;}

	/**
	*	@brief	��ǰ �ڵ带 �Է��Ѵ�.
	*	@pre	����.
	*	@post	��ǰ �ڵ� ����
	*/
	void set_id(int id){item_id = id;}

	/**
	*	@brief	��ǰ ������ ��� ����Ѵ�.
	*	@pre	����.
	*	@post	��ǰ ���� ���
	*/
	void DisplayAll();

private :
	string item_name; // �Ǹŵ� ��ǰ �̸�
	int item_count;// �Ǹŵ� ��ǰ ����
	string sell_time; // �Ǹŵ� �ð�
	int item_price;// �ǸŻ�ǰ ����
	int total_price;//�ǸŻ�ǰ �Ѿ�
	int item_id;	//�ǸŻ�ǰ id
};