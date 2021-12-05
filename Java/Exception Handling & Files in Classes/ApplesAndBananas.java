// Name: Jack Carson
// Course & Lab: CPSC 1061 Lab 11
// Date: April 7, 2021
// Description: Starts with the String "I like to eat, eat, eat apples and bananas."
// Replaces each vowel or set of vowels in this string with the two vowels ay.

import java.lang.String;
public class ApplesAndBananas {
    public static void main(String[] args) {

        // Creates first String with normal syntax.
        String string1 = "I like to eat, eat, eat apples and bananas";
        String string2 = "I like to eat, eat, eat apples and bananas".replaceAll("(I|ea|a|e|i|o)", "ay");
        // Creates second String and uses the (|) regular expression operator to replace specific instances of vowels and double vowels in the String instead of simply every vowel.

        System.out.println("The following 2 Strings have the same syntax, but one has been modified with regular expression and the replaceAll method!!");

        System.out.println();

        System.out.println(string1);
        System.out.println(string2);

    }
}




