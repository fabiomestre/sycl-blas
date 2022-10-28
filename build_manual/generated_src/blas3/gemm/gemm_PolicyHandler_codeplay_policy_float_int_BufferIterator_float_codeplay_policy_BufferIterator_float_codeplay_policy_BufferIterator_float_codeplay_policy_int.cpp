/***************************************************************************
 *
 *  @license
 *  Copyright (C) Codeplay Software Limited
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  For your convenience, a copy of the License has been included in this
 *  repository.
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  SYCL-BLAS: BLAS implementation using SYCL
 *
 *  @filename gemm.cpp.in
 *
 **************************************************************************/
#include "container/sycl_iterator.hpp"
#include "executors/executor_sycl.hpp"
#include "interface/gemm_interface.hpp"
#include "operations/blas_constants.hpp"
#include "policy/sycl_policy_handler.hpp"
#include "views/view_sycl.hpp"

namespace blas {
namespace internal {
// gemm
template typename Executor<PolicyHandler<codeplay_policy>>::policy_t::event_t _gemm(
    Executor<PolicyHandler<codeplay_policy>>& ex, char _TransA, char _TransB, int _M,
    int _N, int _K, float _alpha, BufferIterator<float,codeplay_policy> a_,
    int _lda, BufferIterator<float,codeplay_policy> b_, int _ldb,
    float _beta, BufferIterator<float,codeplay_policy> _C, int _ldc);
// batched gemm
template typename Executor<PolicyHandler<codeplay_policy>>::policy_t::event_t _gemm_batched(
    Executor<PolicyHandler<codeplay_policy>>& ex, char _TransA, char _TransB, int _M,
    int _N, int _K, float _alpha, BufferIterator<float,codeplay_policy> a_,
    int _lda, BufferIterator<float,codeplay_policy> b_, int _ldb,
    float _beta, BufferIterator<float,codeplay_policy> _C, int _ldc,
    int batch_size, gemm_batch_type_t batch_type);
}  // namespace internal
}  // namespace blas

