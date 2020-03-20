#include "Pixel.h"
#include <cmath>
/**
 * @brief constructeur par défaut de la classe
 */
Pixel::Pixel() : rouge_(0), vert_(0), bleu_(0) {}
/**
 * @brief constructeur par paramètres de la classe
 * @param rouge, l'élément R du pixel, entre 0 -> 255
 * @param vert, l'élément G du pixel, entre 0 -> 255
 * @param bleu, l'élément B du pixel, entre 0 -> 255
 */
Pixel::Pixel(uint8_t rouge, uint8_t vert, uint8_t bleu)
    : rouge_(rouge), vert_(vert), bleu_(bleu) {}

//!Methode qui copie les éléments du paramètre pixel dans l’objet.
//! /param Pixel    le pixel a copier.
void Pixel::operator=(const Pixel &pixel) {
    rouge_ = pixel.rouge_;
    vert_ = pixel.vert_;
    bleu_ = pixel.bleu_;
}

//!Methode qui affecte l'attribut rouge.
//! /param rouge    la couleur a affecter.
void Pixel::setRouge(int rouge) {
  // TO DO

    //int five_divided_by_x = (x != 0 ? 5 / x : 0);
    int test_si_rouge_trop_grand = (rouge > 255 ? rouge = 255 : rouge = rouge);
    int test_si_rouge_trop_petit = (rouge < 0 ? rouge = 0 : rouge = rouge);
    rouge_ = rouge;
    /* mettons rouge = 300
    apres la premiere "fonction" rouge = 255
    apres la deuxieme 'fonction" rouge qui valait 255 vaut encore 255
    finalement rouge_ = rouge // rouge =255
    */

    /*
    mettons rouge = -10
    apres la premiere fonction rouge vaut -10
    apres la deuxieme fonction rouge vaut 0
    finalement rouge_=rouge //rouge = 0

    */


    
}

//!Methode qui affecte l'attribut vert.
//! /param vert    la couleur a affecter.
void Pixel::setVert(int vert) {
  // TO DO
    int test_si_vert_trop_grand = (vert > 255 ? vert = 255 : vert = vert);
    int test_si_vert_trop_petit = (vert < 0 ? vert = 0 : vert = vert);
    vert_ = vert;


}

//!Methode qui affecte l'attribut bleu.
//! /param vert    la couleur a affecter.
void Pixel::setBleu(int bleu) {
  int test_si_bleu_trop_grand = (bleu > 255 ? bleu = 255 : bleu = bleu);
  int test_si_bleu_trop_petit = (bleu < 0 ? bleu = 0 : bleu = bleu);
  bleu_ = bleu;

}
/**
 * @brief retourn l'attribut rouge_ du pixel
 * @return rouge_ du type uint8_t
 */
uint8_t Pixel::getRouge() const 
{ 
    return rouge_;
}

/**
 * @brief retourn l'attribut vert_ du pixel
 * @return vert_ du type uint8_t
 */
uint8_t Pixel::getVert() const 
{ 
    return vert_;
}
/**
 * @brief retourn l'attribut bleu_ du pixel
 * @return bleu_ du type uint8_t
 */
uint8_t Pixel::getBleu() const
{ 
    return bleu_;
}

//!Methode qui affiche tous les attributs du pixel.
//! /param os    stream dans lequel afficher.
//! /param pixel  le pixel a afficher.
std::ostream &operator<<(std::ostream &os, Pixel pixel) {
  // TO DO
    
    os << "#" << std::hex << std::uppercase << std::setw(2)
        << std::setfill('0') << int(pixel.getRouge()) << " " << std::setw(2)
        << std::setfill('0') << int(pixel.getBleu()) << " " << std::setw(2)
        << std::setfill('0') << int(pixel.getVert());
    return os;
}

//!Methode qui initialise tous les attributs du pixel.
//! /param is    stream a lire.
//! /param pixel  le pixel a initialiser.
std::istream& operator>>(std::istream& is, Pixel& pixel) {
    // TO DO
    
    int rouge, bleu, vert;
    is >> rouge >> bleu >> vert;
    pixel.setRouge(rouge);
    pixel.setBleu(bleu);
    pixel.setVert(vert);
    return is; 

}