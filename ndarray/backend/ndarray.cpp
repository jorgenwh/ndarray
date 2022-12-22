#include <inttypes.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "ndarray.h"

template<typename T>
ndarray<T>::ndarray(std::vector<int> &shape)
{
  shape_m = shape;
  size_m = 1;
  for (int i = 0; i < shape_m.size(); i++)
  {
    size_m *= shape_m[i];
  }

  data_m = new T[size_m];
  for (int i = 0; i < size_m; i++)
  {
    data_m[i] = (T)i;
  }
}

template<typename T>
ndarray<T>::~ndarray() 
{
  delete[] data_m;
}

template<typename T>
std::string ndarray<T>::to_string() const
{
  std::ostringstream oss;
  oss << "[";

  int elems = std::min(10, size_m);
  for (int i = 0; i < elems; i++)
  {
    oss << data_m[i];
    if (i < (elems - 1)) 
    { 
      oss << ", "; 
    }
  }
  oss << "]";

  return oss.str();
}

template ndarray<int32_t>::ndarray(std::vector<int> &shape);
template ndarray<int32_t>::~ndarray();
template std::string ndarray<int32_t>::to_string() const;

template ndarray<float>::ndarray(std::vector<int> &shape);
template ndarray<float>::~ndarray();
template std::string ndarray<float>::to_string() const;
