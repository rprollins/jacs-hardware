#include "benchmark/benchmark.h"

template<size_t stride>
static void BM_Stride(benchmark::State& state)
{
  size_t N = 8000000;
  size_t repeat = 10000;
  std::vector<int> a(N);
  for(size_t i=0; i<N; i++) { a[i] = 0.0; }
  while (state.KeepRunning())
  {
    size_t i = 0;
    for(size_t r=0; r<repeat; r++) { a[i]++; i = (i+stride) % N; }
  }
}

BENCHMARK_TEMPLATE(BM_Stride, 31);
BENCHMARK_TEMPLATE(BM_Stride, 32);
BENCHMARK_TEMPLATE(BM_Stride, 33);
BENCHMARK_TEMPLATE(BM_Stride, 63);
BENCHMARK_TEMPLATE(BM_Stride, 64);
BENCHMARK_TEMPLATE(BM_Stride, 65);
BENCHMARK_TEMPLATE(BM_Stride, 127);
BENCHMARK_TEMPLATE(BM_Stride, 128);
BENCHMARK_TEMPLATE(BM_Stride, 129);
BENCHMARK_TEMPLATE(BM_Stride, 255);
BENCHMARK_TEMPLATE(BM_Stride, 256);
BENCHMARK_TEMPLATE(BM_Stride, 257);
BENCHMARK_TEMPLATE(BM_Stride, 383);
BENCHMARK_TEMPLATE(BM_Stride, 384);
BENCHMARK_TEMPLATE(BM_Stride, 385);
BENCHMARK_TEMPLATE(BM_Stride, 511);
BENCHMARK_TEMPLATE(BM_Stride, 512);
BENCHMARK_TEMPLATE(BM_Stride, 513);

BENCHMARK_MAIN()
