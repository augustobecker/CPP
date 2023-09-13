#include <iostream>

template <typename T>
T const& min(T const &x, T const &y)
{
    return ((x <= y) ? x : y);
}

template <typename T>
T const& max(T const &x, T const &y)
{
    return ((x >= y) ? x : y);
}

template <typename T>
void swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main(void)
{
    int a = 2;
    int b = 3;
    swap<int>(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << min<int>(a, b) << std::endl;
    std::cout << "max( a, b ) = " << max<int>(a, b) << std::endl;
    
    // std::string c = "chaine1";
    // std::string d = "chaine2";
    // swap(c, d);
    // std::cout << "c = " << c << ", d = " << d << std::endl;
    // std::cout << "min( c, d ) = " << min(c, d) << std::endl;
    // std::cout << "max( c, d ) = " << max(c, d) << std::endl;
    
    return 0;
}
