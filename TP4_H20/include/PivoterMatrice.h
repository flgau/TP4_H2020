/*
 * Titre : PivoterMatrice.h - Travail Pratique #4 - Programmation Orient�e Objet
 * Date : 27 F�vrier 2020
 * Auteur : Nabil Dabouz
 */

#ifndef PIVOTER_MATRICE_H
#define PIVOTER_MATRICE_H

#include "def.h"


template <class M> class PivoterMatrice {
public:
  // Constructeurs
  PivoterMatrice();
  PivoterMatrice(M *matrice);
  // Destructeur
  ~PivoterMatrice() = default;  
  void pivoterMatrice(Direction direction);

private:
  Coordonnees changerCoordonneesCentreMatrice(Coordonnees coords) const;
  Coordonnees recupererCoordonnees(Coordonnees coords) const;
  M *matrice_;
};

/**
 * @brief constructeur par défaut de la classe
 */
template <class M> inline PivoterMatrice<M>::PivoterMatrice()
  :matrice_(nullptr)
 {
    matrice_=new M;
 }
/**
 * @brief constructeur par paramètre de la classe
 */
template <class M>
inline PivoterMatrice<M>::PivoterMatrice(M *matrice) : matrice_(matrice) {}
/**
 * @brief trouver les coordonnées du point par rapport au centre de la matrice
 * @param coords les coordonnées du point originales
 */
template <class M>
inline Coordonnees
PivoterMatrice<M>::changerCoordonneesCentreMatrice(Coordonnees coords) const {
  int posX =(-1*(matrice_->getWidth()/2))+coords.x;
  int posY =(-1*(matrice_->getHeight()/2))+coords.y;

  return {posX,posY};
}
/**
 * @brief revenir au système précédent, trouver les coordonnées du point par
 * rapport au premier élément de la matrice
 * @param coords les coordonnées du point originales
 */
template <class M> inline 
Coordonnees PivoterMatrice<M>::recupererCoordonnees(Coordonnees coords) const {
  int posX =(matrice_->getWidth()/2)+coords.x;
  int posY =(matrice_->getHeight()/2)+coords.y;

  return {posX,posY};
}

//! Méthode qui pivote la matrice d'un quart de tour a droite ou a gauche.
//! /param direction   la direction dans laquelle faire pivoter la matrice.
template <class M> inline
void PivoterMatrice<M>::pivoterMatrice(Direction direction){
  std::unique_ptr<M> clone =matrice_->clone();
  Coordonnees tampon;
  int inverse=-1;
  for(int i=0;i<matrice_->getHeight();i++){
    for(int j=0; j< matrice_->getWidth();j++){
        Coordonnees coordoTempo = { j, i };
        Coordonnees coordo = PivoterMatrice::changerCoordonneesCentreMatrice(coordoTempo);
      if(direction==Direction::Right){
        tampon=coordo;
        coordo.x= inverse*tampon.y;
        coordo.y=tampon.x;
      }
      else if(direction==Direction::Left) {
         tampon=coordo;
        coordo.x= tampon.y;
        coordo.y=inverse*tampon.x;
     }
     coordo=recupererCoordonnees(coordo);
     matrice_->ajouterElement(clone->operator()(i,j),coordo.y,coordo.x);
    }
  }
  
}

#endif
