# include "vecteur.hpp"
# include <vector>

vecteur::vecteur( const std::initializer_list<double>& coefs) :
    m_coefs{}, m_proxy_norm{-1}
    {
       std::vector<double> arr(coefs);
       m_coefs[0] = arr[0]; m_coefs[1] = arr[1]; m_coefs[2] = arr[2]; 
    }

double vecteur::norm() const
{
    if ( m_proxy_norm < 0. )
        std::cout << "Computing norm" << std::endl;
        m_proxy_norm = std::sqrt(m_coefs[0]*m_coefs[0]+
                                 m_coefs[1]*m_coefs[1]+
                                 m_coefs[2]*m_coefs[2]);
    return m_proxy_norm;
}

vecteur vecteur::operator + ( const vecteur& u ) const
{
    return {x()+u.x(),y()+u.y(),z()+u.z()};
}

vecteur& vecteur::operator = ( const vecteur& u )
{
    if (this != &u)
    {
        m_coefs = u.m_coefs;
    }
    return *this;
}

double vecteur::normalize() {
    double nrm = norm();
    m_coefs[0] = x()/nrm; m_coefs[1] = y()/nrm; m_coefs[2] = z()/nrm;
    return nrm;
}