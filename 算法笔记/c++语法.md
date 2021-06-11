#### using LL = long long;
* typedef long long LL;
#### static constexpr double EPS = 1e-7;
* [static修饰符的作用](https://www.runoob.com/w3cnote/cpp-static-usage.html)
* [static, const, static const修饰符](https://blog.csdn.net/ReturningProdigal/article/details/78832095)
* [const和constexpr的区别](https://www.zhihu.com/question/35614219)
* 对于修饰Object而言，const并未区分出编译期和运行期常量，constexpr限定在了编译期常量
* **对于constexpr修饰的函数，返回值不一定是编译器常量，it is not a bug, it is a featrue.**
```c++
#include <iostream>
#include <array>
using namespace std;

constexpr int foo(int i)
{
    return i + 5;
}

int main()
{
    int i = 10;
    std::array<int, foo(5)> arr; // OK
    
    foo(i); // Call is Ok
    
    // But...
    std::array<int, foo(i)> arr1; // Error
   
}
```
* constexpr修饰的函数，简单来说，如果其传入的参数可以在编译时期算出来，那么这个函数就会产生编译时期的值，但是，传入的参数如果不能在编译时期算出来，那么constexpr修饰的函数就和普通函数一样了
* constexpr的作用主要是效率
#### LLONG\_MAX
* long long k = LLONG\_MAX; 则k=9223372036854775807，k约为9e18
* 在需要一个极大值的情况下使用
