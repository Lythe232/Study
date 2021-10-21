#include <iostream>
#include <math.h>
/* 
    对称矩阵压缩算法，实现杨辉三角
 */
typedef int elem;

class Arr
{
private:
    elem *data;
    int size;
public:
    Arr(int s){ data = new elem[s]; size = s; }
    ~Arr(){ delete [] data; }
    void fill(int p, int n)
    {
        p--;
        if(size <= p) return;
        *(data + p) = n;
    }
    int call(int q)
    {
        q--;
        return *(data + q);
    }
    void show(int s)
    {
        s--;
        std::cout << *(data + s);
    }

};



int main()
{
    int size;
    std::cout << "Please enter the number of rows of YangHui triangle: ";
    std::cin >> size;
    int arrsize = (1 + size) * size / 2;
    Arr arr(arrsize);

    for(int i = 1; i <= arrsize; i++)
    {
        arr.fill(i, 1);
    }
    for(int i = 2; i < size; i++)
    {
        for(int j = 2; j <= i; j++)
        {
            int temp = ((i + 1) * i) / 2 + j;   //矩阵对应一维数组的位置
            int s1 = ((i) * (i - 1)) / 2 + j - 1;
            int s2 = ((i) * (i - 1)) / 2 + j;
            int s3 = arr.call(s1) + arr.call(s2);
            arr.fill(temp, s3);
        }
    }

    for(int c = 1; c <= size; c++)
    {
        for(int j = 1; j <= c; j++)
        {
            int temp = ((c - 1) * c) / 2 + j;
            std::cout << arr.call(temp) << " ";
        }
        std::cout << "\n";
    }
    return 0;
}