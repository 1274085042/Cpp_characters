#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Tensor
{
private:
    T *data_;
    void Clear()
    {
        if (data_!=nullptr)
        {
            delete[] data_;
        }
    }
public:
bool FromArray(const vector<uint16_t> &shape)
{
    uint16_t total = 1;
    for (int i = 0; i < shape.size();i++)
    {
        total *= shape[i];
    }
    data_ = new T[total];
    cout << "指针的字节："<<sizeof(data_) << endl;
}
    Tensor()
    {
        data_ = nullptr;
    }
~Tensor()
{
    Clear();
}
};
