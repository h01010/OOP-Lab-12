//(실습2)아래는 bubble sort 방식으로 정수를 정렬하는 프로그램입니다.
//프로그램을 분석해 보고, bubble_sort의 인자로 입력되는 Compare comp를 위한 *Functor를 구현해 보시오.
//comp의 입력(compLess / compGreater)에 따라 오름차순과 / 내림차순으로 각각 다르게 정렬됩니다.

//*Functor: 함수 오브젝트로서 일반적인 함수가 아닌 객체로 생성되어 함수 역할을 수행한다.


#include <iostream>
#include <algorithm>
#include <forward_list>
#include <functional>

template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	for (auto sorted = first; first != last; last = sorted) {	//끝을 sorted로 넣어준다?
		sorted = first;
		for (auto cur = first, prev = first; ++cur != last; ++prev) {   //++로 다음 연산자부터 시작
			if (comp(*cur, *prev)) {
				std::iter_swap(cur, prev);
				sorted = cur;
			}
		}//for문 한번 다 돌면 처음부터 끝까지 돈다
	}
}

//Fuctor인 compGreater를 구현하세요. (힌트: 1. 두 정수 비교 결과를 bool 타입을 리턴한다. 2. operator() 를 구현한다. 3. Fuctor는 클래스 형태와 비슷하다.)

//Fuctor인 compLess를 구현하세요. (힌트: 1. 두 정수 비교 결과를 bool 타입을 리턴한다. 2. operator()를 구현한다. 3. Fuctor는 클래스 형태와 비슷하다.)

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 };

	std::cout << "오름차순 정렬" << std::endl;
	compLess compLess; //Functor 생성
	bubble_sort(values.begin(), values.end(), compLess);
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;


	std::cout << "내림차순 정렬" << std::endl;
	compGreater compGreater; //Functor 생성
	bubble_sort(values.begin(), values.end(), compGreater);//begin은 7을 가리키고, end는 3을 넘어선 다른 주소를 가리킨다
	//결과 프린트
	for (auto it = values.begin(); it != values.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << std::endl;

	getchar();
}

class compLess {
public:
	//위에 if문 안에 들어가있어야 함
	bool operator()(int a, int b) {
		return a > b;
	}
};

class compGreater {//위와 구조는 같다
public :
	//왜 인트형이냐면 main에서의 들어오는 값들이 int형이다
	bool operator()(int a, int b) {
		return a < b;
	}
};
