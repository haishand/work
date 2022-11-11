// BEGIN CUT HERE
// PROBLEM STATEMENT
// The ancient civilization of Nlogonia used the same 26 letters as modern English: 'a'-'z'.
However, we do not know the order in which these letters appeared in the Nlogonian alphabet.

One particular custom in Nlogonia was that in a good word the letters appear in non-decreasing order.
For example, in English the word "ciel" is not a good word because in the alphabet 'i' is after 'e'.
The word "ceil" is a good word because 'c' <= 'e' <= 'i' <= 'l'.

You are given the String[] words.
Each element of words is a nonempty string of lowercase English letters.
Return "Possible" if it is possible that all elements of words were good words in Nlogonian, and "Impossible" otherwise.

In other words, return "Possible" if and only if there is at least one possible Nlogonian alphabet such that the letters of each word in words are in non-decreasing alphabetical order.

DEFINITION
Class:AlphabetOrderDiv1
Method:isOrdered
Parameters:String[]
Returns:String
Method signature:String isOrdered(String[] words)


CONSTRAINTS
-words has between 2 and 100 elements inclusive.
-The size of each element of words will be between 1 and 100 inclusive.
-Elements of words contains only English lowercase letters from 'a' to 'z'.


EXAMPLES

0)
{"single","round","match"}

Returns: "Possible"

A possible Nlogonian alphabet would be "bfjkmapqrositchundglevwxyz"

1)
{"topcoder","topcoder"}

Returns: "Impossible"

The word "topcoder" can never be a good word.
The character 'o' cannot be both before 'p' and after 'p' in the alphabet.

2)
{"algorithm", "contest"}

Returns: "Impossible"



3)
{"pink","floyd"}

Returns: "Possible"



4)
{"gimnasia","y","esgrima","la","plata"}

Returns: "Impossible"



// END CUT HERE
import java.util.*;
public class AlphabetOrderDiv1 {
	public String isOrdered(String[] words) {
		
	}
	public static void main(String[] args) {
		AlphabetOrderDiv1 temp = new AlphabetOrderDiv1();
		System.out.println(temp.isOrdered(String[] words));
	}
}
