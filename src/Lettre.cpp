#include "Lettre.h"
#include <string>
#include <iostream>

using namespace std;

Lettre::Lettre(char x,int pos,Color coul=blanc):val(x),Position(pos),Couleur(coul)
{


}

Lettre::~Lettre()
{

}

int Lettre ::getPosition()const
{
    return Position;
}

Color Lettre ::getCouleur()const
{
    return Couleur;
}

void Lettre ::setPosition(int a)
{
    Position=a;
}

void Lettre ::setCouleur(Color b)
{
    Couleur=b;
}

void Lettre ::Comparer(Lettre y)
{
    if  ((Position==y.Position)&&((toupper(val))==(toupper(y.val)))) {Couleur=rouge;}
    if  ((toupper(val)==toupper(y.val))&&(Position!=y.Position)) {Couleur=jaune;}
    if  ((toupper(val)!=toupper(y.val))&&(Couleur!=jaune)) {Couleur=blanc;}
}
