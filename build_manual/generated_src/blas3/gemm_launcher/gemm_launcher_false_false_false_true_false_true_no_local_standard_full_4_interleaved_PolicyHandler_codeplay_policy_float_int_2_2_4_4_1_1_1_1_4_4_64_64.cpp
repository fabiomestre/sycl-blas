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
 *  @filename gemm_launcher.cpp.in
 *
 **************************************************************************/

#include "container/sycl_iterator.hpp"
#include "executors/executor_sycl.hpp"
#include "executors/kernel_constructor.hpp"
#include "interface/gemm_launcher.hpp"
#include "operations/blas3_trees.hpp"
#include "operations/extension/reduction.hpp"
#include "operations/blas_constants.hpp"
#include "policy/sycl_policy_handler.hpp"
#include "views/view_sycl.hpp"

namespace blas {
template class Gemm_Launcher<
    64, false, false, false, 64,
    Tile<2, 2, 4, 4, 1, 1, 1, 1, 4, 4>,
    true, false,
    static_cast<int>(gemm_memory_t::no_local),
    static_cast<int>(gemm_algorithm_t::standard),
    static_cast<int>(gemm_vectorization_t::full),
    true, 4,
    static_cast<int>(gemm_batch_type_t::interleaved)>;

template typename Executor<PolicyHandler<codeplay_policy>>::policy_t::event_t Gemm_Launcher<
    64, false, false, false, 64,
    Tile<2, 2, 4, 4, 1, 1, 1, 1, 4, 4>,
    true, false,
    static_cast<int>(gemm_memory_t::no_local),
    static_cast<int>(gemm_algorithm_t::standard),
    static_cast<int>(gemm_vectorization_t::full),
    true, 4,
    static_cast<int>(gemm_batch_type_t::interleaved)>::
    _select_gemm<Executor<PolicyHandler<codeplay_policy>>,
                 BufferIterator<float, codeplay_policy>,
                 BufferIterator<float, codeplay_policy>,
                 BufferIterator<float, codeplay_policy>, float,
                 int>(
        Executor<PolicyHandler<codeplay_policy>>& ex, int _M, int _N,
        int _K, float _alpha,
        BufferIterator<float, codeplay_policy> a_, int _lda,
        BufferIterator<float, codeplay_policy> b_, int _ldb,
        float _beta, BufferIterator<float, codeplay_policy> _C,
        int _ldc, int batch_size);

template typename Executor<PolicyHandler<codeplay_policy>>::policy_t::event_t Gemm_Launcher<
    64, false, false, false, 64,
    Tile<2, 2, 4, 4, 1, 1, 1, 1, 4, 4>,
    true, false,
    static_cast<int>(gemm_memory_t::no_local),
    static_cast<int>(gemm_algorithm_t::standard),
    static_cast<int>(gemm_vectorization_t::full),
    true, 4,
    static_cast<int>(gemm_batch_type_t::interleaved)>::
    _select_gemm<Executor<PolicyHandler<codeplay_policy>>,
                 BufferIterator<float const, codeplay_policy>,
                 BufferIterator<float const, codeplay_policy>,
                 BufferIterator<float, codeplay_policy>, float,
                 int>(
        Executor<PolicyHandler<codeplay_policy>>& ex, int _M, int _N,
        int _K, float _alpha,
        BufferIterator<float const, codeplay_policy> a_, int _lda,
        BufferIterator<float const, codeplay_policy> b_, int _ldb,
        float _beta, BufferIterator<float, codeplay_policy> _C,
        int _ldc, int batch_size);

}  // namespace blas

