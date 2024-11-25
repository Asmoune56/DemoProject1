#include <stdio.h>
#include <string.h>

typedef struct {

    int jour;
    int mois;
    int anee;
}date;
 typedef struct{

    char titre[20];
    char description[200];
    char priorite [10];
    date dt;
}tach;
// pour stokere les nouville tache

 tach table[150];
 int conteur = 0;


 void Ajouter(){

     if ( conteur >= 150){
         printf(" Aucune autre tache ne peut etre ajoutee. ");
         return;
     }

     tach nouville_tache;

     printf("_____nouville_tache_____\n");


     printf("\n entrer le titre : \n");
     scanf(" %[^\n]",nouville_tache.titre);

     printf("entrer le description : \n");
     scanf(" %[^\n]",nouville_tache.description);

     printf("entrer la pririorite (high/low) : \n");
     scanf(" %[^\n]",nouville_tache.priorite);

     printf("entrer le jour : \n");
     scanf("%d",&nouville_tache.dt.jour);

     printf("entrer le mois : \n");
     scanf("%d",&nouville_tache.dt.mois);

     printf("entrer l anee : \n");
     scanf("%d",&nouville_tache.dt.anee);

     table[conteur]= nouville_tache;
     conteur++;
 }

 void Afficher(){

     if (conteur == 0){
         printf("Il ny a aucune tache a afficher.");
         return;
     }
     printf("\nListe de choses a faire:\n");

     for (int i= 0; i< conteur;i++){

     printf(" Tache : %d\n",i + 1);
     printf(" titre : %s\n",table[i].titre);
     printf(" description : %s\n",table[i].description);
     printf(" pririorite : %s\n",table[i].priorite);

     printf("date d_echeance : %02d-%02d-%04d \n",table[i].dt.jour,table[i].dt.mois,table[i].dt.anee);
     }
 }
void ModifierTache (){

    if (conteur==0){
        printf("Il ny a aucune tache a modifier.");
        return;
    }
    int id=0;
    printf("Saisissez le numero de tache que vous souhaitez modifier de (1 a %d :",conteur);
    scanf("%d",&id);

    if (id<1 || id>conteur){

        printf("Le numero de tache n est pas valide.");
        return;
    }
    //المهمة المختارة

    tach *selectedTache= &table[id -1];

// تعديل التفاصيل
    printf(" nouvelle titre :");
    scanf("%s",selectedTache->titre);

    printf(" nouvelle description :");
    scanf("%s",selectedTache->description);

    printf(" nouvelle pririorite :");
    scanf("%s",selectedTache->priorite);

    printf(" nouvelle jour :");
    scanf("%d",&selectedTache->dt.jour);
    printf("nouvelle mois :");
    scanf("%d",&selectedTache->dt.mois);
    printf(" nouvelle anee :");
    scanf("%d",&selectedTache->dt.anee);

    printf("La tache a ete modifiee avec succes.");
}
void supprimerTache(){

    if (conteur == 0){

        printf("Il n y a aucune tache a supprimer.\n");
        return;
    }
    int idi;

    printf("Entrez le numero de la tache que vous souhaitez supprimer de( 1 a %d) : \n",conteur);
    scanf("%d",&idi);

     if( idi< 1 || idi> conteur){

         printf("Le numéro de tache n est pas valide.\n");
         return;
     }
         // نقل المهام لتغطية المهمة المحذوفة
         for( int i = i-1; i < conteur - 1 ; i++){

             table[i] = table[i + 1];
         }
         conteur--;
}

void FiltrerTaches(){

    if (conteur == 0){

        printf("Il n y a aucune tache a afficher.\n");
        return;
    }

    char pRecherchee[10];
    printf("Entrez la priorite selon laquelle vous souhaitez filtrer les taches (gigh/low).:");
    scanf("%s",pRecherchee);

    printf("_____________ Taches prioritaires: %s _____________\n",pRecherchee);

    // علم للتحقق من وجود مهام مطابقة

    int found = 0;

    for (int i = 0; i< conteur; i++){

        if (strcmp(table[i].priorite, pRecherchee) == 0){

                // إذا تطابقت الأولويات، اعرض المهمة

          printf("Tache n° %d :\n", i + 1);
          printf("titre: %s\n", table[i].titre);
          printf("description: %s\n", table[i].description);
          printf("date d_echeance %02d _%02d _%04d \n", table[i].dt.jour,table[i].dt.mois,table[i].dt.anee);

          printf("----------------------\n");
            found = 1;

        }
    }

    if (!found) {
        printf("Il n y a pas de taches prioritaires: %s.\n", pRecherchee);
    }
}

int main(){
    int choix;
    do {
        printf(" \n \n_____________ les taches _____________ \n");
        printf(" _1_  Ajouter.\n");
        printf(" _2_  Afficher.\n");
        printf(" _3_  ModifierTache.\n");
        printf(" _4_  supprimerTache.\n");
        printf(" _5_  FiltrerTaches.\n");
        printf(" _6_  sortie.\n");
        scanf("%d",&choix);
    switch (choix){

        case 1:
         Ajouter();
         break;

         case 2:
         Afficher();
         break;

         case 3:
          ModifierTache();
         break;

         case 4:
         supprimerTache();
         break;

         case 5:
         FiltrerTaches();
         break;

         case 6:
         printf("Quittez le programme...\n");
         break;

         default:

         printf("Mauvais choix ! Essayer a nouveau.\n");

    }


    }  while( choix != 6);


    return 0;
}
