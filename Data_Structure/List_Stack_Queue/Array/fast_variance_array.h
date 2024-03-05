/*
1.3.2 연습문제 : 빠르고 번용적인 데이터 저장 컨테이너 만들기
다양한 타입의 데이터 여러개를 인자로 받아 공통 타입으로 변환하는 함수
컨테이너의 모든 인자를 공통타입으로 변환하여 저장하며, 전체 원소를 빠르게 순회
*/

#include<array>
#include<iostream>
#include<type_traits>

template<typename ... Args> // ... = 템플릿 파라미터 팩; 0개 이상의 템플릿 인자들을 나타냄
auto build_array(Args&&  ...args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)> // -> 뒷부분은 반환 타입을 정의해주는거임 (python처럼)
{// common_type은 Args의 공통타입을 설정해주는거임
// sizeof...(a) 는 a의 개수를 return (예를 들어 a = {1,2,3,6}이면 4를 리턴함)
    using commonType = typename std::common_type<Args...>::type;
    return {std::forward<commonType>((Args&&)args)...};
}