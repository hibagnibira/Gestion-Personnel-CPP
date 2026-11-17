#include "Personnel.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

void Personnel::ajouterEmploye(Employe* employe) {

    for (const Employe* e : employes) {
        if (e->getMatricule() == employe->getMatricule()) {
            throw std::invalid_argument(
                "Matricule " + employe->getMatricule()
                + " déjà utilisé !");
        }
    }

    employes.push_back(employe);
}

double Personnel::calculerMasseSalariale() const {
    double total = 0.0;

    for (const Employe* emp : employes) {
        total += emp->calculerSalaire();
    }

    return total;
}

void Personnel::afficherToutLePersonnel() const {

    for (const Employe* emp : employes) {
        emp->afficherCaracteristiques();
    }

    std::cout << "Masse salariale totale : "
        << std::fixed << std::setprecision(2)
        << calculerMasseSalariale()
        << " €" << std::endl;
}