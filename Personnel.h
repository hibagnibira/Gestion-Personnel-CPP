#pragma once
#include "Employe.h"
#include <vector>

class Personnel {
private:
    std::vector<Employe*> employes;

public:
    void ajouterEmploye(Employe* employe);

    double calculerMasseSalariale() const;

    void afficherToutLePersonnel() const;
};