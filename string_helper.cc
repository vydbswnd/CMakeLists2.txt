#include "string_helper.h"
//앞에서 만든 함수 선언을 끌고옴.
#include <algorithm>
//정렬, 변환, 검색 등의 알고리즘 함수를 사용하기 위해 헤더파일을 끌고옴.
#include <cctype>
// 문자 처리 함수를 사용하기 위해 헤더파일을 끌고옴.
#include <stdexcept> 
/// 예외클래스들을 사용하기 위해 헤더 파일을 끌고옴.

namespace utils::string {
//네임스페이스로 영역?공간?을 지정해주고

std::string string_helper::toUpperCase(const std::string* str) {
//헤더 파일에서 쓴 함수 선언부분
    if (str == nullptr) {
        throw std::invalid_argument("Null input passed to toUpperCase");
    }
    // 문자열에 아무것도 집어넣지 않은 null이라면 즉, nillptr이라면 예외를 발생시키는 것.
    
    std::string result = *str;
    // 문자열을 result에 저장하고

    for (char& c : result) {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    /*
    result의 문자열 안의 문자를 하나하나 반복하고
    c안에 std::toupper() 즉, 각 문자를 대문자로 변환하는 함수
    static_cast<unsigned char>(c) 이것은 유닛코드와 같이 음수가 있을 수 있으니까 안전하게
    정수형으로 바꿔주는 것.
    */
    return result;
}

std::string string_helper::toLowerCase(const std::string* str) {
    if (str == nullptr) {
        throw std::invalid_argument("Null input passed to toLowerCase");
    }
    std::string result = *str;
     for (char& c : result) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
	// 위의 대문자 바꾸는 것과 같게 tolower을 활용해 소문자로 변환
    return result;
}

bool string_helper::contains(const std::string* text, const std::string* pattern) {
    if (text == nullptr || pattern == nullptr) {
    // 똑같이 null들어오면 오류만들건데, ||은 논리 or연산자이다.
        throw std::invalid_argument("Null input passed to contains");
    }
    return text->find(*pattern) != std::string::npos;
    /*
    text안에서 pattern을 찾을 건데
    std::string::npos; 못 찾았다는 의미의 특수한 값으로
    != std::string::npos; 찾았다는 뜻이며 찾으면 참 아니면 거짓으로 결과 나옴.
    */
}

}
