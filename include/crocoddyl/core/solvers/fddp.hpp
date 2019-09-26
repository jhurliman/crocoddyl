///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (C) 2018-2019, LAAS-CNRS
// Copyright note valid unless otherwise stated in individual files.
// All rights reserved.
///////////////////////////////////////////////////////////////////////////////

#ifndef CROCODDYL_CORE_SOLVERS_FDDP_HPP_
#define CROCODDYL_CORE_SOLVERS_FDDP_HPP_

#include <Eigen/Cholesky>
#include <vector>
#include "crocoddyl/core/solvers/ddp.hpp"

namespace crocoddyl {

class SolverFDDP : public SolverDDP {
 public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

  explicit SolverFDDP(ShootingProblem& problem);
  ~SolverFDDP();

  bool solve(const std::vector<Eigen::VectorXd>& init_xs = DEFAULT_VECTOR,
             const std::vector<Eigen::VectorXd>& init_us = DEFAULT_VECTOR, unsigned int const& maxiter = 100,
             const bool& is_feasible = false, const double& regInit = 1e-9);
  void computeDirection(const bool& recalc = true);
  double tryStep(const double& steplength = 1);
  const Eigen::Vector2d& expectedImprovement();
  void updateExpectedImprovement();
  double calc();
  void forwardPass(const double& stepLength);

  double get_th_acceptnegstep() const;
  void set_th_acceptnegstep(double th_acceptnegstep);

 protected:
  double dg_;
  double dq_;
  double dv_;

 private:
  double th_acceptnegstep_;
};

}  // namespace crocoddyl

#endif  // CROCODDYL_CORE_SOLVERS_FDDP_HPP_