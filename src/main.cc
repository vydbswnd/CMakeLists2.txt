#include <iostream>

#include "utils/string/string_helper.h"
//iostream 과 내가 만든 헤더 파일을 끌어옴.

// 의미 있는 상수 정의 (매직 문자열 제거)
const std::string DEFAULT_INPUT = "My name IS Pyo YUNjuNg 07.29!";
const std::string SEARCH_PATTERN = "pyo";

//main.cc는 여기부터 프로그램 시작하는 걸 알리는 것이고, 이미 구현한 함수를 테스트 해볼 수 있음.
int main() {
    std::string input = DEFAULT_INPUT;
    std::string pattern = SEARCH_PATTERN;
    // 입력값을 복잡하게 설정하고 pyo를 찾게 함.

    std::cout << "초기 입력값: " << input << '\n';	//input 그대로 출력
	
    std::string upper = utils::string::string_helper::toUpperCase(&input);
    std::cout << "대문자 정렬:    " << upper << '\n';
	//iput을 대문자로 반환하는 함수에 넣고 출력
	
    std::string lower = utils::string::string_helper::toLowerCase(&input);
    std::cout << "소문자 정렬:    " << lower << '\n';
	//input을 소문자로 반환하는 함수에 넣고 출력
	
    bool containsTest = utils::string::string_helper::contains(&input, &pattern);
    std::cout <<" '" << pattern << "'가 포함되나요? " << (containsTest ? "네" : "아니요") <<'\n';
	//input을 특정 문자열을 감지하는 함수에 넣고 판단해서 네/아니요 출력
	//조건식 ? 참일 때 값 : 거짓일 때 값 이러한 문법을 통해 값을 출력하는 것.
    return 0;
}
