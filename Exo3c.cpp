#include <iostream>
#include <stdexcept>

#include "Employe.h"
#include "Responsable.h"
#include "Commercial.h"
#include "Personnel.h"

int main() {

    Employe alice("Alice Martin", "EMP001", 1200);
    Employe bob("Bob Dupont", "EMP002", 1500);

    alice.afficherCaracteristiques();
    bob.afficherCaracteristiques();

    std::cout << std::endl;

    Employe::augmentationGenerale(2.5);

    alice.afficherCaracteristiques();

    std::cout << std::endl;

    Responsable directrice("Claire Lefèvre", "EMP003", 2200);
    Responsable responsableDev("David Bernard", "EMP004", 1800);

    directrice.ajouterSubordonne(&responsableDev);
    directrice.ajouterSubordonne(&alice);

    responsableDev.ajouterSubordonne(&bob);

    directrice.afficherSubordonnesDirects();

    std::cout << std::endl;

    directrice.afficherSubordonnesIndirects();

    std::cout << std::endl;

    Commercial carol("Carol Petit", "EMP005", 1000, 40000);

    carol.afficherCaracteristiques();

    carol.mettreAJourVentes(60000);

    carol.afficherCaracteristiques();

    std::cout << std::endl;

    Personnel personnel;

    personnel.ajouterEmploye(&alice);
    personnel.ajouterEmploye(&bob);
    personnel.ajouterEmploye(&directrice);
    personnel.ajouterEmploye(&responsableDev);
    personnel.ajouterEmploye(&carol);

    personnel.afficherToutLePersonnel();

    try {
        Employe inconnu("Inconnu", "EMP001", 900);
        personnel.ajouterEmploye(&inconnu);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Erreur attendue : "
            << e.what() << std::endl;
    }

    return 0;
}