//Simulation et exploration d un automate cellulaire etendu (Jeu de la Vie avec compteur de vie et seuil de survie)
#include <stdio.h>

void createArray(int n, int array[n][n]) // Fonction pour creer un tableau
{
    int i;
    int j;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            array[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%1d", &array[i][j]);
        }
    }
}

void showArray(int n, int array[n][n]) // Fonction pour afficher un tableau de taille n x n
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void copyArray(int n, int array[n][n], int cparray[n][n]) // Fonction pour copier un tableau
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cparray[i][j] = array[i][j];
        }
    }
}

void sommeVoisin(int n, int seuil, int array[n][n], int ArrayVie[n][n]) // Fonction pour calculer la somme des voisins d'une cellule
{
    int i;
    int j;
    int k;
    int l;
    int somme;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            somme = 0;
            for (k = i - 1; k <= i + 1; k++)
            {
                for (l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < n && l >= 0 && l < n)
                    {
                        if (k != i || l !=j)
                        {
                            somme += array[k][l];
                        }
                    }
                    
                } 
            }

            if (somme > seuil)
            {
                ArrayVie[i][j] = 0; // La cellule meurt
            }
            else
            {
                if (somme == seuil && array[i][j] != 0)
                {
                    if (array[i][j] >= 9)
                    {
                        ArrayVie[i][j] = array[i][j] - 1; //Cela permet de ne pas depasser 9
                    }
                    else
                    {
                        ArrayVie[i][j] = array[i][j] + 1;
                    }
                }
                else
                {
                    ArrayVie[i][j] = array[i][j];
                }
            }
        }
    }
}

int main()
{
    int taille = 0;    //Taille du plateau de jeu
    int seuil = 0;     //Seuil de vie ou de mort
    int iteration = 0; // Nombre d'iterations
    int tour = 0;      // Tour actuelle

    printf("Taille du plateau de jeu : ");
    scanf("%d", &taille);
    printf("%d\n", taille);
    
    printf("Seuil de vie : ");
    scanf("%d", &seuil);
    printf("%d\n", seuil);

    printf("Nombre d'iterations : ");
    scanf("%d", &iteration);
    printf("%d\n", iteration);


    int plateau[taille][taille];       // Plateau de jeu
    int jeu_de_la_vie[taille][taille]; // Plateau pour les calculs


    createArray(taille, plateau);   // Creation du plateau de jeu via l'entree standard
    showArray(taille, plateau);     // Affichage du plateau de jeu

    for (tour = 0; tour < iteration; tour++)
    {
        printf("\nTour %d :\n", tour + 1);                 
        sommeVoisin(taille, seuil, plateau, jeu_de_la_vie);// Calcul de la somme des voisins
        showArray(taille, jeu_de_la_vie);                  // Affichage du plateau de jeu/
        copyArray(taille, jeu_de_la_vie, plateau);         // Recopie du plateau pour le tour d'apres
    }

    return 0;
}