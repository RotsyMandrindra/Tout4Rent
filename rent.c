#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char type[50];
    int nombreDeJourReserver;
    bool isDisponible;
} Objet;

typedef struct {
    Objet base;
} Auto;

typedef struct {
    Objet base;
} Assiette;

void Objet_init(Objet* obj, const char* type) {
    strncpy(obj->type, type, sizeof(obj->type) - 1);
    obj->type[sizeof(obj->type) - 1] = '\0'; 
    obj->nombreDeJourReserver = 0;
    obj->isDisponible = true;
}

bool Objet_reserver(Objet* obj, int jours) {
    if (!obj->isDisponible) {
        printf("❌ Erreur : \"%s\" est déjà réservé.\n", obj->type);
        return false;
    } else if (jours <= 0) {
        printf("❌ Erreur : Le nombre de jours doit être un nombre valide supérieur à zéro.\n");
        return false;
    } else {
        obj->nombreDeJourReserver = jours;
        obj->isDisponible = false;
        printf("✅  \"%s\" a été réservé pour %d jours.\n", obj->type, jours);
        return true;
    }
}

void Objet_afficherEtat(Objet* obj) {
    printf("\n📦 État de \"%s\" :\n", obj->type);
    printf("   - Disponible : %s\n", obj->isDisponible ? "Oui ✅" : "Non ❌");
    printf("   - Réservé pour : %d jour(s)\n", obj->nombreDeJourReserver);
}

void Auto_init(Auto* voiture) {
    Objet_init(&voiture->base, "Auto");
}

void Assiette_init(Assiette* assiette) {
    Objet_init(&assiette->base, "Assiette");
}

int main() {
    Auto voiture;
    Assiette assiette;
    int choix, jours;

    Auto_init(&voiture);
    Assiette_init(&assiette);

    printf("\nQuel objet souhaitez-vous réserver ?\n");
    printf("1 - Auto\n");
    printf("2 - Assiette\n");
    printf("Entrez le numéro de votre choix : ");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Combien de jours souhaitez-vous réserver \"Auto\" ? : ");
        scanf("%d", &jours);
        if (Objet_reserver(&voiture.base, jours)) {
            Objet_afficherEtat(&voiture.base);
        }
    } else if (choix == 2) {
        printf("Combien de jours souhaitez-vous réserver \"Assiette\" ? : ");
        scanf("%d", &jours);
        if (Objet_reserver(&assiette.base, jours)) {
            Objet_afficherEtat(&assiette.base);
        }
    } else {
        printf("❌ Choix invalide.\n");
    }

    return 0;
}
