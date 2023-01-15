## 42 Labs 👩🏻‍🔬🧪 | Encoder and Decoder Programs


<p align="center">
  <a href="#license"><img src="https://img.shields.io/github/license/sourcerer-io/hall-of-fame.svg?colorB=ff0000"></a>
</p>

> **I'm working on the 42 Labs project at the moment, if you feel interested in studying together, don't hesitate to send me a message! 🤓**

> You can find me through [my discord](https://discord.gg/7QrbMzuT), my [email](mailto:fernanda.gastal.figueiredo@alumni.usp.br) or [LinkedIn](https://www.linkedin.com/in/fernandagastal/). :)


* [Introduction](#introduction)

## Introduction 📍

The Labs project at school [42 São Paulo](https://www.42sp.org.br/) has the proposal that interested students develop a proposed challenge in order to get a 6-month experience in some of the partner companies.

It provides a very important stage in the life of a cadet, since it is the first contact with the job market. It is necessary that the student is at least in the first project of the second phase of the game: the Push Swap - creation of a program to sort numbers -, since the challenge of the selection process in question challenges us in some more advanced subjects, such as Linked List, binary tree, bitwise operations and shared memory.

Short on time? You can check the [challenge subject 🥵](https://github.com/fegastal/42SP-Labs-Notes/blob/main/SUBJECT.md)!

---

## Tools used 🛠

The technologies I used throughout the execution of the project were [Visual Studio Code](https://code.visualstudio.com/) for code development, [Github](https://github.com/) for code versioning, [Discord](https://discord.com/) for community contact and a very important tool for the development of the code flow was [Miro](https://miro.com/). :) I use it for project defense in evaluations as well, so I feel very comfortable in the environment.

I really like to use flows, post-it notes and I have a notebook full of information about the subjects discussed here. 🔮 If you click on the links to the [So_Long](https://miro.com/app/board/uXjVPcf9kOE=/?share_link_id=328504592650), [Minitalk](https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/Minitalk_fgastal-.pdf) and [Push Swap](https://miro.com/app/board/uXjVPG5JxXA=/?share_link_id=610858182881) projects, for example, you can see that it's a standard around here :) I really like schematics, planning and color in the development process.

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/flow_project_so_long.png" alt="Flow Project So Long"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/flow_project_so_long_2.png" alt="Flow Project So Long"></a>

One part that I made sure to focus on throughout the process is to make better named commits, work well on the issue of code versioning on github and, mainly, I discovered through the cadet @acosta-a the [code documentation with Doxygen](https://wiki.scilab.org/Doxygen%20documentation%20Examples). It's something I had seen recurrently in some projects but had never stopped to try to do. :) Very good tip and I'll take it to my other projects too!

---

## Schedule according to the project objective 🗓

It is also important to say that, as a matter of strategy, my 42 Labs project had as its total practical focus the implementation step of these data structures - mainly the binary tree - in order to consolidate well the knowledge. The project is very extensive, involves the study of many new concepts, and therefore it was necessary to establish an order of priority in this regard.

In this sense, it was necessary to make a study schedule during the week of the challenge that encompassed both the Labs project and the Minishell, since the latter is in pairs and mine had not signed up for Labs. Therefore, only I would be entitled to o2, so in order not to jeopardize it, I decided to take both projects in parallel, dedicating my afternoon and evening periods to Labs. 

At the moment the project compresses and decompresses a text in encoded .txt format. However, there is no presence of two programs separately - ```encoder and decoder``` - and there was the study of the "Shared Memory" and "Map" part, however it was not possible to implement it (not yet).

However, despite the time limit for the challenge, the project will continue to be implemented until the remaining parts requested by the subject are completed. 👾

---

## Overall Project Objective ✏️ 

Although I did not implement it in code, throughout the development process I tried to talk to several cadets who were working at a faster pace than me and who had a sense of the project as a whole.

I tried, therefore, to study the main concepts and make a summary of what the project would be in its entirety. The flowchart below was made based on what was discussed during the Labs chat and from the content that cadet @eandre-f - who helped me a lot 💜 - shared with us. 

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/flow_project.png" alt="Flow Project"></a>

One of the cadets I noticed a rapid development of the project, for example, was @ralves-b. Based on his [Labs repository](https://github.com/rodrigo-br/42Labs), I could get a very good idea about the parts of the project in general. :) I recommend him to whoever else is interested.

---

## How to compile the project? 🚀

First, you need to clone my repository into a directory of your choice on your computer:

```git clone https://github.com/42sp/42labs-selection-process-v4-fegastal.git```

Then you can enter this folder and type ```make``` in your terminal. This will generate the .o (objects) files and our .a executable.

Finally, you can type: ```./decoder``` or ```./encoder``` in the terminal. 

It is important to stress that the ideal would be to have two programs running from shared memory, but since I have not been able to achieve this successfully, I have only one file called "main.c" that contains all the contents of my program. 

---

## Phase 1 - Initial Studies 📚

After reading the subject, I had an impression that it was a project similar to the creation of two programs - server and client - that communicate through signals (SIGUSR1 e SIGUSR2), [MiniTalk](https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/Minitalk_fgastal-.pdf). 

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/minitalk-program.png" alt="Minitalk"></a>

However, the communication between the two programs in question - ```encoder and decoder``` - should be via [Shared Memory Operations](https://www.youtube.com/watch?v=a8tR6d47bCc), something I had not seen in the course of my studies, until then.

In order to understand these new concepts and map out the new challenges ahead of me, I chose to follow initial references on the topic, such as:

> This playlist on YouTube: [Huffman's Algorithm in C](https://www.youtube.com/watch?v=o8UPZ_KDWdU&list=PLqJK4Oyr5WShtxF1Ch3Vq4b1Dzzb-WxbP&index=1)

> And this book: [Mastering Algorithms with C - Useful Techniques from Sorting to Encryption](https://www.amazon.com.br/Mastering-Algorithms-C-Kyle-Loudon/dp/1565924533)

These two references were essential to give continuity to the challenge, which was to be delivered in 6 days. 🤯

---

## Phase 2 - Data Structures 🕸

> 2.1 Huffman's Tree 🌳

In order to start studying data structures, I tried to understand how the Huffman's Tree works. Based on the playlist indicated above, I was able to get a good understanding. :)

It is also important to say that my 42 Labs project had as its total practical focus the implementation step of these data structures.

Basically, when we have files - be it images, video, audio or text - that occupy a large amount of memory because they are heavy, we have the possibility to compress them - it can be by WinRar, 7zip or any other software.

In this sense, pixel points with very similar colors can be converted into one color, decreasing the file size, for example.

With the Huffman Algorithm - proposed by David A. Huffman in 1952 during his doctorate at MIT - it is possible to adapt it to compress any type of file, but it is also widely used for text, since it is very efficient and lossless. Come to think of it, this very important algorithm was implemented 70 years ago! 👀

⚠️ What is so interesting about it? 

It makes use of several data structures, such as table, chained list or priority queue, and binary tree. :D It's a lot!

To get an idea of the final product, the figure below illustrates what a Binary Tree would look like. To generate the nodes we need to string these values together in a row or list:

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree.png" alt="Binary Tree"></a>

Note that recursion is required to implement this tree, because we don't know how many nodes will be created. It is also important to note: is the next number less than or greater than/equal to the previous one? 

Each character (1 char) has 8 bits (1 byte) to be represented. Using the [ASCII table](https://www.ime.usp.br/~pf/algoritmos/apend/ascii.html), we can note that in the string "I want to get an internship", the value of the character "I" in binary would be 01001001, of "W" would be 01010111 and so on. This 27-character (or symbol) string contains 27 * 8 bits = 216 bits. With the binary tree, this total amount of bits can be reduced a lot! 🌈

So we need to focus on the coding steps:

🐾 1 | Determine the frequency of each element

For example, in the sentence "I want to get an internship", we have a certain frequency of occurrence for each character, if we want to compact this text.

In this case, we have:

symbol  | frequency |
---|------|
`i` | 3	|
`w` | 1	|
`a` | 2 |
`n` | 3 |
`t` | 4 |
`o` | 1	|
`g` | 1 |
`e` | 2 |
`p` | 1 |
` ` | 5 |
`r` | 1	|
`s` | 1 |

<details>
  <summary>The functions created for this step were:</summary>

*```void initializes_tab_with_zero(unsigned int tab[])```
 /*
has the goal of making the table initialization from zero elements, considering that SIZE equals 256.
@param tab[] the frequency table.
*/

*```void fill_tab_frequency(unsigned char text[], unsigned int tab[])```
 /*
receives both the characters (char) that are passed as a text array, as well as the amount of their frequency (int).
@param[out] text[] the string I want to encode.
@param[in] tab[] the frequency table.
*/

*```void print_tab_frequency(unsigned int tab[])``` 
/*
Takes the table generated in the previous function and prints it to the terminal. It was used as a test, basically.
@param tab[] the frequency table.
*/
</details>

In the figure below, we can analyze how this table is generated in the output:

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/frequency_table.png" alt="Frequency Table"></a>

🐾 2 | Sorted Linked List

After going through our text and once we already have this frequency table, it will originate a list or a priority row, and from this row we will remove the elements and assemble our binary tree, grouping the symbols according to frequency in increasing or decreasing order.

We need to be careful about this, because if we order the table in ascending order, when we remove the elements from the list, they will be removed from the beginning and we need to always remove the elements with the lowest frequency.

It is also nice to note that the Linked List knowledge was started along the [Push Swap](https://miro.com/app/board/uXjVPG5JxXA=/?share_link_id=610858182881) project, the first project of the second phase of 42SP :) this helped in the design of this part of the project.

Sorting the previous sentence "I want to get an internship" in ascending order, we have: 

symbol  | frequency |
---|------|
`w` | 1	|
`o` | 1	|
`g` | 1 |
`p` | 1 |
`r` | 1	|
`s` | 1 |
`a` | 2 |
`e` | 2 |
`i` | 3	|
`n` | 3 |
`t` | 4 |
` ` | 5 |

In this way, it is possible to generate the chained list of nodes of a binary tree. 🚀

For example, by taking row 01 of the table, `w` with frequency 1, we can generate this node below:

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/linked_list_node.png" alt="Node Linked List"></a>

It has one pointer to the left and one to the right, and all nodes are exactly the same: it has one character and one frequency.

<details>
  <summary>The functions created for this step were:</summary>

* ```void create_list(List *list)```
/*
Function that creates an ordered list.
@param the ordered list that will be used to form the binary tree.
*/

* ```void insert_order(List *list, No *no);```
/*
Function that inserts a node in an ordered linked list.
@param[out] the ordered list that will be used to form the binary tree.
@param[in] the node generated from two elements in the ordered list.
*/

* ```void fill_list(unsigned int tab[], List *list);```
/*
Function that fills the list with nodes in an ordered (ascending) manner.
@param[out] tab[] the frequency table.
@param[in]  the ordered list that will be used to form the binary tree.
*/

* ```void print_list(List *list);```
/*
Function that prints the list on the terminal.
@param the ordered list that will be used to form the binary tree.
*/

</details>

In the figure below, we can analyze how this list is generated in the output:

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/output_linked_list.png" alt="Output Linked List"></a>

🐾 3 | Building the Huffman Tree

After forming our queue or ordered chained list, we move on to the assembly phase of our binary tree. :) Which is really cool when it's done for the first time! :D

At first, we need to remove the first two elements (nodes) of LOWEST frequency: in our case, `w` and `o`. In a binary tree, we have "leaves" (a node which has no children), we also have "intermediate nodes" which always have 2 children (when the path forks) and the frequency of that particular node is the sum of the frequencies of its children.

One important detail is that a binary tree is different from a binary search tree, specifically. Here, smaller elements are always to the left of the root and larger elements are to the right of it. :)

It sounds complicated, but it is actually quite simple. Let's go:

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/sum_leaf_frequency.png" alt="Sum of leaf frequency"></a>

Now, after inserting the intermediate node into our queue in an ordered fashion, then it will be among the nodes that have frequency 2, considering that the `+` node is an intermediate node, with the leaves `w` and `o`. 

symbol  | frequency |
---|------|
`g` | 1 |
`p` | 1 |
`r` | 1	|
`s` | 1 |
`a` | 2 |
`e` | 2 |
`+` | 2 |
`i` | 3	|
`n` | 3 |
`t` | 4 |
` ` | 5 |

Therefore, it is necessary to repeat the process - now with `g` and `p` - until we get an empty row:

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_1.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_2.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_3.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_4.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_5.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_6.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_7.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_8.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_9.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_10.png" alt="Sum of leaf frequency"></a>
<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/binary_tree_process_11.png" alt="Sum of leaf frequency"></a>

<details>
  <summary>The functions created for this step were:</summary>

* ```No* remove_at_start(List *list)```
 /*
Function that removes the first two lowest frequency nodes.
@param the ordered list that will be used to form the binary tree.
*/

* ```No* assemble_tree(List *list);```
 /*
Function that constructs the huffman tree.
@param the priority queue.
*/

* ```void print_tree(No *root, int size);```
 /*
Function that prints the Huffman's tree.
@param[out] the root node of the binary tree.
@param[in]  the size of the tree.
*/

* ```void destroy_tree(No *root);```
 /*
Function to destroy the nodes of the tree and release the stored memory.
@param the root node of the binary tree.
*/

</details>

🐾 4 | Encoding 🔒 and Dictionary 📖

In the image above, you can see that when we go to a path to the left, we get the binary value 0, this is a convention of Huffman's Law. If we go to the right, we get the value 1. Therefore, to get to char "R", we get the binary value 0100, which is 4 bits. This implies that if we were to use the ASCII table to determine its value in binary, we would arrive at the value 01010010, which is 8 bits. Therefore, using the binary tree, we can use fewer bits to arrive at a desired character value. 🔎

The coding step is just that. :) Reading the binary tree from its root, we go through it until we find the character "R" that is equivalent to 0100 in binary. So, after going through it completely, we need to generate a table with our new codes for each character according to its frequency.

This table will be called a dictionary! 📖🔮

To assemble it, we need to go through our entire tree from start to finish in a recursive (important) manner, starting at the root and going always to the left, until we reach a leaf. We do this by traversing the entire tree until we have filled our entire dictionary table.

Using again the string "I want to get an internship", we know that going by the ASCII table, we would need 27 * 8 = 216 bits to encode this sentence. Using the binary tree, we only need 58 bits! 🤯

symbol  | frequency | encoding (bits)
---|------|------|
`w` | 1	| 11100
`o` | 1	| 11101
`g` | 1 | 11110
`p` | 1 | 11111
`r` | 1	| 0100
`s` | 1 | 0101
`a` | 2 | 1100
`e` | 2 | 1101
`i` | 3	| 011
`n` | 3 | 100
`t` | 4 | 101
` ` | 5 | 00

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/dictionary_output.png" alt="Dictionary"></a>

<details>
  <summary>The functions created for this step were:</summary>

* ```int height_tree(No *root);```
 /*
Function to check the height of the binary tree. 
Note that + 1 is for the null character '\0'.
@param the root node of the binary tree.
*/

* ```char** allocate_dictionary(int columns);```
 /*
Function that allocates memory for the dictionary, 
receiving the value of the number of columns (which is the 
height of the Huffman tree + 1)
Important to note that the number of rows, in turn, is the 
size of the ASCII table (macro SIZE).
@param the number of columns in the matrix.
*/

* ```void generate_dictionary(char **dictionary, No *root, char *path, int columns);```
 /*
In this function I will produce (generate) my dictionary. I get some parameters
like the dictionary, the root node, the path and the columns.
Note that this is a recursive procedure: as I go 
in my tree to the left(0) or to the right(1), I concatenate (with
strcat) to 0 or 1, and the path is precisely the code of the character
generated until it reaches a leaf 
(that is, a non-intermediate node, with no children).
@param the dictionary.
@param the root node of the binary tree.
@param the path of the tree in bits.
@param the number of columns in the matrix.
*/

* ```void print_list(List *list);```
 /*
Function for printing the dictionary.
@param the sorted list.
*/

* ```int calculate_string_size(char ** dictionary, unsigned char *text);```
 /*
Function that calculates the string size, 
given the dictionary and the text
as parameters. Note that text[i] will 
become a number represented in ASCII.
@param double pointer to the dictionary.
@param the text to be encoded / decoded.
*/

* ```char* encode(char ** dictionary, unsigned char *text);```
 /*
Function responsible for doing the encoding of our text.
Receives as parameter the dictionary and the strings.
Note that calloc takes the number of characters from an array
and the size of a character.
@param double pointer to the dictionary.
@param the text to be encoded / decoded.
*/
</details>

🐾 5 | Decoding 🔓

Decoding is the reverse process of the above.  That is, we have the sequence of bits, for example:

```11100111011111011111010001011100110101110010100```

From this sequence, we can take the first byte (i.e., the first 8 bits of it) and, starting from the root of our tree, we will walk over it. The first byte of our sequence is:

So first we go right (1), then right (1), right (1), left (0) and left (0). Considering this path, we can find a leaf (i.e., no children). Therefore, we find the character `w`. 🤗 After finding the leaf, we go back to the root of the tree and start the process all over again until we reach a leaf (and a corresponding character) again.

<details>
  <summary>The functions created for this step were:</summary>

* ```char* decode(unsigned char text[], Node *root);```
/*
Function responsible for the decoding - the process 
inverse to the codification - of a text. 
@param[out] the text to be encoded / decoded.
@param[in] the root node of the binary tree.
*/
</details>

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/decoder_output.png" alt="Decoder"></a>

🐾 6 | Bitwise Operations

In this particular step, it was very important to note the parallel with the learning about "Bitwise Operations" obtained in both [Minitalk](https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/Minitalk_fgastal-.pdf) and [Push Swap](https://miro.com/app/board/uXjVPG5JxXA=/?share_link_id=610858182881) during the implementation of the "Radix Sorting Algorithm". :)

Basically, the Right Shift (>>) shifts all bits to the right. So, for example, taking the binary 0010 0100 (equivalent to the number 36 in the base 10 in the ASCII table) and doing a Right Shift >> two places to the right, we have 0000 1001 (equivalent to the number 9 in the base 10 in the ASCII table).

We also have the AND operator which works as follows for each bit:

```
1 & 1 == 1
1 & 0 == 0
0 & 1 == 0
0 & 0 == 0
```

So, taking the leading bits of the number 2 in base 10 in the ASCII table and doing the AND (&) operation with the number 5 in base 10 in the ASCII table:

```
0010
0101
_________
2&5: 1001 (equivalent to the number 9 in ASCII base 10)
```

Reviewing these concepts was very important in order to implement the compression and decompression part of a file, as we will see in the next two topics. An important reference was this [video here](https://www.youtube.com/watch?v=Ew2QnDeTCCE).

🐾 7 | Creating a compressed file (text.txt)

🐾 8 | Decompressing the file (text.txt)

---

> 2.2 Map

Next structure to be created is a [map of the symbols and their respective codes](https://www.geeksforgeeks.org/which-data-structure-is-used-by-map/). Since in a tree, the paths from the root to any of the leaves (Nodes where the two descendants, left and right, are null) are unique, the encoding and decoding of the codes always have an associated tree.

According to the link above: 

> "Map is the part of the STL library that stores key value pairs in it and no two values have the same keys but the different keys can store similar values. The map stores keys in sorted order. For map’s internal implementation it uses Red-Black Tree."

> "A red-black tree is a kind of self-balancing binary search tree where each node has an extra bit, and that bit is often interpreted as the color (red or black) which is used to ensure that the tree remains balanced during insertions and deletions."

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/red_black_tree.png" alt="Red Black Tree"></a>

---

## Phase 3 - Sharing Memory 🤝

Due to the research on the subject with a short time to go, I have not yet been able to delve into it. However, from the little that I have researched, I know that  Shared memory is an operating-system feature that allows the database server threads and processes to share data by sharing access to pools of memory.

The database server uses shared memory for the following purposes:

* To reduce memory usage and disk I/O - enables the database server to reduce overall memory usage because the participating processes, in this case, virtual processors, do not require maintaining private copies of the data that is in shared memory.
* To perform high-speed communication between processes, because it processes read and write messages at the speed of memory transfers.

The figure below was made based on the studies of cadet @eandre-f. 🤓 Here, you can get a sense of the whole.

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/shared_memory_operations_2.png" alt="Shared Memory Operations"></a>

---
## Cadet contributors

A very special thanks to all the cadets who helped me in any way throughout the project, including the company in the labs' study chats. 💜

Átila @acosta-a |
Beatriz @bede-car |
Emmanuel @etomiyos |
Erick @eandre-f |
Fernanda Fahl @feralves |
Gabriel @gasouza |
Joana @jvidon-n |
Jeferson @jgiacomo |
Lucas Queiroz @lsilva-q |
Mayara @macarval |
Raphael @rarobert |
Ricardo @ryoshio |
Sheela @sguilher

The feeling was that I had made the "piscina" again! (: the project was very challenging, it made me question, rethink my trajectory at 42. Having you by my side in this made all the difference! Thank you. 🎈

---