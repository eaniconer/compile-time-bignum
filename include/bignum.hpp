//
// Created by Egor Basharin on 21.11.2020.
//

#ifndef COMPILE_TIME_BIGNUM_INCLUDE_BIGNUM_HPP_
#define COMPILE_TIME_BIGNUM_INCLUDE_BIGNUM_HPP_
#pragma once

#include <cstddef>
#include <utility>

namespace bignum {

template <size_t Value>
class Base { };

enum class Sign {
    plus,
    minus
};

template <class Base, Sign sign, int... digits>
class BigNum {};

namespace utils {

constexpr size_t strlen(const char* s) {
    if (*s == 0) return 0;
    return 1 + strlen(s + 1);
}

template <const char* s, class Base, class T = void>
struct BigNumBuilder;

template <const char* s, class Base, size_t... Is>
struct BigNumBuilder<s, Base, std::integer_sequence<size_t, Is...>> {
    using type = BigNum<Base, Sign::plus, (*(s + Is) - '0')...>;
};

} // namespace utils

template <const char* s, class Base = Base<10>>
class BigNumBuilder {
public:
    using type = typename utils::BigNumBuilder<s, Base, std::make_integer_sequence<size_t, utils::strlen(s)>>::type;
};

} // namespace bignum

#endif //COMPILE_TIME_BIGNUM_INCLUDE_BIGNUM_HPP_
