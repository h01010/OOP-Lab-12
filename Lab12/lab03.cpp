//(실습3)아래  C 스타일 예외처리 문을 try, catch, throw를 활용하여 바꾸어 보시오.
//(단, 예외는 out_of_range("Invalid Input!!")을 사용할것.main 함수의 catch 문에서 "Invalid Input"을 예외 인자로 받아 출력할것.)
#include <iostream>

bool funcA() {
	int c;
	std::cin >> c; //사용자로부터 입력을 받음
	if (c < 10) //Let's assume this is exception
		throw std::out_of_range("Invalid Input!!");
	//out_of_range라는 건 c++에서 자체로 정해놓은 예외처리 함수
	return true;
}
int main() {

	try
	{
		funcA();	//얘를 실행했을 때~
	}
	catch (std::out_of_range& e){
		std::cout << "Exception : "<<e.what()<< std::endl;
	}

	return 0;
}
