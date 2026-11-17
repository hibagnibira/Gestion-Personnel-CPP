#include "Commercial.h"

const double Commercial::SALAIRE_FIXE = 1500.0;
const double Commercial::TAUX_COMMISSION = 0.05;

Commercial::Commercial(const std::string& nom,
    const std::string& matricule,
    double indiceSalarial,
    double ventes)
    : Employe(nom, matricule, indiceSalarial),
    ventes(ventes) {
}

void Commercial::mettreAJourVentes(double montantVentes) {
    ventes = montantVentes;
}

double Commercial::calculerSalaire() const {
    return SALAIRE_FIXE + TAUX_COMMISSION * ventes;
}