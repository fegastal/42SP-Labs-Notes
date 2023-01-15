## 42 Labs 👩🏻‍🔬🧪 | Encoder and Decoder Programs


<p align="center">
  <a href="#license"><img src="https://img.shields.io/github/license/sourcerer-io/hall-of-fame.svg?colorB=ff0000"></a>
</p>

> **I'm working on the 42 Labs project at the moment, if you feel interested in studying together, don't hesitate to send me a message! 🤓**

> You can find me through [my discord](https://discord.gg/7QrbMzuT), my [email](mailto:fernanda.gastal.figueiredo@alumni.usp.br) or [LinkedIn](https://www.linkedin.com/in/fernandagastal/). :)

## Introduction

The Labs project at school [42 São Paulo](https://www.42sp.org.br/) has the proposal that interested students develop a proposed challenge in order to get a 6-month experience in some of the partner companies.

It provides a very important stage in the life of a cadet, since it is the first contact with the job market. It is necessary that the student is at least in the first project of the second phase of the game: the Push Swap - creation of a program to sort numbers -, since the challenge of the selection process in question challenges us in some more advanced subjects, such as Linked List, binary tree, bitwise operations and shared memory.

Short on time? You can check the [challenge subject 🥵](https://github.com/fegastal/42SP-Labs-Notes/blob/main/SUBJECT.md)!

---

- **Phase 1 - Initial Studies 📚**

After reading the subject, I had an impression that it was a project similar to the creation of two programs - server and client - that communicate through signals (SIGUSR1 e SIGUSR2), [MiniTalk](https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/Minitalk_fgastal-.pdf). 

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/minitalk-program.png" alt="Minitalk"></a>

However, the communication between the two programs in question - encoder and decoder - should be via [Shared Memory Operations](https://www.youtube.com/watch?v=a8tR6d47bCc), something I had not seen in the course of my studies, until then.

In order to understand these new concepts and map out the new challenges ahead of me, I chose to follow initial references on the topic, such as:

> This playlist on YouTube: [Huffman's Algorithm in C](https://www.youtube.com/watch?v=o8UPZ_KDWdU&list=PLqJK4Oyr5WShtxF1Ch3Vq4b1Dzzb-WxbP&index=1)

> And this book: [Mastering Algorithms with C - Useful Techniques from Sorting to Encryption](https://www.amazon.com.br/Mastering-Algorithms-C-Kyle-Loudon/dp/1565924533)

These two references were essential to give continuity to the challenge, which was to be delivered in 6 days. 🤯

It is also important to say that, as a matter of strategy, my 42 Labs project had as its total practical focus the implementation step of these data structures - mainly the binary tree - in order to consolidate well the knowledge. The project is very extensive, involves the study of many new concepts, and therefore it was necessary to establish an order of priority in this regard.

---

- **Phase 2 - Data Structures 🕸**

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

*```void initializes_tab_with_zero(unsigned int tab[])``` has the goal of making the table initialization from zero elements, considering that TAM equals 256.
 /*
Join the string s2 to string s1 generating a new string.
@param[out] s1 The memory area to join to.
@param[in]  s2  The memory area to copy from.
*/

*```void fill_tab_frequency(unsigned char texto[], unsigned int tab[])``` receives both the characters (char) that are passed as a text array, as well as the amount of their frequency (int);
 /*
 Join the string s2 to string s1 generating a new string.
@param[out] s1 The memory area to join to.
@param[in]  s2  The memory area to copy from.
*/

*```void print_tab_frequency(unsigned int tab[])``` takes the table generated in the previous function and prints it to the terminal. :) It was used as a test, basically.
/*
Join the string s2 to string s1 generating a new string.
@param[out] s1 The memory area to join to.
@param[in]  s2  The memory area to copy from.
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

* ```void criar_lista(Lista *lista);```
 /*
Join the string s2 to string s1 generating a new string.
@param[out] s1 The memory area to join to.
@param[in]  s2  The memory area to copy from.
*/

* ```void inserir_ordenado(Lista *lista, No *no);```
 /*
Join the string s2 to string s1 generating a new string.
@param[out] s1 The memory area to join to.
@param[in]  s2  The memory area to copy from.
*/

* ```void preencher_lista(unsigned int tab[], Lista *lista);```
 /*
Join the string s2 to string s1 generating a new string.
@param[out] s1 The memory area to join to.
@param[in]  s2  The memory area to copy from.
*/

* ```void imprimir_lista(Lista *lista);```
 /*
Join the string s2 to string s1 generating a new string.
@param[out] s1 The memory area to join to.
@param[in]  s2  The memory area to copy from.
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

🐾 4 | Encoding 🔒

In the image above, you can see that when we go to a path to the left, we get the binary value 0, this is a convention of Huffman's Law. If we go to the right, we get the value 1. Therefore, to get to char "R", we get the binary value 0100, which is 4 bits. This implies that if we were to use the ASCII table to determine its value in binary, we would arrive at the value 01010010, which is 8 bits. Therefore, using the binary tree, we can use fewer bits to arrive at a desired character value. 🔎

The coding step is just that. :) Reading the binary tree from its root, we go through it until we find the character "R" that is equivalent to 0100 in binary. So, after going through it completely, we need to generate a table with our new codes for each character according to its frequency.

Essa tabela será chamada de dicionário! 📖🔮

Para montá-lo, precisamos percorrer a nossa árvore completa do início ao fim de forma recursiva (importante), começando pela raiz e vamos sempre para a esquerda, até chegar em uma folha. Fazemos isso percorrendo toda a árvore até preencher toda a nossa tabela de dicionário.

Utilizando-se novamente a string "I want to get an internship", sabe-se que indo pela tabela ASCII, precisaríamos de 27 * 8 = 216 bits para codificar essa frase. Através da árvore binária, precisamos de:

symbol  | frequency | encoding
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

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/dictionary.png" alt="Dictionary"></a>


