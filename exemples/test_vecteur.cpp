#include <iostream>
#include "vecteur.hpp"

int main( ) {
    vecteur u{3.,4.,5.};
    vecteur v{u};
    vecteur w = {1.,2.,3.};
    vecteur z(3.);
    v.normalize();
    w = u+v;
    std::cout << "w = " << w << std::endl;
    std::cout << "||u|| = " << u.norm() << std::endl;
    u[vecteur::X] = 2.;
    std::cout << "||u|| = " << u.norm() << std::endl;
    v[vecteur::Y] = u[vecteur::X];
    v[vecteur::X] = vecteur{1.,3.,5.}[vecteur::Z];
    std::cout << "||u|| = " << u.norm() << std::endl;
    std::cout << "v = " << v << std::endl;
    return EXIT_SUCCESS;
}