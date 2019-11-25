//(실습 1) sum()은 임의의 파라미터들을 인자로 받아 합을 수행하는 함수이다.
//재귀적 호출 시 컴파일 에러가 발생한다.원인을 생각해보고 결과값(63.6)이 출력되도록 코드를 완성하세요.
//(힌트: 마지막 sum 호출 시에는 파라미터가 하나만 남는다.Variadic template 활용에 대한 내용임)

#include <iostream>
#include <string>

//파라미터를 하나만 받는 함수를 만들면 됨
//원래는 재귀함수인데, 마지막 sum호출. 즉, 11.1f는 마지막에 남아서 
template<typename T>
auto sum(T x) {
	return x;
}

template<typename T, typename...Args>
auto sum(T x, Args... args) {//사실 여기는 상관이 없음, 0개 이상의 argument를 넣어주면 되는데
	return x + sum(args...);//여기가 문제, 재귀적으로 하고있기 때문에
}

int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;

	getchar();
}
