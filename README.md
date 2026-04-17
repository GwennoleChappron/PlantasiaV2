# PlantasiaV2
# 🌿 Plantasia

Plantasia est une application utilitaire "gamifiée" qui croise l'encyclopédie botanique (wiki), le gestionnaire de tâches (tracker) et le jeu de gestion. 

Le but de l'application est de permettre à l'utilisateur de répliquer son véritable balcon, d'adopter des plantes sous forme de cartes, et de gérer leur entretien quotidien à travers une interface ludique et interactive basée sur le Drag & Drop.

## 🌟 Fonctionnalités Principales

* **📖 Le Codex (Wiki) :** Une encyclopédie sous forme de cartes affichant les propriétés détaillées de chaque plante (besoins en eau, exposition au soleil, etc.).
* **🪴 Le Balcon (Simulation) :** Un espace spatialisé où l'utilisateur place ses plantes adoptées. Le moteur simule les conditions du balcon et met en évidence visuellement les plantes mal placées ou en détresse (alerte d'arrosage, manque de soleil).
* **🗓️ Le Calendrier & Les Actions :** Un système de deck et de main. L'utilisateur peut jouer des cartes d'événements (ex: "Arrosage") sur une timeline pour planifier des actions (To-Do list), ou directement sur les plantes pour valider un entretien.
* **🏆 Progression & Récompenses :** Le suivi rigoureux de l'état des plantes permet de débloquer des cartes annexes et décoratives.

## 🏗️ Architecture Technique

Le projet est développé en **C++** avec la bibliothèque **SDL3** pour le rendu graphique matériel.

L'architecture s'inspire des moteurs de jeux 2D modernes et repose sur plusieurs patrons de conception :
* **MVC (Modèle-Vue-Contrôleur) :** Séparation stricte entre la donnée botanique pure (`PlantProfile`) et sa représentation visuelle interactive (`Card`).
* **Poids Mouche (Flyweight) / Instanciation :** Optimisation drastique de la VRAM via un partage de `SDL_Texture` entre les entités pour garantir des performances optimales même avec des centaines d'éléments à l'écran.
* **Architecture par Vues / Scènes :** Navigation fluide entre les différents modules de l'application (Balcon, Calendrier, Codex).

### 📂 Arborescence du Projet

### 📂 Arborescence du Projet

* **`src/`**
  * `main.cpp` : Point d'entrée de l'application.
  * **`core/`** *(LE MOTEUR GRAPHIQUE - Technique)*
    * `Application.hpp/.cpp` : Boucle principale, gestion du temps (FPS) et de la fenêtre.
    * `InputManager.hpp` : Gestion centralisée de la souris et du Drag & Drop.
    * `ResourceManager.hpp` : Usine à textures (Flyweight) et gestion de la mémoire vidéo.
  * **`data/`** *(LA LOGIQUE MÉTIER - Données)*
    * `PlantProfile.hpp` : Propriétés intrinsèques d'une plante (Nom, besoins).
    * `UserProfile.hpp` : État du joueur (Inventaire, deck, progression).
  * **`views/`** *(LES ÉCRANS - Metteurs en scène)*
    * `ViewManager.hpp` : Machine à états pour naviguer entre les écrans.
    * `BalconyView.hpp` : Logique spatiale et alertes d'environnement.
    * `CalendarView.hpp` : Timeline et planification.
    * `CodexView.hpp` : Interface encyclopédique.
  * **`ui/`** *(LES ACTEURS INTERACTIFS - Composants visuels)*
    * `Card.hpp/.cpp` : Élément visuel réactif (survol, clic, apparence).
    * `DropZone.hpp/.cpp` : Réceptacles logiques (pots, cases du calendrier).

## 🚀 Compilation & Lancement
