//(�ǽ�3)�Ʒ�  C ��Ÿ�� ����ó�� ���� try, catch, throw�� Ȱ���Ͽ� �ٲپ� ���ÿ�.
//(��, ���ܴ� out_of_range("Invalid Input!!")�� ����Ұ�.main �Լ��� catch ������ "Invalid Input"�� ���� ���ڷ� �޾� ����Ұ�.)
#include <iostream>

bool funcA() {
	int c;
	std::cin >> c; //����ڷκ��� �Է��� ����
	if (c < 10) //Let's assume this is exception
		throw std::out_of_range("Invalid Input!!");
	//out_of_range��� �� c++���� ��ü�� ���س��� ����ó�� �Լ�
	return true;
}
int main() {

	try
	{
		funcA();	//�긦 �������� ��~
	}
	catch (std::out_of_range& e){
		std::cout << "Exception : "<<e.what()<< std::endl;
	}

	return 0;
}
