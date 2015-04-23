#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente{
    char nome[MAX_STRLEN];
    char cognome[MAX_STRLEN];
    unsigned int eta;
    unsigned int classe;
    char sezione[MAX_STRLEN];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    int i;
    studente ciao[N];
    FILE *pfile;
    
    // Codice per l'inserimento, da parte dell'utente, dei dati e del salvataggio 
    // nel file
    pfile=fopen("Elenco.dat","wb");
    
   
    for(i=0;i<N;i++)
    {
        printf("Inserisci il nome:\n ");
        scanf("%s", &ciao[i].nome);
        printf("Inserisci il cognome:\n ");
        scanf("%s", ciao[i].cognome);
        printf("Inserisci l'eta':\n ");
        scanf("%d", &ciao[i].eta);
        printf("Inserisci la classe:\n ");
        scanf("%d", &ciao[i].classe);
        printf("Inserisci la sezione:\n ");
        scanf("%s", ciao[i].sezione);
    
    
            fwrite(&ciao, sizeof(studente), 1, pfile);
        }
        
        fclose(pfile);
        
        pfile=fopen("elenco.dat","rb");
        
        for(i=0;i<N;i++){
            fread(&ciao, sizeof(studente), 1, pfile);
               printf("%s; %s; %d; %d; %s\n",ciao[i].nome,ciao[i].cognome,ciao[i].eta,ciao[i].classe,ciao[i].sezione);        
        }
        
        fclose(pfile);
    
    return (EXIT_SUCCESS);
}