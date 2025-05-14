#include <string>	//std::string 클래스 정의, 문자열인 텍스트를 다루기 위한 c++표준 클래스어

//다른 코드에 동일한 이름이 있어도 충돌을 방지하는 namespace
// utils 범주 안에 string 관련 기능을 묶는 논리적 공간
namespace utils::string { 

//class는 C++에서 클래스를 만들 때 쓰는 키워드
//나는 string_helper라는 이름의 새로운 사용자 정의 자료형인 클래스를 정의하겠다는 뜻
class string_helper {

//public은 외부에서 아래에 적는 함수들을 호출할 수 있도록 공개하는 것
//그래서 아무것도 쓰지 않거나, private이면 외부 사용 x
public:

	/*
	 static은 객체를 만들지 않고도 클래스를 이름으로 직접 호출할 수 있는 정적 함수
	std::string은 아까 불러온 표준 라이브러리 srd안에 있는 string을 쓰겠다는 의미
	toUpperCase는 내가 만든 함수의 이름이고 역할은 입력된 문자열을 대문자로 반환
	str은 함수에 전달된 문자열을 가리키는 포인터 변수 이름이고
	*str은 주소가 가르키는 실제 문자열의 값
	const는 뒤의 문자열을 함수 내부에서 변경하지 않는다는 것.
	따라서, 전달된 문자열을 그대로 가져와서 대문자로 반환시키는 것
	*/
	static std::string toUpperCase(const std::string* str);

	//전달된 문자열을 소문자로 반환
	static std::string toLowerCase(const std::string* str);

	/*
	bool은 참 또는 거짓으로 함수가 반환할 수 있게
	contains는 내가 만든 함수 이름으로, 포함 여부를 검사하는 것.
	str로 하면 좋은데 이해하기 쉽고 text로 변수 이름을 잡음.
	pattern또한 전달받는 문자열
	따라서, text와 pattern을 그대로 가져와서 text내에 pattern이 있는지 확인하고
	그 결과를 bool을 통해 참거짓으로 결과를 반환
	*/
	static bool contains(const std::string* text, const std::string* pattern);

};

}
