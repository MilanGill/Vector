#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>

using namespace std;

const double pi = M_PI;

class Vector
{
private:
    double* v;
    int n;
    double zero;
public:
    Vector():v(&zero),zero(0),n(0) {}
    Vector(int dimension, bool zero = true ) :v(dimension >0?new double[dimension]:nullptr),zero(0),n(dimension) 
    {
        if (zero && v) 
            memset(v, 0, sizeof(v[0]) * n);
    }
    Vector(const Vector& other) : Vector(other.dim())
    {
        for (int i = 0; i < n; i++)
        {
            v[i] = other[i];
        }
    }

    virtual ~Vector()
    {
        if (v) delete[]v;
    }

    Vector& operator = (const Vector other)
    {
        Vector :: ~Vector();
        ::new (this) Vector(other);
        return *this;

    }
    double & operator [] (int i)  
    {
        return v[i];
    }

    const double& operator [] (int i) const
    {
        return v[i];
    }

    int dim() const
    {
        return n;
    }
    double & x() 
    {
        return (*this)[0];
    }
    double & y()
    {
        return (*this)[1];
    }
    double & z()
    {
        return (*this)[2];
    }
    double & u()
    {
        return (*this)[3];
    }

    const double& x() const
    {
        return (*this)[0];
    }
    const double& y() const
    {
        return (*this)[1];
    }
    const double& z() const
    {
        return (*this)[2];
    }
    const double& u() const
    {
        return (*this)[3];
    }

    double operator * (const Vector& other) const
    {
        double sum = 0;
        for (int i = 0, n = min(dim(), other.dim()); i < n; i++)
        {
            sum += v[i] * other[i];
       }
        return sum;
    }

    double sqr() const
    {
        return *this * *this;
    }

    double norm() const
    {
        return sqrt(this->sqr());
    }

    double norm1() const
    {
        double sum = 0; 
        for (int i = 0; i < n; i++)
        {
            sum += fabs(v[i]);
        }
        return sum;
    }

    double norm_inf()
    {
        double M = 0;
        for (int i = 0 ; i < n ; i ++) 
        {
            double a = fabs(v[i]);
            if (a > M) M = a;
        }
        return M;
    }
};



int main()
{
    Vector v(5);
    const Vector u(3);
    cout << v.sqr() << "   " << u.sqr();
    v = u;

    cout << " " << pi;
}

