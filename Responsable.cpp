#include "Responsable.h"
#include <iostream>
#include <iomanip>

Responsable::Responsable(const std::string& nom,
    const std::string& matricule,
    double indiceSalarial)
    : Employe(nom, matricule, indiceSalarial) {
}

void Responsable::ajouterSubordonne(Employe* employe) {
    subordonnes.push_back(employe);
}

void Responsable::collecterSubordonnes(
    const std::vector<Employe*>& liste,
    const std::string& prefixe) const {

    for (const Employe* emp : liste) {
        std::cout << prefixe << emp->getNom()
            << " (" << emp->getMatricule()
            << ") — salaire : "
            << std::fixed << std::setprecision(2)
            << emp->calculerSalaire() << " €"
            << std::endl;

        const Responsable* sousResp =
            dynamic_cast<const Responsable*>(emp);

        if (sousResp != nullptr) {
            sousResp->collecterSubordonnes(
                sousResp->subordonnes, prefixe + "  ");
        }
    }
}

void Responsable::afficherSubordonnesDirects() const {
    std::cout << "Subordonnés directs de " << nom << " :"
        << std::endl;

    if (subordonnes.empty()) {
        std::cout << "  (aucun)" << std::endl;
        return;
    }

    for (const Employe* emp : subordonnes) {
        std::cout << "  - " << emp->getNom()
            << " (" << emp->getMatricule()
            << ") — salaire : "
            << std::fixed << std::setprecision(2)
            << emp->calculerSalaire() << " €"
            << std::endl;
    }
}

void Responsable::afficherSubordonnesIndirects() const {
    std::cout << "Tous les subordonnés de " << nom
        << " (directs et indirects) :"
        << std::endl;

    collecterSubordonnes(subordonnes, "  - ");
}