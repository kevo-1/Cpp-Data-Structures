#include <iostream>
#include "Vector.h"

int main(){
    Vector<int> vec1;
    for (int i = 0; i < 10; i++)
    {
        vec1.push_into(i+1);
    }
    std::cout<<vec1.length()<<std::endl;
    for (int i = 0; i < 5; i++)
    {
        vec1.pop_last();
    }
    std::cout<<vec1.length()<<'\n';
    for (int i = 0; i < vec1.length(); i++)
    {
        std::cout<<vec1[i]<<' ';
    }
}