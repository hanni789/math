#include <math.h>
#include <complex>
#include <valarray>
#include <iostream>

// using std::vector;
using std::complex;
using std::valarray;

void fft(valarray <complex<double>> &x)
{    
    const size_t n = x.size;

    valarray <complex<double>> even = x[std::slice(0, n/2, 2)];
    valarray <complex<double>> odd = x[std::slice(1, n/2, 2)];

    fft(even);
    fft(odd);

    for (size_t i = 0; i < n/2; ++i)
    {
        complex<double> t = std::polar(1.0, -2 * M_PI * i/n) * odd[i];
        x[i] = even[i] + t;
        x[i+n/2] = even[i] - t;
    }
    
}

