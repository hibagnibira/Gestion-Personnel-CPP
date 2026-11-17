#pragma once
#include <string>

class Employe {
protected:
    std::string nom;
    std::string matricule;
    double indiceSalarial;

    static double valeurBase;

public:
    Employe(const std::string& nom, const std::string& matricule,
        double indiceSalarial);

    virtual ~Employe() = default;

    static void augmentationGenerale(double nouvelleValeurBase);

    virtual double calculerSalaire() const;
    virtual void afficherCaracteristiques() const;

    const std::string& getNom() const { return nom; }
    const std::string& getMatricule() const { return matricule; }
    double getIndiceSalarial() const { return indiceSalarial; }
};