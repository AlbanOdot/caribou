#pragma once

#include <SofaCaribou/Solver/EigenSparseSolver.h>
#include <sofa/helper/OptionsGroup.h>

namespace SofaCaribou::solver {

template <class EigenSolver>
class LDLTSolver : public EigenSparseSolver<EigenSolver> {
public:
    SOFA_CLASS(SOFA_TEMPLATE(LDLTSolver, EigenSolver), SOFA_TEMPLATE(EigenSparseSolver, EigenSolver));

    template <typename T>
    using Data = sofa::Data<T>;

    LDLTSolver();
private:
    ///< Solver backend used (Eigen or Pardiso)
    Data<sofa::helper::OptionsGroup> d_backend;
};

} // namespace SofaCaribou::solver
