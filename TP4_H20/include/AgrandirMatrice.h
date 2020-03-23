/*
 * Titre : AgrandirMatrice.h - Travail Pratique #4 - Programmation Orient�e
 * Objet Date : 27 F�vrier 2020 Auteur : Nabil Dabouz
 */

#ifndef AGRANDIR_MATRICE_H
#define AGRANDIR_MATRICE_H

#include "def.h"
#include "Matrice.h"

template <class M> class AgrandirMatrice {
public:
  AgrandirMatrice();
  AgrandirMatrice(M *matrice);
  ~AgrandirMatrice() = default;
  Coordonnees trouverLePlusProcheVoisin(const unsigned int &rapport,
                                        size_t posY, size_t posX) const;
  void redimensionnerImage(const unsigned int &rapport);

private:
  M *matrice_;
};

/**
 * @brief constructeur par défaut de la classe
 */
template <class M> AgrandirMatrice<M>::AgrandirMatrice()  
  :matrice_(nullptr)
 {
   matrice_=new M;
 }
/**
 * @brief constructeur par paramètre de la classe
 */
template <class M>
AgrandirMatrice<M>::AgrandirMatrice(M *matrice) : matrice_(matrice) {}
/**
 * @brief trouver le point le plus proche du point (posX, posY) dans la matrice
 * originale
 * @param rapport, le rapport du redimensionnement de l'image
 * @param posX, la colonne du point dans la nouvelle image
 * @param posY, la ligne du point dans la nouvelle image
 * @return coordonnées du point le plus proche
 */
template <class M>
Coordonnees
AgrandirMatrice<M>::trouverLePlusProcheVoisin(const unsigned int &rapport,
                                              size_t posY, size_t posX) const {
    Coordonnees coordo = { int(posX / rapport),int(posY / rapport) };
  
  return coordo;
}

//! Méthode qui redimensionne l'image en utilisant un rapport.
//! /param rapport    le rapport nouvelleImage/imageOriginal.
 template <class M>
 void AgrandirMatrice<M>::redimensionnerImage(const unsigned int& rapport) {
     
     std::unique_ptr<M> clone = matrice_->clone();
     matrice_->setHeight((clone->getHeight()) * rapport);
     matrice_->setWidth((clone->getWidth()) * rapport);
     std::string element;
     for (int i = 0; i < matrice_->getHeight(); i++)
     {
		 for (int j = 0; j < matrice_->getWidth(); j++)
		 {
			 Coordonnees coordoAPlacer = trouverLePlusProcheVoisin(rapport, j, i);

			 matrice_->ajouterElement(clone->operator ()(coordoAPlacer.y, coordoAPlacer.x), j, i);
		 }
     }   
 }



#endif