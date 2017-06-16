# JACS: Understanding Hardware Performance

JACS is a series of introductory computing sessions aimed at new postgraduate students at the Jodrell Bank Centre for Astrophysics. For more information visit [jbca-jacs.bitbucket.io](https://jbca-jacs.bitbucket.io/).

The inherent performance limits of computer hardware and the effects that they have on software performance can seem unintuitive to novice programmers. This session will develop a general mental model for computation, memory access and locality and use it to explain the performance of a range of simple benchmarks run on CPUs. All examples are in C++ but only a basic level of programming in any language is required.

The examples use the [Google Benchmark](https://github.com/google/benchmark) library. To build them you should clone the repository and invoke the [Makefile](Makefile):

```
git clone git@github.com:rprollins/jacs-hardware.git
cd jacs-hardware
make all
```

By the end of the session you should understand the relative performance of the examples in terms of architectural features of the hardware they are run on.
