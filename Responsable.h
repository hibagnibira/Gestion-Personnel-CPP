#pragma once
#include "Employe.h"
#include <vector>

class Responsable : public Employe {
private:
    std::vector<Employe*> subordonnes;

    void collecterSubordonnes(
        const std::vector<Employe*>& liste,
        const std::string& prefixe) const;

public:
    Responsable(const std::string& nom,
        const std::string& matricule,
        double indiceSalarial);

    void ajouterSubordonne(Employe* employe);

    void afficherSubordonnesDirects() const;
    void afficherSubordonnesIndirects() const;
};
