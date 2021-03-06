/*
** EPITECH PROJECT, 2018
** matrix.h
** File description:
** matrix
*/

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

typedef struct matrix_s matrix_t;

#define MATRIX struct matrix_s

MATRIX add_matrix(MATRIX matrix1, MATRIX matrix2);
MATRIX copy_matrix(MATRIX matrix);
MATRIX create_matrix(size_t size, long double *value);
void destroy_matrix(MATRIX matrix);
MATRIX div_matrix(MATRIX matrix, long double nb);
MATRIX mul_matrix(MATRIX matrix1, MATRIX matrix2);
MATRIX sub_matrix(MATRIX matrix1, MATRIX matrix2);

struct matrix_s
{
    long double **value;
    size_t      size;
};

#endif
