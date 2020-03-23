/*
 * Titre : Matrice.h - Travail Pratique #4 - Programmation Orient�e Objet
 * Date : 27 F�vrier 2020
 * Auteur : Nabil Dabouz
 */

#ifndef MATRICE_H
#define MATRICE_H

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include <algorithm>

template <typename T> class Matrice {

public:
  Matrice();
  // Destructeur
  ~Matrice() = default;
  T operator()(const size_t &posY, const size_t &posX) const;
  // Lecture du fichier
  bool chargerDepuisFichier(const std::string &nomFichier);
  bool lireElement(const std::string &elementFichier, const size_t &posY,
                   const size_t &posX);
  // Remplir un matrice
  bool ajouterElement(T element, const size_t &posY, const size_t &posX);
  // Faire une copie
  std::unique_ptr<Matrice<T>> clone() const;
  // Setters
  void setHeight(size_t height);
  void setWidth(size_t width);
  // Getters
  size_t getHeight() const;
  size_t getWidth() const;

private:
  std::vector<std::vector<T>> elements_;
  size_t height_;
  size_t width_;
};

namespace {
static constexpr int CAPACITE_MATRICE = 100;
}

/**
 * @brief constructeur par défaut de la classe
 */
template <typename T> inline Matrice<T>::Matrice()
    :height_(0)
    ,width_(0)
	,elements_(CAPACITE_MATRICE,std::vector<T>(CAPACITE_MATRICE))
{
}
/**
 * @brief retourne le nombre de lignes de la matrice
 * @return l'attribut height_ de l'objet
 */ 
template <typename T> inline size_t Matrice<T>::getHeight() const {
  return height_;
}
/**
 * @brief retourne le nombre de colonnes de la matrice
 * @return l'attribut width_ de l'objet
 */
template <typename T> inline size_t Matrice<T>::getWidth() const {
  return width_;
}

//!Methode qui retourne l’élément se trouvant à la ligne posY et la colonne posX du tableau elements_.
//! /param posY    la position sur l'axe des ordonées .
//! /param posX    le position sur l'axe des abscisses.
//! /return  l'élément a la coordonnée.
template<typename T>
inline T Matrice<T>::operator()(const size_t& posY, const size_t& posX) const
{
    if (posY > height_ || posX > width_)
    {
        return T();
    }
    else {
        return elements_[posY][posX];

    }

}

//!Methode qui ajoute l’élément passé en paramètre dans la position correspondante.
//! /param posY    la position sur l'axe des ordonées .
//! /param posX    la position sur l'axe des abscisses.
//! /return  un booléen pour indiqué la réussite ou échec de l'operation.
template <typename T> bool Matrice<T>::ajouterElement(T element, const size_t& posY, const size_t& posX) {

    if (posY > height_ || posX > width_) {
        return false;
    }
  
    elements_.resize(CAPACITE_MATRICE);

    for (size_t i = 0; i < elements_.size(); ++i)
    {
        elements_[i].resize(CAPACITE_MATRICE);
    }
    elements_[posY][posX] = element;
    return true;

}

//!Methode qui retourne un pointeur vers une copie de la matrice.
//! /return  la copie de la matrice.
template<typename T>
inline std::unique_ptr<Matrice<T>> Matrice<T>::clone() const
{
    return std::make_unique<Matrice<T>>(*this);
}

//!Methode qui affecte l'attribut height.
//! /param height    la hauteur à affecter.
template<typename T>
inline void Matrice<T>::setHeight(size_t height)
{
    (height > CAPACITE_MATRICE  ? height_ = CAPACITE_MATRICE : height_ = height);

}
//!Methode qui affecte l'attribut width.
//! /param width    la largeur à affecter.
template<typename T>
inline void Matrice<T>::setWidth(size_t width)
{ 
    width_ = width;
}

//!Methode qui charge la matrice à partir du fichier passé en paramètre.
//! /param nomFichier    le nom du fichier é lire.
//! \return bool représentant si le chargement a été un succès.
template<typename T>
inline bool Matrice<T>::chargerDepuisFichier(const std::string& nomFichier)
{
    std::ifstream fichierLecture(nomFichier);
    if (fichierLecture) {
        elements_.clear();
        std::string ligne;
        
        
        width_ = CAPACITE_MATRICE;
        height_ = CAPACITE_MATRICE;

       ;
        int largeur = 0;
        int nbLignes = 0;
        while (std::getline(fichierLecture, ligne))
        {    
            //ligne.erase(std::remove(ligne.begin(),ligne.end(),'\r'),ligne.end());
            if (ligne !="L")
            {
                lireElement(ligne, nbLignes - 1, largeur++);                
            }
            else
            {
                nbLignes++;
                largeur = 0;
            }
        }

        width_ = largeur;
        height_ = nbLignes;
        return true;
    }
    else {
        return false;
    }      
}


//! Méthode qui ajoute un element à partir d'un string comportant ses attributs 
//! \param elementFichier       le string contenant les attributs de élément
//! /param posY    la position sur l'axe des ordonées .
//! /param posX    la position sur l'axe des abscisses.
//! \return bool représentant si l'opération est un succès
template <typename T> bool Matrice<T>::lireElement(const std::string& elementFichier, const size_t& posY,
    const size_t& posX) 
{
    T element;
    std::istringstream stringStream = static_cast<std::istringstream>(elementFichier);

    if (stringStream>>element)
    {
        
        return Matrice::ajouterElement(element, posY, posX);

    }
    return false;  

}



#endif











