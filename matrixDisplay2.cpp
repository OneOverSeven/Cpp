#include <iostream>
using namespace std;
int main()
{
	int int_nombreDeLigne = 0;
	int int_nombreDeColonne = 0;


	cout << "Bonjour" << endl;
	cout << "Je suis un programme qui vous donne la possibilite d'afficher une matrice." << endl;
	cout << "Veuillez entrer le nombre de ligne de votre matrice s'il vous plait." << endl;
	cin >> int_nombreDeLigne;
	cout << "Veuillez entrer le nombre de colonne de votre matrice s'il vous plait." << endl;
	cin >> int_nombreDeColonne;
	cout << "Conversion du nombre de ligne et de colonne en valeur constante..." << endl;
	cout << "Creation de votre matrice en cours ..." << endl;
	const int const_int_nombreDeLigne = int_nombreDeLigne;
	const int const_int_nombreDeColonne = int_nombreDeColonne;
	int monBeauTableau[int_nombreDeLigne][int_nombreDeColonne];
	cout << "Encodage des valeurs de la matrice." << endl;
	
	for (int int_compteurLigne = 0; int_compteurLigne < int_nombreDeLigne; int_compteurLigne++)
	{
		for (int int_compteurColonne = 0; int_compteurColonne < int_nombreDeColonne; int_compteurColonne++)
		{
			int int_valeurTemporaire = 0;
			cout << "Veuillez entrer la valeur [" << int_compteurLigne + 1 << 
				", "<< int_compteurColonne + 1 << "] de la matrice" << endl;

//J'ajoute 1 à int_compteurLigne et à int_compteurColonne car je suis obligé de démarrer 
//le compteur à 0 étant donné que j'utillise ces valeurs pour désigner les valeurs des indices
//de mon tableau et que les valeurs des indices d'un tableau démarre à 0 !!!!
			
			cin >> int_valeurTemporaire;
			monBeauTableau[int_compteurLigne][int_compteurColonne] = int_valeurTemporaire;

		}
	}
	cout << "Merci, vous avez entré toutes les valeurs. Nous allons afficher votre matrice."<<endl;



	for (int int_compteurLigne = 0; int_compteurLigne < int_nombreDeLigne; int_compteurLigne++)
	{
		for (int int_compteurColonne = 0; int_compteurColonne < int_nombreDeColonne; int_compteurColonne++)
		{
			cout << monBeauTableau[int_compteurLigne][int_compteurColonne] << "\t";
			if ((int_compteurColonne+1) % 3 == 0)
			 {
			 	cout << "\n";
			 } 
		}
        
	}
//cout << endl;
return 0;
}
