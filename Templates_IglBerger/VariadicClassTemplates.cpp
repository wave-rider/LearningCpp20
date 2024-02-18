#include <cstddef>
template<typename T1, typename T2>
constexpr auto max(T1 const& a, T2 const& b) 
{
    return (a < b ? b : a);
}

template < typename T, typename... Ts>
struct Variant
{
public:
	static constexpr size_t capacity = max(sizeof(T), sizeof(Ts)...);
	static constexpr size_t alignment = max(alignof(T), alignof(Ts)...);

private:
	alignas(alignment) std::array<std::byte, capacity> buffer_;
};

template< typename T, T... Ints>
struct integer_sequence
{
	using value_type = T;
	static constexpr size_t size() noexcept{
		return sizeof...(Ts);
	}
};

template< size_t... Ints >
using index_sequence = integer_sequence<size_t, Ints...>;

template< typename... Ts, size_t... Ints>
void printTuple(std::ostream& os,
				std::tuple<Ts...> const& t,
				std::index_sequence<Ints...> )
				{
					( os << ... << std::get<Ints>(t));
				}

template< typename... Ts >
void printTuple(std::ostream& os, std::tuple<Ts...> const& t)
{
	printTuple(os, t, std::make_index_sequence<sizeof...(Ts)>{});
}