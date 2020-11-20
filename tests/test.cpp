//
// Created by Egor Basharin on 21.11.2020.
//

#include <bignum.hpp>

#include <type_traits>

using namespace bignum;

namespace test1 {

constexpr char rawNum1[] = "100";
constexpr char rawNum2[] = "200";

using Num1 = typename BigNumBuilder<rawNum1>::type;
using Num2 = typename BigNumBuilder<rawNum2>::type;

static_assert(std::is_same_v<Num1, BigNum<Base<10>, Sign::plus, 1, 0, 0>>);
static_assert(std::is_same_v<Num2, BigNum<Base<10>, Sign::plus, 2, 0, 0>>);

} // namespace test1

namespace test2 {

constexpr char rawNum1[] = "100";
constexpr char rawNum2[] = "200";

using Num1 = typename BigNumBuilder<rawNum1, Base<10>>::type;
using Num2 = typename BigNumBuilder<rawNum2, Base<10>>::type;

static_assert(std::is_same_v<Num1, BigNum<Base<10>, Sign::plus, 1, 0, 0>>);
static_assert(std::is_same_v<Num2, BigNum<Base<10>, Sign::plus, 2, 0, 0>>);

} // namespace test2

int main() {
    return 0;
}


