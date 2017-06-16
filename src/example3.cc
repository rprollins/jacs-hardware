#include "benchmark/benchmark.h"

static void BM_Triad_OpenMP(benchmark::State& state)
{
  size_t N = state.range(0);
  std::vector<double> a(N), b(N), c(N);
  double q = 2.0;
  #pragma omp parallel for
  for(size_t i=0; i<N; i++) { a[i] = 0.0; b[i] = 1.0; c[i] = 2.0; }
  while (state.KeepRunning())
  {
    #pragma omp parallel for
    for(size_t i=0; i<N; i++) { a[i] = b[i] + q * c[i]; }
  }
}
BENCHMARK(BM_Triad_OpenMP)->RangeMultiplier(2)->Range(1, 1<<29);

BENCHMARK_MAIN()
