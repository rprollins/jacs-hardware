#include "benchmark/benchmark.h"

static void BM_Triad(benchmark::State& state)
{
  size_t N = state.range(0);
  std::vector<double> a(N), b(N), c(N);
  double q = 2.0;
  for(size_t i=0; i<N; i++) { a[i] = 0.0; b[i] = 1.0; c[i] = 2.0; }
  while (state.KeepRunning()) { for(size_t i=0; i<N; i++) { a[i] = b[i] + q * c[i]; } }
}
BENCHMARK(BM_Triad)->RangeMultiplier(2)->Range(1, 1<<29);

BENCHMARK_MAIN()
