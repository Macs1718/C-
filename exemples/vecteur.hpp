// clang -5.0
// sublime_text
#ifndef _VECTEUR_HPP_
#define _VECTEUR_HPP_
#include <utility>
#include <iostream>
#include <cmath>
#include <array>

class vecteur
{
  public:
    enum Dir {
        X = 0,
        Y = 1,
        Z = 2
    };
    
    vecteur() : m_coefs(), m_proxy_norm{-1} { }
    vecteur(double cx, double cy, double cz): m_coefs({cx,cy,cz}), m_proxy_norm{-1}
    { }
    vecteur( const std::initializer_list<double>& coefs );
    vecteur(double cx ) : m_coefs({cx,cx,cx}), m_proxy_norm{-1} { } 
    vecteur(const vecteur& u) = default;
    vecteur(vecteur&& ) = default;
    ~vecteur() = default;

    double normalize();
    double norm() const;
    vecteur operator + ( const vecteur& u ) const;
    vecteur& operator = ( const vecteur& u );
    vecteur& operator = ( vecteur&&  ) = default;
    double x() const { return m_coefs[0]; }
    double y() const { return m_coefs[1]; }
    double z() const { return m_coefs[2]; }

    double& operator [] ( Dir d ) & {
#       if defined(TRACE)        
        std::cerr << "lhs accessor" << std::endl;
#       endif
        m_proxy_norm = -1.;
        return m_coefs[d];
    }

    double& operator [] ( Dir d ) && {
#       if defined(TRACE)        
        std::cerr << "rhs accessor" << std::endl;
#       endif
        return m_coefs[d];
    }

    const double& operator [] ( Dir d ) const & {
#       if defined(TRACE)        
        std::cerr << "Cte accessor " << std::endl;
#       endif
        return m_coefs[d];
    }

private:
    std::array<double,3> m_coefs;
    mutable double m_proxy_norm;
};

inline std::ostream& operator << ( std::ostream& out, const vecteur& u)
{ 
    out << "[" << u.x() << ", " << u.y() <<  ", " << u.z() << "]";
    return out;
}
#endif