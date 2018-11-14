# Cpp_Data_Structures_And_Algorithms
Packt Textbook - Wisnu Anggoro

Lacking in quality and precision.

Although I’ve learnt about various data structures over the years as a professional programmer, I’ve never had a formal education into them and wanted a text to solidify and expand my knowledge. Early on however, you pick up that the author’s first language isn’t English. His sentences can be ambiguous and some only made sense because I already had some area knowledge with which I could piece together what was meant. This is very different to other programming texts I’ve read that have quite a precise way with words. (E.g. Accelerated C++ by Andrew Koenig & Barabara Moo, Effective Modern C++ by Scott Meyers, Exceptional C++ by Herb Sutter).

The same lack of quality also pervaded the code. Although, the code does adequately demonstrate the underlying mechanics fairly well, it’s very rough and “non-production”. Eg.:
-	C++98 use of naked pointers via new. Ok, so we don’t want to use smart pointers, but there’s not a single use of delete. Hence, there’s memory leaks throughout.
-	“Animal dog = Animal();” Strange style. 
-	void LinkedList<T>::RemoveHead(){…} forgets to update the Tail pointer if there was only one element (i.e. Head and Tail are the same element).  Same thing in void DoublyLinkedList<T>::RemoveHead(){…}.
-	Builds an AVL tree class inheriting from base BST but doesn’t make overridden functions virtual within base.

There are also times when the author doesn’t quite seem to understand what’s going on:
-	“To search for the desired element, we can use find() method provided by the vector.” But code then uses <algorithm> find(), there is no vector::find().
-	Conversely, “We can use the erase() method provided by the vector. To use this method, we also need to include the algorithm header.” He then correctly employs vector::erase() without needing <algorithm>.

Chapter 9 is incomplete both in terms of content (“We will now show”… but then the section abruptly ends) and in terms of presentation (e.g. the font will randomly change in places). There’s a brief introduction for a linear congruential generator but with a = 1 and m = 10. Why couldn’t some proper values be used instead?

I could go on but I’ve made my point. I did learn how to balance a binary search tree and a new sorting algorithm (radix), so the text did expand my knowledge. I also commend the author for at least trying to produce a text and help the community. But overall, I wouldn’t recommend as there are surely better texts out there. Even putting aside the monetary cost of the text, you will waste time trying to understand the author's use of English.
