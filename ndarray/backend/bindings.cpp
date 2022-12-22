#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace py = pybind11;

PYBIND11_MODULE(ndarray_backend, m) 
{
  m.doc() = "Documentation for the ndarray C backend module";
}
