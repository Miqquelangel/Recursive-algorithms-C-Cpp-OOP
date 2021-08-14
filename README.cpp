
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;



class Recursive
{
public:

    int Suma_numeros_reales(int m, int n)
    {
        int s = 0;
        int i;
        for (i = m; i <= n; i++)
            s = s + i;
        return s;

    }
    
    double taylor_orden_n2(int x, int n)
    {
        static double c=1;
        static double d=1;
        double r;
        if (n == 0)
            return 1;
        r=taylor_orden_n2(x, n - 1);
        c = c * x;
        d = d * n;
        return r + c/d;
    }
    double taylor_recursive_orden_n(int x, int n)
    {
        static double s = 1;
        if (n == 0)
            return s;
       
        s = 1 + s*x / n;
        return taylor_recursive_orden_n(x, n - 1);

    }

    double taylor_iterative_orden_n(int x, int n)
    {
        double s = 1;
        for (; n > 0; n--)
            s = 1 + s * x / n;
        return s;
    }

    
    int cuenta_atras(int x)
    {
        if (x == 0)
            return 0;
        printf("%d\n", x);
        cuenta_atras(x - 1);
    }

    int exponential(int x, int n)
    {
        if (n == 0)
            return 1;
        if (n % 2 == 0)
            return exponential(x * x, n / 2);
        else
            return exponential(x * x, (n - 1) / 2) * x;
    }

    int factorial_iterative(int n)
    {
        static int s = 1;
        int i;
        if (n == 0)
            return 1;
        for (i = 1; i <= n; i++)
        {
            s = s * i;
        }
        return s;
    }

    int fibonacci_iterative_order_n(int n)
    {
        int a = 0;
        int b = 1;
        int c;
        int i;
        for (i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    int fibonacci_memoization_order_n(int n)
    {
        // inicializar un array con los mismos valores para poder almacenar los resultados
        int i;
        
        
        int F[500];
        for (i = 0; i < 500; i++)
            F[i] = -1;
        if (n <= 1)
        {
            F[n] = n;
            return n;
        }
        else
        {
            if (F[n - 2] == -1)
                F[n - 2] = fibonacci_memoization_order_n(n - 2);
            if (F[n - 1] == -1)
                F[n - 1] = fibonacci_memoization_order_n(n - 1);

            return F[n - 2] + F[n - 1];
        }
    }

    int tower_of_hanoi(int n, int a, int b, int c)
    {
        
        static int s = 0;
        if (n > 0)
        {
            toh(n - 1, a, c, b);
            s = s++;
            toh(n - 1, b, a, c);
        }
 
        
        return s;
    }

 
    int ncr_pascal(int x, int r)
    {
        if (x == r || r==0)
            return 1;
        return ncr_pascal(x - 1, r - 1) + ncr_pascal(x - 1, r);
    }
        
};

    


int main()
{
    Recursive r;
    
    cout << r.cuenta_atras(2) << endl;


    return 0;
}
