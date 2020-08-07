#include "src/data.cpp"

int main()
{
    vector<uint16_t> shape = {4, 300, 400};
    Tensor<int> out;
    out.FromArray(shape);
    system("pause");
    return 0;
} 