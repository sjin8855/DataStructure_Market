#pragma once
#include <iostream>
#include <string>
using namespace std;

class SellItem
{
public :
	/**
	*	기본 생성자.
	*/
	SellItem();

	/**
	*	소멸자.
	*/
	~SellItem(){}

	/**
	*	@brief	상품 이름을 리턴한다.
	*	@pre	상품 이름을 가지고있다.
	*	@post	상품 이름이 반환된다.
	*	@return	상품 이름
	*/
	string get_name(){return item_name;}

	/**
	*	@brief	상품 갯수를 리턴한다.
	*	@pre	상품 갯수를 가지고있다.
	*	@post	상품 갯수가 반환된다.
	*	@return	상품 갯수
	*/
	int get_count(){return item_count;}

	/**
	*	@brief	현재 시간을 리턴한다.
	*	@pre	현재 시간을 가지고있다.
	*	@post	현재 시간이 반환된다..
	*	@return	현재 시간
	*/
	string get_time(){return sell_time;}

	/**
	*	@brief	상품 가격을 리턴한다.
	*	@pre	상품 가격을 가지고있다.
	*	@post	상품 가격이 반환된다..
	*	@return	상품 가격
	*/
	int get_price(){return item_price;}

	/**
	*	@brief	상품 총액을 리턴한다.
	*	@pre	상품 총액을 가지고있다.
	*	@post	상품 총액이 반환된다..
	*	@return	상품 총액
	*/
	int get_total_price(){return total_price;}

	/**
	*	@brief	상품 코드를 리턴한다.
	*	@pre	상품 코드를 가지고있다.
	*	@post	상품 코드가 반환된다..
	*	@return	상품 코드
	*/
	int get_id(){return item_id;}

	/**
	*	@brief	상품 이름을 입력한다.
	*	@pre	없음.
	*	@post	상품 이름 설정
	*/
	void set_name(string name){item_name = name;}

	/**
	*	@brief	상품 이름을 입력한다.
	*	@pre	없음.
	*	@post	상품 이름 설정
	*/
	void set_count(int count){item_count = count;}

	/**
	*	@brief	상품 판매시간을 입력한다.
	*	@pre	없음.
	*	@post	상품 판매시간 설정
	*/
	void set_time(string time){sell_time = time;}

	/**
	*	@brief	상품 가격을 입력한다.
	*	@pre	없음.
	*	@post	상품 가격 설정
	*/
	void set_price(int price){item_price = price;}

	/**
	*	@brief	상품 총액을 입력한다.
	*	@pre	없음.
	*	@post	상품 총액 설정
	*/
	void set_total_price(int price){total_price = price;}

	/**
	*	@brief	상품 코드를 입력한다.
	*	@pre	없음.
	*	@post	상품 코드 설정
	*/
	void set_id(int id){item_id = id;}

	/**
	*	@brief	상품 정보를 모두 출력한다.
	*	@pre	없음.
	*	@post	상품 정보 출력
	*/
	void DisplayAll();

private :
	string item_name; // 판매된 상품 이름
	int item_count;// 판매된 상품 갯수
	string sell_time; // 판매된 시간
	int item_price;// 판매상품 가격
	int total_price;//판매상품 총액
	int item_id;	//판매상품 id
};