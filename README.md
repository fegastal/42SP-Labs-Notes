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

For this table to be generated, it was necessary to create 3 specific functions:

The function ```initializes_tab_with_zero``` has the goal of making the table initialization from zero elements, considering that TAM equals 256.

The function ```fill_tab_frequency``` receives both the characters (char) that are passed as a text array, as well as the amount of their frequency (int);

The function ```print_tab_frequency``` takes the table generated in the previous function and prints it to the terminal. :) It was used as a test, basically.

In the figure below, we can analyze how this table is generated in the output:

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/frequency_table.png" alt="Frequency Table"></a>

🐾 2 | Sorted Linked List

After going through our text and once we already have this frequency table, it will originate a list or a priority row, and from this row we will remove the elements and assemble our binary tree, grouping the symbols according to frequency in increasing or decreasing order.

We need to be careful about this, because if we order the table in ascending order, when we remove the elements from the list, they will be removed from the beginning and we need to always remove the elements with the lowest frequency.

Sorting the previous sentence in ascending order, we have: 

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









