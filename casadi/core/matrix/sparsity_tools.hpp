/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
 *                            K.U. Leuven. All rights reserved.
 *    Copyright (C) 2011-2014 Greg Horn
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef CASADI_SPARSITY_TOOLS_HPP
#define CASADI_SPARSITY_TOOLS_HPP

#include "sparsity.hpp"

namespace casadi {

/**
\ingroup expression_tools
@{
*/

  /** \brief Reshape the sparsity pattern keeping the relative location of the nonzeros
   */
  CASADI_EXPORT Sparsity reshape(const Sparsity& a, int nrow, int ncol);

  /** \brief Vectorize the pattern */
  CASADI_EXPORT Sparsity vec(const Sparsity& a);

  /** \brief Split up a sparsity pattern diagonally */
  CASADI_EXPORT
    std::vector<Sparsity> diagsplit(const Sparsity& sp,
      const std::vector<int>& output_offset1,
      const std::vector<int>& output_offset2);

  /** \brief  split diagonally, retaining groups of square matrices
  * \param incr Size of each matrix
  *
  *  diagsplit(diagsplit(x, ...)) = x
  */
  CASADI_EXPORT std::vector<Sparsity> diagsplit(const Sparsity& x, int incr=1);

  /** \brief  split diagonally, retaining fixed-sized matrices
  * \param incr1 Row dimension of each matrix
  * \param incr2 Column dimension of each matrix
  *
  *  diagsplit(diagsplit(x, ...)) = x
  */
  CASADI_EXPORT std::vector<Sparsity> diagsplit(const Sparsity& x, int incr1, int incr2);

  /** \brief  split diagonally, retaining square matrices
  * \param output_offset List of all start locations for each group
  *      the last matrix will run to the end.
  *
  *   diagcat(diagsplit(x, ...)) = x
  */
  CASADI_EXPORT std::vector<Sparsity> diagsplit(const Sparsity& x,
                                                   const std::vector<int>& output_offset);

  /// Obtain the structural rank of a sparsity-pattern
  CASADI_EXPORT int rank(const Sparsity& a);

  /// Get upper triangular part
  inline Sparsity triu(const Sparsity& sp, bool includeDiagonal=true)
  { return sp.getTriu(includeDiagonal);}

  /// Get lower triangular part
  inline Sparsity tril(const Sparsity& sp, bool includeDiagonal=true)
  { return sp.getTril(includeDiagonal);}

  /*
  @}
  */
} // namespace casadi

#endif // CASADI_SPARSITY_TOOLS_HPP
