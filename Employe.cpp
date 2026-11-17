#include "Employe.h"
#include <iostream>
#include <iomanip>

double Employe::valeurBase = 2.0;

Employe::Employe(const std::string& nom,
    const std::string& matricule,
    double indiceSalarial)
    : nom(nom), matricule(matricule),
    indiceSalarial(indiceSalarial) {
}

void Employe::augmentationGenerale(double nouvelleValeurBase) {
    valeurBase = nouvelleValeurBase;
}

double Employe::calculerSalaire() const {
    return indiceSalarial * valeurBase;
}

void Employe::afficherCaracteristiques() const {
    std::cout << "Matricule : " << matricule
        << " | Nom : " << nom
        << " | Indice : " << indiceSalarial
        << " | Salaire : " << std::fixed
        << std::setprecision(2)
        << calculerSalaire() << " €" << std::endl;
}