#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace SofaCaribou::topology::python {

void addFictitiousGrid(py::module &m);

}