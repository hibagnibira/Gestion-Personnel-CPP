#pragma once
#include "Employe.h"

class Commercial : public Employe {
private:
    double ventes;

    static const double SALAIRE_FIXE;
    static const double TAUX_COMMISSION;

public:
    Commercial(const std::string& nom,
        const std::string& matricule,
        double indiceSalarial,
        double ventes = 0.0);

    void mettreAJourVentes(double montantVentes);

    double calculerSalaire() const override;
};