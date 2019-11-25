//(�ǽ� 1) sum()�� ������ �Ķ���͵��� ���ڷ� �޾� ���� �����ϴ� �Լ��̴�.
//����� ȣ�� �� ������ ������ �߻��Ѵ�.������ �����غ��� �����(63.6)�� ��µǵ��� �ڵ带 �ϼ��ϼ���.
//(��Ʈ: ������ sum ȣ�� �ÿ��� �Ķ���Ͱ� �ϳ��� ���´�.Variadic template Ȱ�뿡 ���� ������)

#include <iostream>
#include <string>

//�Ķ���͸� �ϳ��� �޴� �Լ��� ����� ��
//������ ����Լ��ε�, ������ sumȣ��. ��, 11.1f�� �������� ���Ƽ� 
template<typename T>
auto sum(T x) {
	return x;
}

template<typename T, typename...Args>
auto sum(T x, Args... args) {//��� ����� ����� ����, 0�� �̻��� argument�� �־��ָ� �Ǵµ�
	return x + sum(args...);//���Ⱑ ����, ��������� �ϰ��ֱ� ������
}

int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;

	getchar();
}
