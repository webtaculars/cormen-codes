# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <omp.h>

using namespace std;

int main ( void );
void jacobi ( int n, double a[], double b[], double x[], double x_old[] );
void r8vec_uniform_01 ( int n, int *seed, double r[] );

//****************************************************************************80

int main ( void )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for JACOBI.
//
{
  double *a;
  double *b;
  int i;
  int j;
  int n = 500;
  double row_sum;
  int seed;
  double *x;
  double *x_old;

  a = new double[n*n];
  b = new double[n];
  x = new double[n];
  x_old = new double[n];

  cout << "\n";
  cout << "JACOBI\n";
  cout << "  C++ version\n";
  cout << "  Number of threads = " << omp_get_max_threads ( ) << "\n";
  cout << "  Problem size N = " << n << "\n";

  seed = 123456789;

  r8vec_uniform_01 ( n * n, &seed, a );

  for ( i = 0; i < n; i++ )
  {
    row_sum = 0.0;
    for ( j = 0; j < n; j++ )
    {
      row_sum = row_sum + fabs ( a[i+j*n] );
    }
    a[i+i*n] = 1.0 + 2.0 * row_sum;
  }

  for ( i = 0; i < n; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < n; i++ )
  {
    b[i] = 0.0;
    for ( j = 0; j < n; j++ )
    {
      b[i] = b[i] + a[i+j*n] * x[j];
    }
  }

  r8vec_uniform_01 ( n, &seed, x );

  jacobi ( n, a, b, x, x_old );

  delete [] a;
  delete [] b;
  delete [] x;
  delete [] x_old;

  return 0;
}
//****************************************************************************80

void jacobi ( int n, double a[], double b[], double x[], double x_old[] )

//****************************************************************************80
//
//  Purpose:
//
//    JACOBI carries out the Jacobi iteration.
//
{
  double axi;
  double diff;
  double diff_tol;
  int i;
  int it;
  int it_max = 100;
  int j;
  double r8_epsilon = 1.0E-14;
  double wtime;
  double wtime1;
  double wtime2;

  diff_tol = 0.0;
  for ( i = 0; i < n; i++ )
  {
    diff_tol = diff_tol + fabs ( b[i] );
  }
  diff_tol = ( diff_tol + 1.0 ) * r8_epsilon;

  wtime1 = omp_get_wtime ( );

  for ( it = 1; it <= it_max; it++ )
  {

    for ( i = 0; i < n; i++ )
    {
      x_old[i] = x[i];
    }

    for ( i = 0; i < n; i++ )
    {
      axi = 0.0;
      for ( j = 0; j < n; j++ )
      {
        axi = axi + a[i+j*n] * x_old[j];
      }
      x[i] = x_old[i] + ( b[i] - axi ) / a[i+i*n];
    }

    diff = 0.0;
    for ( i = 0; i < n; i++ )
    {
      diff = diff + fabs ( x[i] - x_old[i] );
    }

    cout << "  " << setw(8) << it
         << "  " << setw(14) << diff << "\n";

    if ( diff <= diff_tol )
    {
      break;
    }
  }

  wtime2 = omp_get_wtime ( );
  wtime = wtime2 - wtime1;

  cout << "\n";
  cout << "DIFF     = " << diff << "\n";
  cout << "DIFF_TOL = " << diff_tol << "\n";
  cout << "Time     = " << wtime  << "\n";

  for ( i = 0; i < 10; i++ )
  {
    cout << "  " << setw(8) << i
         << "  " << setw(14) << x[i] << "\n";
  }

  return;
}
//****************************************************************************80

void r8vec_uniform_01 ( int n, int *seed, double r[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_01 returns a unit pseudorandom vector.
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input/output, int *SEED, a seed for the random number generator.
//
//    Output, double R[N], the vector of pseudorandom values.
//
{
  int i;
  int i4_huge = 2147483647;
  int k;

  if ( *seed == 0 )
  {
    cerr << "\n";
    cerr << "R8VEC_UNIFORM_01 - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + i4_huge;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }

  return;
}

