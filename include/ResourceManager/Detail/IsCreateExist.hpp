#ifndef RESOURCEMANAGER_DETAIL_ISCREATOREXIST_HPP_
#define RESOURCEMANAGER_DETAIL_ISCREATOREXIST_HPP_

#include <type_traits>

namespace Resource
{

namespace Detail
{

template <typename, typename>
struct IsCreateExist : std::false_type
{
};

template <typename ClassType, typename ReturnType, typename... Arguments>
struct IsCreateExist<ClassType, ReturnType(Arguments...)>
{
private:
    template <typename Type>
    static constexpr auto check(int) -> typename std::is_same<
        decltype(std::declval<Type>().create(std::declval<Arguments>()...)),
        ReturnType>::type;

    template <typename>
    static constexpr auto check(...) -> std::false_type;

public:
    static constexpr bool value = decltype(check<ClassType>(0))::value;
};

} // namespace Detail

} // namespace Resource

#endif // RESOURCEMANAGER_DETAIL_ISCREATOREXIST_HPP_
