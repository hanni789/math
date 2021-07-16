#include <math.h>

double secant(double x_1, double x_2, double eps=0.000001, int max_iter=100)
{
    int iter = 0; 
    double x_k;
    do
    {
        x_k = x_2 - function(x_2) * (x_2 - x_1) / (function(x_2) - function(x_1));
        x_1 = x_2;
        x_2 = x_k;
        iter++;
    } while (std::fabs(function(x_k)) > eps && iter < max_iter);
    
    return x_k;
    
}

double num_derivation(double x)
{
    double df;
    double h = std::pow(10, -(12));
    df = (function(x + h) - function(x)) / h;  
    return df;
}

double newton(double x_1, double max_iter=100, double eps=0.000001)
{
    double iter = 0;
    double x_k;
    do
    {
        x_k = x_1 - (function(x_1) / num_derivation(x_1));
        x_1 = x_k;
        iter++;
    } while (std::fabs(function(x_k)) > eps && iter < max_iter);
    return x_k;
}