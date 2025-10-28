# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

Veille technologique:

Question 1 : C++
Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours:

Dans ma méthode d’affichage, tous les livres de la bibliothèque sont stockés dans un vecteur. J’utilise donc des 
"pointer", qui sont des pointeurs intelligents modernes en C++. Cela veut dire que je ne m’occupe jamais de
libérer la mémoire, c’est fait automatiquement dès que le livre n’est plus utilisé ou retiré du vecteur.Dans la 
boucle for dans library.cpp (méthode displayAllBooks), chaque "ptr" (C'est comme ca que je l'ai nommé) est un 
pointer vers un Book (livre). Pour trier et afficher, j’utilise get() afin d’obtenir un pointeur brut juste pour 
cette opération temporaire.Grâce au pointer (unique_ptr), mon code est plus simple à écrire et sûr. Il n’y a pas 
de “delete”, pas de risque d’oublier de libérer la mémoire. C’est pratique et efficace pour la gestion de tous mes 
objets dynamiques dans ce projet.​
----------------------------------------------------------------------------------------------------------------------------
Question 2 : Options de développement possible
Proposez une solution plus adaptée pour la gestion de bibliothèque et faisant appel éventuellement à une technologie autre que le C++, et expliquez comment vous interfaceriez ça avec le C++. Pensez au futur de cette bibliothèque à Alexandrie qui pourrait éventuellement contenir des millions de livres : 

Dans mon projet, je pourrais améliorer la gestion de la bibliothèque en utilisant une base de données intégrée (comme SQLite), c’est une base de données légère et facile a acile à intégrer directement dans le programme (pas besoin d'installer un serveur à part). Avec SQLite, on peut stocker toutes les infos sur les livres, les emprunts, et les utilisateurs dans des tables organisées. C'est beaucoup mieux pour gérer les données, à éviter les erreurs, et ça serait surtout utile si la bibliothèque devient très grande avec beaucoup de livres à gérer. De plus, il existe des bibliothèques C++ (SQLiteCpp) qui simplifient la connexion à SQLite, donc ça ne serait pas trop compliqué à mettre en place. Ces bibliothèques gèrent la connexion à la base, l’exécution des requêtes SQL, et la récupération des résultats avec une interface moderne et sécurisée, basée sur les bonnes pratiques du C++ (en utilisant des exceptions, RAII, etc.). De ce fait, cette solution me peremt de garder toute la "puissance" du code C++ pour profiter d'n stocakge robuste, performant et facile à maintenir pour toutes les données de la bibliothèque.