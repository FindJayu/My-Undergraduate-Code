#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Define constants for # of sentences and # of chars in each sentence
#define SEN 20
#define SEN_LEN 50

int main() {
    // char arrays holding required words
    char *article[] = {"the", "a", "one", "some", "any"};
    char *noun[] = {"boy", "girl", "dog", "town", "car"};
    char *verb[] = {"drove", "jumped", "ran", "walked", "skipped"};
    char *preposition[] = {"to", "from", "over", "under", "on"};

    // Seed the RNG, declare a sentence string of size 50, and char array holding 20 sentences
    srand(time(NULL)); 
    char sentence[SEN_LEN];
    char sentences[SEN][SEN_LEN];

    for (int i = 0; i < 20; i++) {
        // Generate a random number between 0 and 4 for each of the 5 arrays
        int rand_article = rand() % 5;
        int rand_noun = rand() % 5;
        int rand_verb = rand() % 5;
        int rand_preposition = rand() % 5;
        int rand_article2 = rand() % 5;
        int rand_noun2 = rand() % 5;

        // Declare a string to hold the first index of an article as uppercase
        char capitalized_article[SEN_LEN];
        capitalized_article[0] = toupper(article[rand_article][0]);

        // Copy the remaining chars in rand_article to capitalized_article by an offset of 1
        strcpy(capitalized_article + 1, article[rand_article] + 1);

        // Concatenate the remaining indexes of article, noun, verb, and preposition to sentence separated by spaces
        strcpy(sentence, capitalized_article);
        strcat(strcat(sentence, " "), noun[rand_noun]);
        strcat(strcat(sentence, " "), verb[rand_verb]);
        strcat(strcat(sentence, " "), preposition[rand_preposition]);
        strcat(strcat(sentence, " "), article[rand_article2]);
        // Finalize concatenation by adding a period
        strcat(strcat(strcat(sentence, " "), noun[rand_noun2]), ".");

        // Copy the sentence to the sentences array
        strcpy(sentences[i], sentence);
    }
    // Print the sentences in the sentences array
    for (int i = 0; i < 20; i++) {
        printf("%s\n", sentences[i]);
    }
return 0;
}

/* Three runs of the program yielded: 

Any town skipped under one dog. 
One boy jumped from any girl.
The town jumped from one town.
Any girl ran under any town.
One town drove on one car.
Some car walked under any town.
One town ran to some boy.
One girl skipped under some car. *****
Some car skipped from any car.
A car drove from any girl.
Any girl walked on some town.
The boy ran on any dog.
The car walked under the dog.
A dog skipped to the town.
One girl ran on one girl. *****
Some boy drove from some dog. *****
Some girl ran on the girl.
The boy walked to one boy. *****
One town skipped to the car.
Some girl walked to a dog. *****
Any town ran over the girl.
The dog walked from a dog. *****
A boy ran under any boy.
The town jumped to some town. *****
The girl ran over the girl. *****
Any boy drove to some town.
Any town walked over the car.
One town walked under some boy.
The town jumped to a town. *****
A car drove under one boy.
Some dog jumped from some dog.
One boy ran on one girl.
Any girl jumped from a car. 
A girl ran on one town.
Some car skipped over any dog.
Any dog skipped on a boy.
One boy jumped from the girl. *****
A girl walked on any town.
Any dog walked on one boy.
A town ran from the dog. *****
Some boy walked on any girl.
Any car walked on one town.
Any town drove to some car.
Some boy walked under the boy. 
Some dog drove over some boy.
One girl drove from the car. 
Some town ran from the boy. *****
A town jumped to some dog. 
A car jumped on any town. 
One dog jumped to one town. *****
A town jumped over any town. 
A car jumped from a boy. 
Any dog jumped to any town. 
Any town jumped on one boy. 
Any girl ran under some boy. 
One car walked under a dog. 
A car ran under any town. 
A dog drove on a dog. 
A dog jumped from one boy. 
Some boy walked to some dog. 

Of these 60 sentences, approximately 13 are sensical while the remaining 47 are nonsensical. 
We can simplify this to a ratio of approximately 12/60 = 1/5. 
Considering each array of 5 words, we can assume that arrays of 6 words would lead to a ratio of 1/6, and vice versa. 
This interpretation makes sense under the condition that four arrays with one word each would lead to a sensical sentence 100% of the time. */
