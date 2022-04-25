/*
* @Author: ACacti
* @Date:   2022-04-15 20:54:43
* @Last Modified by:   shang
* @Last Modified time: 2022-04-17 21:47:07
*/
#include <iostream>
template <typename A, typename B>
void foo(A a, B b){
    std::cout << a << std::endl << b << std::endl;
}

int main()
{
    foo(1, 23.2);

    return 0;
}