class Object
{
private:
    /* data */
    int* _data{};
public:
    Object(/* args */): _data{new int{6}} {}
    ~Object() { delete _data; }
    Object(const Object& rhs):_data{new int{*rhs._data}}{}
    Object& operator=(const Object& rhs)
    {
        if (&rhs != this)
        {
            delete _data;
            _data = new int{*rhs._data};
        }
        return *this;
    }

};



