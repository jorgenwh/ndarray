#ifndef NDARRAY_H_
#define NDARRAY_H_

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <inttypes.h>

#include "dtype.h"

template<typename T>
class ndarray 
{
public:
  ndarray(std::vector<int> &shape, uint16_t dtype);
  ~ndarray();

  std::vector<int> shape() const { return shape_m; }
  int size() const { return size_m; }
  int bytes() const { return size_m*sizeof(T); }
  std::string to_string() const;

  void apply_arange(int start, int step);
private:
  uint16_t dtype_m;
  std::vector<int> shape_m;
  int size_m;
  T *data_m;
};

#endif // NDARRAY_H_
