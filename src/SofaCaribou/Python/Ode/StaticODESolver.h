#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;

namespace SofaCaribou::ode::python {

void addStaticODESolver(py::module &m);

}