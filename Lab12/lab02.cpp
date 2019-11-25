//(�ǽ�2)�Ʒ��� bubble sort ������� ������ �����ϴ� ���α׷��Դϴ�.
//���α׷��� �м��� ����, bubble_sort�� ���ڷ� �ԷµǴ� Compare comp�� ���� *Functor�� ������ ���ÿ�.
//comp�� �Է�(compLess / compGreater)�� ���� ���������� / ������������ ���� �ٸ��� ���ĵ˴ϴ�.

//*Functor: �Լ� ������Ʈ�μ� �Ϲ����� �Լ��� �ƴ� ��ü�� �����Ǿ� �Լ� ������ �����Ѵ�.


#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {	//���� sorted�� �־��ش�?
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {   //++�� ���� �����ں��� ����
			if (comp(*cur, *prev)) {
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}//for�� �ѹ� �� ���� ó������ ������ ����
	}
}

//Fuctor�� compGreater�� �����ϼ���. (��Ʈ: 1. �� ���� �� ����� bool Ÿ���� �����Ѵ�. 2. operator() �� �����Ѵ�. 3. Fuctor�� Ŭ���� ���¿� ����ϴ�.)

//Fuctor�� compLess�� �����ϼ���. (��Ʈ: 1. �� ���� �� ����� bool Ÿ���� �����Ѵ�. 2. operator()�� �����Ѵ�. 3. Fuctor�� Ŭ���� ���¿� ����ϴ�.)

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };

	std::cout << "�������� ����" << std::endl;
	compLess compLess; //Functor ����
	bubble_sort(values.begin(), values.end(), compLess);
	//��� ����Ʈ
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;


	std::cout << "�������� ����" << std::endl;
	compGreater compGreater; //Functor ����
	bubble_sort(values.begin(), values.end(), compGreater);//begin�� 7�� ����Ű��, end�� 3�� �Ѿ �ٸ� �ּҸ� ����Ų��
	//��� ����Ʈ
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	getchar();
}

class compLess {
public:
	//���� if�� �ȿ� ���־�� ��
	bool operator()(int a, int b) {
		return a > b;
	}
};

class compGreater {//���� ������ ����
public :
	//�� ��Ʈ���̳ĸ� main������ ������ ������ int���̴�
	bool operator()(int a, int b) {
		return a < b;
	}
};
