/**
*	@mainpage	동적으로 관리 가능한 슈퍼마켓 관리 프로그램
*
*
*	@date	2014.10.18 
*	@author	김주영  
*/

#include "Application.h"


int main()
{
	Application app;	// 프로그램 어플리케이션 
	app.ReadDataFromFile();
	app.Run();			// 프로그램 구동 실행

	return 0;
}