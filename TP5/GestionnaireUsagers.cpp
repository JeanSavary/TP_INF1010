/********************************************
 * Titre: Travail pratique #5 - GestionnaireUsagers.cpp
 * Date: 9 mars 2018
 * Auteurs: SAVARY Jean, PAGE Nicolas
 *******************************************/
#include "GestionnaireGenerique.h"
#include "GestionnaireUsagers.h"
#include "Usager.h"
#include "Client.h"
#include "ProduitAuxEncheres.h"


double GestionnaireUsagers::obtenirChiffreAffaires() const
{
    double chiffreAffaires = 0.0;
    for (Usager* usager:conteneur_) {
        chiffreAffaires+= usager->obtenirTotalAPayer();
    }
    return chiffreAffaires;
}

void GestionnaireUsagers::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
    
    if (produit->obtenirPrix() < montant)
        produit->mettreAJourEnchere(client, montant);
    
}
void GestionnaireUsagers::reinitialiser()
{
    
    for (set<Usager*>::iterator it = conteneur_.begin();it!=conteneur_.end();it++) {
        (*it)->reinitialiser();
    }
    
}
void GestionnaireUsagers::afficherLesProfils() const
{
    cout << "PROFILS" << endl;
    for (Usager* usager:conteneur_) {
        usager->afficher();
    }
    cout << endl;
}

