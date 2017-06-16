#include "benchmark/benchmark.h"

template<size_t stride>
static void BM_Stride(benchmark::State& state)
{
  size_t N = 8000000;
  std::vector<int> a(N);
  for(size_t i=0; i<N; i++) { a[i] = 0.0; }
  while (state.KeepRunning()) { for(size_t i=0; i<N; i+=stride) { a[i]++; } }
}

BENCHMARK_TEMPLATE(BM_Stride, 1);
BENCHMARK_TEMPLATE(BM_Stride, 2);
BENCHMARK_TEMPLATE(BM_Stride, 4);
BENCHMARK_TEMPLATE(BM_Stride, 8);
BENCHMARK_TEMPLATE(BM_Stride, 16);
BENCHMARK_TEMPLATE(BM_Stride, 32);
BENCHMARK_TEMPLATE(BM_Stride, 64);
BENCHMARK_TEMPLATE(BM_Stride, 128);
BENCHMARK_TEMPLATE(BM_Stride, 256);

BENCHMARK_MAIN()
