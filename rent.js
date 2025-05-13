const readline = require('readline');

class Objet {
    constructor(type) {
        this.type = type;
        this.nombreDeJourReserver = 0;
        this.isDisponible = true;
    }

    reserver(jours) {
        if (!this.isDisponible) {
            console.log(`❌ Erreur : "${this.type}" est déjà réservé.`);
            return false;
        } else if (jours <= 0 || isNaN(jours)) {
            console.log("❌ Erreur : Le nombre de jours doit être un nombre valide supérieur à zéro.");
            return false;
        } else {
            this.nombreDeJourReserver = jours;
            this.isDisponible = false;
            console.log(`✅  "${this.type}" a été réservé pour ${jours} jours.`);
            return true;
        }
    }

    afficherEtat() {
        console.log(`\n📦 État de "${this.type}" :`);
        console.log(`   - Disponible : ${this.isDisponible ? "Oui ✅" : "Non ❌"}`);
        console.log(`   - Réservé pour : ${this.nombreDeJourReserver} jour(s)`);
    }
}

class Auto extends Objet {
    constructor() {
        super("Auto");
    }
}

class Assiette extends Objet {
    constructor() {
        super("Assiette");
    }
}

function demanderQuelObjet(rl) {
    return new Promise((resolve) => {
        console.log("\nQuel objet souhaitez-vous réserver ?");
        console.log("1 - Auto");
        console.log("2 - Assiette");
        rl.question("Entrez le numéro de votre choix : ", (choix) => {
            resolve(choix.trim());
        });
    });
}

function demanderJours(objet, rl) {
    return new Promise((resolve) => {
        rl.question(`Combien de jours souhaitez-vous réserver "${objet.type}" ? : `, (input) => {
            const jours = parseInt(input);
            const success = objet.reserver(jours);

            if (success) {
                objet.afficherEtat();
            }

            resolve();
        });
    });
}

async function main() {
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    const voiture = new Auto();
    const assiette = new Assiette();

    const choix = await demanderQuelObjet(rl);

    if (choix === "1") {
        await demanderJours(voiture, rl);
    } else if (choix === "2") {
        await demanderJours(assiette, rl);
    } else {
        console.log("❌ Choix invalide.");
    }

    rl.close();
}

main();
