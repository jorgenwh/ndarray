#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

#include "ndarray.h"

namespace py = pybind11;

PYBIND11_MODULE(ndarray_backend, m) 
{
  m.doc() = "Documentation for the ndarray C backend module";

  py::class_<ndarray>(m, "ndarray")
    .def(py::init([](py::tuple &shape)
    {
      std::vector<int> _shape(shape.size());
      for (int i = 0; i < shape.size(); i++)
      {
        _shape[i] = shape[i].cast<int>();
      }

      return new ndarray(_shape);
    }))

    .def("to_string", &ndarray::to_string)
    .def("size", &ndarray::size)
    ;
}
