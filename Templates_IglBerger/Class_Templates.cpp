#include <stddef.h>
template  < typename Type, size_t Capacity >
class FixedVector 
{
    private:
    alignas(Type) std::array<std::byte,Capacity*sizeof(Type)> buffer_;
    size_t size_{};
    public:
    FixedVector() = default;
    explicit FixedVector(size_t size, Type const& value = Type{})
    : size_{size}
    {
        checkSize(size);
        std::unitialized_fill( begin(), end(), value);
    }
    ~FixedVector()
    {
        std::destroy(begin(), end());
    }
    size_t size() const;

    using iterator = Type*;
    using const_iterator = Type const*;

    iterator begin();
    const_iterator begin() const { return data; }
    iterator end() { return data+size_; }
    const_iterator end() { return data+size_; }

    Type* data() { return reinterpret_cast<Type*>(buffer_.data); }
    Type const* data() const { return reinterpret_cast<Type const*>(buffer_.data); }
    
    void push_back(Type const& value)
    {
        checkSize(size_ + 1);
        std::construct_at(end(), value);
        ++size_;
    }

    void push_back( Type&& value )
    {
        checkSize(size_ + 1);
        std::construct_at(end(), std::move(value));
        ++size_;
    }
};

template< typename Type, size_t Capacity >
size_t FixedVector<Type,Capacity>::size() const
 { return size_; }

template< typename Type, size_t Capacity >
auto FixedVector<Type, Capacity>::begin() -> iterator
 { 
    return data; 
}
