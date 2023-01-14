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

- **Phase 1 - Initial Studies 📚**

After reading the subject, I had an impression that it was a project similar to the creation of two programs - server and client - that communicate through signals (SIGUSR1 e SIGUSR2), [MiniTalk](https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/Minitalk_fgastal-.pdf). 

<a href=""><img src="https://github.com/fegastal/42SP-Labs-Notes/blob/main/documents/image/Minitalk-Project.png" alt="Minitalk"></a>

However, the communication between the two programs in question - encoder and decoder - should be via [Shared Memory Operations](https://www.youtube.com/watch?v=a8tR6d47bCc), something I had not seen in the course of my studies, until then.

In order to understand these new concepts and map out the new challenges ahead of me, I chose to follow initial references on the topic, such as:

> This playlist on YouTube: [Huffman's Algorithm in C](https://www.youtube.com/watch?v=o8UPZ_KDWdU&list=PLqJK4Oyr5WShtxF1Ch3Vq4b1Dzzb-WxbP&index=1)

> And this book: [Mastering Algorithms with C - Useful Techniques from Sorting to Encryption](https://www.amazon.com.br/Mastering-Algorithms-C-Kyle-Loudon/dp/1565924533)

These two references were essential to give continuity to the challenge, which was to be delivered in 6 days.🤯

- **Phase 2 - Data Structures 🕸**

> 2.1 Huffman's Tree

In order to start studying data structures, I tried to understand how the Huffman Tree works. Based on the playlist indicated above, I was able to get a good understanding. :)

Basically, when we have files - be it images, video, audio or text - that occupy a large amount of memory because they are heavy, we have the possibility to compress them - it can be by winrar, 7zip or any other software.

In this sense, pixel points with very similar colors can be converted into one color, decreasing the file size, for example.

With the Huffman Algorithm - proposed by David A. Huffman in 1952 during his doctorate at MIT - it is possible to adapt it to compress any type of file, but it is also widely used for text, since it is very efficient and lossless. Come to think of it, this very important algorithm was implemented 70 years ago! 👀

⚠️ What is so interesting about it? 

It makes use of several data structures, such as table, chained list or priority queue, and binary tree. :D It is a lot!

So we need to focus on steps.




