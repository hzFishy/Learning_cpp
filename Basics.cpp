
type_de_retour nom_de_la_fonction(paramètres) {
    // Corps de la fonction
    // Instructions et logique de la fonction
    // ...
    return valeur_de_retour; // Facultatif, dépend du type de retour
}
/*
- `type_de_retour` : C'est le type de données renvoyé par la fonction. Cela peut être un type primitif (comme `int`, `float`, `char`, etc.), un type personnalisé (une classe, une structure) ou même `void` si la fonction ne renvoie aucune valeur.

- `nom_de_la_fonction` : C'est le nom que vous donnez à votre fonction. Choisissez un nom descriptif qui indique clairement le but de la fonction.

- `paramètres` : Ce sont les données d'entrée de la fonction, également appelées arguments. Vous pouvez spécifier plusieurs paramètres en les séparant par des virgules. Chaque paramètre est composé d'un type et d'un nom. Par exemple : `int a, float b`.

- `Corps de la fonction` : C'est l'endroit où vous écrivez le code qui sera exécuté lorsque la fonction est appelée. Vous pouvez y inclure des instructions, des opérations, des boucles, des conditions, etc. Tout le code à l'intérieur des accolades `{}` fait partie du corps de la fonction.

- `return` : Si votre fonction a un type de retour autre que `void`, vous pouvez utiliser l'instruction `return` pour renvoyer une valeur à l'endroit où la fonction a été appelée. Cela termine l'exécution de la fonction à ce point. La valeur de retour doit correspondre au type de retour spécifié.
*/



// Heading (doestn compile if not included)
#include <iostream>

// Fonction
int func() {
  //code
}

//Print:
std::cout << "Text \n";

//Compile:
g++ filename.cpp -o filenametoexecute

//execute:
./filenametoexecute
