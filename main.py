class Objet:
    def __init__(self, type_objet):
        self.type = type_objet
        self.nombre_de_jours_reserver = 0
        self.is_disponible = True

    def reserver(self, jours):
        if not self.is_disponible:
            print(f"❌ Erreur : \"{self.type}\" est déjà réservé.")
            return False
        elif jours <= 0 or not isinstance(jours, int):
            print("❌ Erreur : Le nombre de jours doit être un nombre valide supérieur à zéro.")
            return False
        else:
            self.nombre_de_jours_reserver = jours
            self.is_disponible = False
            print(f"✅ \"{self.type}\" a été réservé pour {jours} jours.")
            return True

    def afficher_etat(self):
        print(f"\n📦 État de \"{self.type}\" :")
        print(f"   - Disponible : {'Oui ✅' if self.is_disponible else 'Non ❌'}")
        print(f"   - Réservé pour : {self.nombre_de_jours_reserver} jour(s)")

class Auto(Objet):
    def __init__(self):
        super().__init__("Auto")

class Assiette(Objet):
    def __init__(self):
        super().__init__("Assiette")

def demander_quel_objet():
    print("\nQuel objet souhaitez-vous réserver ?")
    print("1 - Auto")
    print("2 - Assiette")
    choix = input("Entrez le numéro de votre choix : ").strip()
    return choix

def demander_jours(objet):
    try:
        jours = int(input(f"Combien de jours souhaitez-vous réserver \"{objet.type}\" ? : "))
        success = objet.reserver(jours)
        if success:
            objet.afficher_etat()
    except ValueError:
        print("❌ Erreur : Veuillez entrer un nombre entier valide.")

def main():
    voiture = Auto()
    assiette = Assiette()

    choix = demander_quel_objet()

    if choix == "1":
        demander_jours(voiture)
    elif choix == "2":
        demander_jours(assiette)
    else:
        print("❌ Choix invalide.")

if __name__ == "__main__":
    main()