/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgastal- <fgastal-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:13:23 by fgastal-          #+#    #+#             */
/*   Updated: 2022/11/13 05:22:06 by fgastal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ======================== DEFINITIONS

#ifndef ENCODER_H
# define ENCODER_H

// ======================== MACROS

# define SIZE 256

// ======================== INCLUDES

# include <unistd.h> // standard unix functions, like getpid(), write()
# include <stdlib.h> // exit()
# include <sys/types.h> //various type definitions, like pid_t
# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include <string.h>

// ======================== STRUCTS

typedef struct node{
	unsigned char character;
	int frequency;
	struct node *left;
	struct node *right;
	struct node *next;
}Node;

typedef struct list{
	Node *start;
	int size;
}List;

// ======================== UTILS PROTOTYPES

#endif
