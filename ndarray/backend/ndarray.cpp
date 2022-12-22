#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "ndarray.h"

ndarray::ndarray(std::vector<int> &shape)
{
  shape_m = shape;
  size_m = 1;
  for (int i = 0; i < shape_m.size(); i++)
  {
    size_m *= shape_m[i];
  }
}

ndarray::~ndarray() 
{
  ;
}

std::string ndarray::to_string() const
{
  std::ostringstream oss;
  oss << "ndarray([";

  int elems = std::min(10, size_m);
  for (int i = 0; i < elems; i++)
  {
    //oss << data_m[i];
    oss << i;
    if (i < (elems - 1)) 
    { 
      oss << ", "; 
    }
  }
  oss << "], dtype=None)";

  return oss.str();
}
