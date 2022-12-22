#include <iostream>
#include <inttypes.h>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

#include "ndarray.h"

namespace py = pybind11;

template<typename T>
void declare_ndarray(py::module &m, const std::string &typestr)
{
  using Class = ndarray<T>;
  std::string pyclass_name = std::string("ndarray_") + typestr;

  py::class_<Class>(m, pyclass_name.c_str())
    .def(py::init([](py::tuple &shape)
    {
      std::vector<int> _shape(shape.size());
      for (int i = 0; i < shape.size(); i++)
      {
        _shape[i] = shape[i].cast<int>();
      }
      return new Class(_shape);
    }))

    .def("to_string", &Class::to_string)
    .def_property_readonly("size", &Class::size)
    .def_property_readonly("shape", &Class::shape)
    ;
}

PYBIND11_MODULE(ndarray_backend, m) 
{
  m.doc() = "Documentation for the ndarray C backend module";

  declare_ndarray<int32_t>(m, "int32");
  declare_ndarray<float>(m, "float32");
}
