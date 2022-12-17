#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <string>

using namespace std;

enum gender {male, female};

// int a;
vector < tuple <string, string, gender> > owners2 = { make_tuple(string("Dasha"), string("Chicago"), female)};
// , 
//   make_tuple("Alexey", "Romanov", male) };


#endif // DATA_H