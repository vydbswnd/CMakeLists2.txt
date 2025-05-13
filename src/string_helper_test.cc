#include "string_helper.h"
#include <gtest/gtest.h>
//

//주어진 목표인 5가지의 테스트를 진행

// 1. 빈 문자열 테스트
TEST(string_helpe_test, 빈_문자열) {
    std::string empty = "";
    std::string pattern = "vydbswnd";
    EXPECT_EQ(utils::string::string_helper::toUpperCase(&empty), "");
    EXPECT_EQ(utils::string::string_helper::toLowerCase(&empty), "");
    EXPECT_FALSE(utils::string::string_helper::contains(&empty, &pattern));
}
//빈 것을 입력하고 vydbswnd 문자열 있는지 판단하는 것
//대문자든 소문자든 아무것도 출력 안 해야 하고, vydbswnd 문자열에 대해 없으니까 false 출력해야함.

// 2. 일반 문자열 테스트
TEST(string_helper_test, 일반_문자열) {
    std::string text = "My namE Is PyO Yunjung";
    std::string pattern = "Yunjung";
    EXPECT_EQ(utils::string::string_helper::toUpperCase(&text), "MY NAME IS PYO YUNJUNG");
    EXPECT_EQ(utils::string::string_helper::toLowerCase(&text), "my name is pyo yunjung");
    EXPECT_TRUE(utils::string::string_helper::contains(&text, &pattern));
}
//일반 문자열에 대해 Yunjung 문자열이 있는지 판단
//일반 문자열의 대문자, 소문자 반환이 되어야 함.
//일반 문자열에 Yunjung이 포함되니까 True를 출력해야 함.

// 3. 특수문자 포함 문자열 테스트
TEST(string_helper_test, 특수문자_문자열) {
    std::string text = "i LoVe C++!";
    std::string pattern = "C++!";
    EXPECT_EQ(utils::string::string_helper::toUpperCase(&text), "I LOVE C++!");
    EXPECT_EQ(utils::string::string_helper::toLowerCase(&text), "i love c++!");
    EXPECT_TRUE(utils::string::string_helper::contains(&text, &pattern));
}
//특수문자를 포함하더라도 대문자와 소문자로 잘 반환해야하고
//특수문자의 문자열을 잘 찾는 지 확인하고 true로 반환해야함.

// 4. 긴 문자열 테스트
TEST(string_helper_test, 긴_문자열) {
    std::string longStr(1000, 't');
    std::string expected(1000, 'T');
    std::string pattern = "ttt";
    EXPECT_EQ(utils::string::string_helper::toUpperCase(&longStr), expected);
    EXPECT_TRUE(utils::string::string_helper::contains(&longStr, &pattern));
}
/*
std::string longStr(1000, 't'); 이 함수는 t를 1000번 반복하는 긴 문자열이고
std::string expected(1000, 'T'); 그 결과가 T 1000번임을 예상값으로 설정.
ttt가 패턴으로 있는 확인해야 하고 T만 있으니까 FALSE로 출력해야 함.
*/

// 5. Null 입력 시 예외 테스트 (정상 작동하는 방식)
TEST(string_helper_test, null_입력_시) {
	std::string text = "abc";
	std::string pattern = "a";
	
    EXPECT_THROW(utils::string::string_helper::toUpperCase(nullptr), std::invalid_argument);
    EXPECT_THROW(utils::string::string_helper::toLowerCase(nullptr), std::invalid_argument);
    EXPECT_THROW(utils::string::string_helper::contains(nullptr, &pattern), std::invalid_argument);
    EXPECT_THROW(utils::string::string_helper::contains(&text, nullptr), std::invalid_argument);
    EXPECT_THROW(utils::string::string_helper::contains(nullptr, nullptr), std::invalid_argument);
}
/*
null 입력 시에 예외코드를 출력
std::invalid_argument 은 잘못된 인자인 argument를 함수에 전달했을 때 발생시키는
예외클래스 중 하나임.
따라서 모든 함수에서 예외를 출력해야함.
*/
