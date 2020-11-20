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
struct BigNum {
    using negate_type = BigNum<
        Base,
        sign == Sign::minus ? Sign::plus : Sign::minus,
        digits...>;
};

namespace utils {

constexpr size_t strlen(const char* s) {
    if (*s == 0) return 0;
    return 1 + strlen(s + 1);
}

template <const char* s, size_t offset>
struct StringView {
    static constexpr const char* str = s + offset;
};

template <class StringView, class Base, Sign sign, class T = void>
struct BigNumBuilder;

template <class StringView, class Base, Sign sign, size_t... Is>
struct BigNumBuilder<StringView, Base, sign, std::integer_sequence<size_t, Is...>> {
    using type = BigNum<
        Base,
        sign,
        (*(StringView::str + Is) - '0')...>;
};

} // namespace utils

template <const char* s, class Base = Base<10>>
class BigNumBuilder {
    static_assert(std::is_same_v<Base, bignum::Base<10>>, "Only Base<10> supported");

    static constexpr bool has_minus = (*s == '-');
    static constexpr size_t offset = (has_minus ? 1 : 0);
    using StringView = utils::StringView<s, offset>;
public:
    using type = typename utils::BigNumBuilder<
        StringView,
        Base,
        has_minus ? Sign::minus : Sign::plus,
        std::make_integer_sequence<size_t, utils::strlen(s + offset)>>::type;
};

template <class BigNum>
struct Negate {
    using type = typename BigNum::negate_type;
};

} // namespace bignum

#endif //COMPILE_TIME_BIGNUM_INCLUDE_BIGNUM_HPP_
