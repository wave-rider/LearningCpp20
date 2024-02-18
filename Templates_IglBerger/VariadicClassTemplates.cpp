#include <cstddef>
template < typename T, typename... Ts>
struct Variant
{
public:
	static constexpr size_t capacity = max(sizeof(T), sizeof(Ts)...);
	static constexpr size_t alignment = max(alignof(T), alignof(Ts)...);

private:
	alignas(alignment) std::array<std::byte, capacity> buffer_;
};