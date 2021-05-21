#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include "Joueur.h"
#include "Lettre.h"
#include "Tentative.h"
#include <vector>
#include<algorithm>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;

string setmotadeviner(){// genere un mot aleatoire du fichier
    srand(time(NULL));
    int i=rand()%50+1;
ifstream f("fichier.txt");
string m;
for (int j=1; j<i; j++ ) {
	getline(f,m);

}
return m;
}

int main (){
    vector<string> v;//initialisation d'un vecteur pour l'affichage
    v.push_back("R");
    v.push_back("J");
    v.push_back("B");

    string A;
	string nom ,mot;
	cout<<"    *****                  BIENVENUE AU JEU MOTUS                       *****"<<endl;
	cout<<"\n";
	cout <<"                               Veuillez entrer votre Nom :    "<<endl;
	cin >> nom ;
	Joueur l(nom);
	cout<<"\n";
	cout<<"    *****              Le jeu du Motus consiste a retrouver             *****"<<endl;
    cout<<"    *****          un mot de 7 lettres au bout de 7 tentatives         *****"<<endl;
    cout<<"    ***** on associe la lettre R aux lettres presentes et bien placees *****"<<endl;
    cout<<"    ***** on associe la lettre J aux lettres presentes et mal placees  *****"<<endl;
    cout<<"    *****         on associe la lettre B aux lettres inexistantes      *****"<<endl;
	cout<<"    *****                  Pour lancer le jeu tapez 1                  ***** "<<endl;
    bool controle=false;
    do{
	cin>> A ;

	if((A!="1")){
        cout<<"Verifier votre choix !!"<<endl;   //entree non valide
	}
	else{controle=true;}
	}while (controle==false);
	string x;


	do {

     system("cls");
    cout<<"             C'EST PARTI !               "<<endl;
    cout<<"\n";
	string motadeviner;
	string reponse;
	string ch="";
	motadeviner=setmotadeviner();
	int nbessai=0;bool test=false;
	do{
    cout<<"\n";
    cout<<"     Le mot commence par la lettre  "<<motadeviner[0]<<endl;
     if ((nbessai+1)>3){
        cout<<"\n";
        cout<<"Voulez vous utiliser un Jocker lors de votre prochain essai? "<<endl;
        cout<<"Si oui , tapez 1 sinon tapez 0"<<endl;
        bool r=false;
        do{
        cin>>reponse;
        if ((reponse!="1")&&(reponse!="0")){ cout<<"Verifier votre choix !!"<<endl;}   //entree non valide
        else {r=true;}
        }while (r==false);
        }




	cout<<"      Saisir votre essai numero :  "<< nbessai+1 <<endl;
	cout<<x<<endl;
	x.clear();

		cin>>mot;
		for (int i=0; i<7; i++) { if ((toupper(mot[i]))!=(toupper(motadeviner[i]))) { test= false; break;}
		else {test=true;}
		        }
		if (test==true){break;}
    Tentative t(mot);
    if (t.controlesaisie(motadeviner))
        { nbessai++;//essai validé

     vector<int> red; //recherche des lettres bien placées
     for (int i=0;i<7;i++){
            Lettre j(mot[i],i,blanc);
      for (int k=0;k<7;k++){
            Lettre m(motadeviner[k],k,blanc);
            j.Comparer(m);
            if (j.getCouleur()==rouge) {red.push_back(k);break;}
     }
     }
     for (int i=0;i<7;i++)
{
    if ((std::count(red.begin(), red.end(), i))) {x=x+motadeviner[i];} //affichage des lettres bien placees
    else {x=x+"_";}
}
     vector<int> yellow;//recherche des lettres mal placées
     yellow.clear();
    vector<char> yellowstr;
     yellowstr.clear();
	for (int i=0;i<7;i++)
    {   Lettre j(mot[i],i,blanc);
        //calcul de l'occurence de chaque lettre dans le mot a deviner

        for (int k=0;k<7;k++)
        {if ((!(std::count(red.begin(), red.end(), k)))&&
             (!(std::count(yellow.begin(), yellow.end(), k)))&&
            (std::count(yellowstr.begin(), yellowstr.end(), j.getval()))<(std::count(motadeviner.begin(),motadeviner.end(),j.getval()))
             )//k pas dans red
                                {//recherche des jaunes
         Lettre m(motadeviner[k],k,blanc);
         j.Comparer(m);
         if (j.getCouleur()==jaune) {yellow.push_back(k);yellowstr.push_back(j.getval());break;}
                                }


        }//fin parcours lettre mot a deviner

        if ((std::count(red.begin(), red.end(), i))){j.setCouleur(rouge);}
        if ((std::count(yellow.begin(), yellow.end(), i))){j.setCouleur(jaune);}
        yellow.clear();

        cout<<v[j.getCouleur()];


        if ((reponse == "1") &&(v[j.getCouleur()]== "J")){//Le Jocker:affichge de la position correcte d'une lettre mal placée
            char w[5];
            w[0]=j.getval();
            string ch1,ch2;
            char str1[100]="La Lettre ";
            char str2[100]=" est a la position ";
            for (int i=0 ;i<7;i++){
                if (motadeviner[i]==w[0]){
                    string str3= to_string(i+1);
                    char const *str=str3.c_str();
                    ch1=strcat(str1,w);
                    ch2=strcat(str2,str);
                    ch=ch1+ch2;
                break;}
            }
            }


    }
//fin parcours de la lettre lettre
cout<<"\n";
cout<<ch;

    }//fin parcours de l'essai
    else {
            cout<<"        Veuillez essayer de nouveau !!   "<<endl;//controle saisie non validé
    }

	}//fin parcours de tous les essais
	while (nbessai<7);
	if (test) {
            cout <<"      BRAVO !! Vous avez gagne en "<<nbessai +1<<" coups"<<endl;
                 int x;
               x=7-nbessai;
	           l.setScore(x);

	           cout<<"        Votre score est :   "<<x<<endl;        //affichage score
	           l.setRecord(x);
               int b=l.getRecord();
	           cout<<"        Votre record est :  "<<b<<endl;    //affichage record
	}
        else {cout<<"        Dommage, vous avez perdu"<<endl;}

        cout<<"           Voulez vous jouer de nouveau ? "<<endl;
        cout<<"Entrez 0 si vous voulez quitter et 1 si vous voulez rejouer : "<<endl;
        bool f=false;
        do{
        cin>>A;
        if ((A!="1")&&(A!="0")){cout<<"Verifier votre choix !!"<<endl;} //entree invalide
        else{f=true;}
        }while (f==false);

	} while(A=="1") ;

	return 0;

}
