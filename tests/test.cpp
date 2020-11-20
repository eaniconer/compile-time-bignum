//
// Created by Egor Basharin on 21.11.2020.
//

#include <bignum.hpp>

#include <type_traits>

using namespace bignum;

namespace test1 {

constexpr char rawNum[] = "100";
using Num = typename BigNumBuilder<rawNum>::type;
static_assert(std::is_same_v<Num, BigNum<Base<10>, Sign::plus, 1, 0, 0>>);

} // namespace test1

namespace test2 {

constexpr char rawNum[] = "100";
using Num = typename BigNumBuilder<rawNum, Base<10>>::type;
static_assert(std::is_same_v<Num, BigNum<Base<10>, Sign::plus, 1, 0, 0>>);

} // namespace test2

namespace test3 {

constexpr char rawNum[] = "-100";
using Num = typename BigNumBuilder<rawNum, Base<10>>::type;
static_assert(std::is_same_v<Num, BigNum<Base<10>, Sign::minus, 1, 0, 0>>);

} // namespace test3

namespace test4 {

constexpr char rawNum[] = "13932";
using Num = typename BigNumBuilder<rawNum>::type;
using NegativeNum = typename Negate<Num>::type;

static_assert(std::is_same_v<NegativeNum, BigNum<Base<10>, Sign::minus, 1, 3, 9, 3, 2>>);

} // namespace test4

int main() {
    return 0;
}


