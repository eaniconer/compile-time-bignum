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

constexpr size_t str_len(const char* s) {
    if (*s == 0) return 0;
    return 1 + str_len(s + 1);
}

template <const char* s, class Base, class T = void>
struct BigNumBuilderHelper;

template <const char* s, class Base, size_t... Is>
struct BigNumBuilderHelper<s, Base, std::integer_sequence<size_t, Is...>> {
using type = BigNum<Base, Sign::plus, (*(s + Is) - '0')...>;
};

template <const char* s, class Base = Base<10>>
class BigNumBuilder {
public:
    using type = typename BigNumBuilderHelper<s, Base, std::make_integer_sequence<size_t, str_len(s)>>::type;
};

} // namespace bignum

#endif //COMPILE_TIME_BIGNUM_INCLUDE_BIGNUM_HPP_
