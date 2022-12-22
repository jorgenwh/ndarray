#ifndef NDARRAY_H_
#define NDARRAY_H_

#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

template<typename T>
class ndarray 
{
public:
  ndarray() = default;
  ndarray(std::vector<int> &shape);
  ~ndarray();

  std::vector<int> shape() const { return shape_m; }
  int size() const { return size_m; }
  std::string to_string() const;

private:
  std::vector<int> shape_m;
  int size_m;
  T *data_m;
};

#endif // NDARRAY_H_
