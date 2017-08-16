/**
 * @file main.c
 * @author Franklin Matheus e Leonardo Santos
 * @date 29/11/2016
 * @brief Arquivo principal onde as funções e procedimentos são chamados
 */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "rotinas.h"

/**
 * @brief Classe main
 * @param int quantity          quantidade de parâmetros passados na linha de código
 * @param char *parameters[]    vetor contendo os parâmetros
*/
int main(int quantity, char *parameters[]){
    int length = 0, range = 0, moment_input = 0, counter, i, j;
    int parameter_d = 0, parameter_o = 0, parameter_l = 0, mountain_number = 0;
    
    enum Moment moment;

    if(quantity % 2 == 1){
        for(counter = 0; counter < quantity; counter++){
            if(counter % 2 == 1){
                if(strcmp(parameters[counter], "-d") == 0){
                    range = atoi(parameters[counter+1]);
                    parameter_d = 1;
                } else if(strcmp(parameters[counter], "-o") == 0){
                    parameter_o = counter+1;
                } else if(strcmp(parameters[counter], "-l") == 0){
                    length = atoi(parameters[counter+1]);      
                    parameter_l = 1;
                } else if(strcmp(parameters[counter], "-m") == 0){
                    moment_input = atoi(parameters[counter+1]);
                }
            }
        }
    } else {
        printf("Error\n");
        return 0;
    }

    moment = convert_moment(moment_input);
    verify_range_length(parameter_d, &range, parameter_l, &length);

    int column = length, line = length;
    PIXEL malha[line][column];
    float line_shape[length];

    srand((unsigned) time(NULL));
    int min = rand() % (length/2) + length/3;
    int max = rand() % (length/2) + length/3;

    line_shape[0] = min;
    line_shape[length-1] = max;

    shape(0, length-1, length, range, line_shape);
    sky(line, column, malha, moment);
    mountain(length, malha, line_shape, moment, &mountain_number);
    
    if(moment == MORNING){
        float second_line_shape[length];
        srand((unsigned) time(NULL));
        int value_min = line_shape[0];
        int value_max = line_shape[length-1];
        
        int min = rand() % (length-value_min+(value_min/5));
        int max = rand() % (length-value_max+(value_max/5));
        second_line_shape[0] = value_min + min;
        second_line_shape[length-1] = value_max + max;
        shape(0, length-1, length, range/2, second_line_shape);
        mountain(length, malha, second_line_shape, moment, &mountain_number);
    }

    if(parameter_o == 0){
        save(column, line, malha, "image.ppm");
    } else {
        save(column, line, malha, parameters[parameter_o]);
    }

    return 0;
}