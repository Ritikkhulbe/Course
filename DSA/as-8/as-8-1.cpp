#include <iostream>
using namespace std;

struct LL{
    int data;
    struct LL *next;
};

//head[NULL, 1023] -> [30, 2042] -> [40, 3421] -> [50, NULL] 
//                     1023             2042        3421