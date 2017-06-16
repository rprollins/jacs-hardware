#include "benchmark/benchmark.h"
#include <vector>
#include <list>

static void BM_Vector(benchmark::State& state)
{
  size_t N = 4096;
  std::vector<double> a(N), b(N);
  std::fill(a.begin(),a.end(),0.0);
  std::fill(b.begin(),b.end(),1.0);
  while (state.KeepRunning()) { std::copy(b.begin(),b.end(),a.begin()); }
}
BENCHMARK(BM_Vector);

static void BM_List(benchmark::State& state)
{
  size_t N = 4096;
  std::list<double> a(N), b(N);
  std::fill(a.begin(),a.end(),0.0);
  std::fill(b.begin(),b.end(),1.0);
  while (state.KeepRunning()) { std::copy(b.begin(),b.end(),a.begin()); }
}
BENCHMARK(BM_List);

BENCHMARK_MAIN()
