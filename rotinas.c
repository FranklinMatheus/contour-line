/**
 * @file rotinas.c
 * @author Franklin Matheus e Leonardo Santos
 * @date 26/11/2016
 * @brief Arquivo que contém as sub-rotinas do projeto
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rotinas.h"

/**
 * @brief Sub-rotina que pinta o céu 
 *
 * Pinta o céu da imagem de acordo com o momento desejado (manhã, tarde ou noite)
 *
 * @param line      quantidade de linhas da matriz
 * @param column    quantidade de colunas da matriz
 * @param malha[][] matriz de registros do tipo PIXEL, onde cada célula representa uma cor no formato RGB 
 * @param moment    momento que a imagem será gerada, importante para definir a cor do céu
*/
void sky(int line, int column, PIXEL malha[line][column], enum Moment moment){
    int i, j, gradient = 66;
    int ratio;
    int rgb[3];

    if(moment == MORNING){
        rgb[0] = 153;
        rgb[1] = 192;
        rgb[2] = 255;
    } else if(moment == AFTERNOON){
        rgb[0] = 255;
        rgb[1] = gradient;
        rgb[2] = 80;                
    } else if(moment == EVENING){
        rgb[0] = 0;
        rgb[1] = 20;
        rgb[2] = 50;
    }

    if(line > (255-66)){
         ratio = line/(255-66);
    } else {
        ratio = 1;
    }
    for(i = 0; i < line; i++){
        for(j = 0; j < column; j++){
            malha[i][j].r = rgb[0];
            malha[i][j].g = rgb[1];
            malha[i][j].b = rgb[2];
        }
        if(i % ratio == 0){
            gradient += 1;
            if(moment == AFTERNOON){
                rgb[1] = gradient;
            }
        }
    }
    if(moment == 3){    
        stars(line, column, malha);
    }
}

/**
 * @brief Sub-rotina que pinta as estrelas
 *
 * Gera um número aleatório de estrelas em locais aleatórios da matriz
 * 
 * @param line      quantidade de linhas da matriz
 * @param column    quantidade de colunas da matriz
 * @param malha[][] matriz de registros do tipo PIXEL, onde cada célula representa uma cor no formato RGB
*/

void stars(int line, int column, PIXEL malha[line][column]){
    int i, x, y, stars;
    stars = rand() % line;

    for(i = 0; i < stars; i++){
        y = rand() % line;
        x = rand() % column;

        malha[y][x].r = 255;
        malha[y][x].g = 255;
        malha[y][x].b = 255;
    }
}

/**
 * @brief Sub-rotina que faz os cálculos para encontrar os valores de altitude 
 *
 * Calcula os valores de altitude da montanha que irão ser inseridos no vetor
 *
 * @param begin         indice do primeiro valor do intervalo que está sendo manipulado
 * @param end           indice do último valor do intervalo que está sendo manipulado
 * @param length        tamanho da matriz que representa a imagem
 * @param range         fator deslocamento
 * @param line_shape[]  vetor que armazena as altitudes que a montanha alcança
*/
void shape(int begin, int end, int length, int range, float line_shape[length]){
    int i, min, max;

    float displacement; 

    if (range > 0) {
		displacement = rand() % (range*2 + 1) - range;
	} else {
        displacement = 0;
    }

	float midpoint_value =  (line_shape[begin] + line_shape[end]) / 2 + displacement;
	int midpoint = (end+begin)/2;

	if(midpoint_value > length-1) {
		midpoint_value = length-1;
	}
	else if(midpoint_value < 0) {
		midpoint_value = 0;
	}
	line_shape[midpoint] = midpoint_value;
	range /= 2;  
	if(midpoint - begin > 1) {
		shape(begin, midpoint, length, range, line_shape);
	}
	if(end - midpoint > 1) {
		shape(midpoint, end, length, range, line_shape);
	}
}

/**
 * @brief Sub-rotina responsável por pintar a montanha
 *
 * Preenche os as células da matriz cujos indices da linha forem menores que os respectivos
 * 
 * valores no vetor de altitude
 * @param length            tamanho da matriz que representa a imagem
 * @param malha[][]         matriz de registros do tipo PIXEL, onde cada célula representa uma cor no formato RGB
 * @param line_shape[]      vetor que armazena as altitudes que a montanha alcança
 * @param moment            momento que a imagem será gerada, importante para definir a cor da montanha
 * @param mountain_number   número da montanha que está sendo criada
*/
void mountain(int length, PIXEL malha[length][length], float line_shape[length], enum Moment moment, int *mountain_number){
	int i, j;
    int rgb[3];

    if(moment == MORNING){
        if(*mountain_number == 0){
            rgb[0] = 48;
            rgb[1] = 34;
            rgb[2] = 19;
            *mountain_number += 1;
        } else {
            rgb[0] = 29;
            rgb[1] = 66;
            rgb[2] = 19;
        }
    } else if((moment == AFTERNOON) || (moment == EVENING)){
        rgb[0] = 0;
        rgb[1] = 0;
        rgb[2] = 0;
    }

    for(i = 0; i < length; ++i){
		for(j = 0; j < length; ++j){
			if(i >= line_shape[j]){
                malha[i][j].r = rgb[0];
                malha[i][j].g = rgb[1];
                malha[i][j].b = rgb[2];                    
			}
		}	
	}
}

/**
 * @brief Sub-rotina que define valores válidos para o procedimento -m  
 *
 * Verifica se o valor para o parâmetro -m (responsável por definir o momento em que a imagem é gerada) 
 * inserido pelo usuário é válido (1~3), senão, encontra um equivalente
 *
 * @param moment_input  valor inserido pelo usuário na linha de código para o parâmetro -m
*/
enum Moment convert_moment(int moment_input){
    enum Moment moment;
    int temporally = moment_input;

    if(temporally > 0 && temporally <= 3){
        if(temporally == 1){
            moment = MORNING;
        } else if(temporally == 2){
            moment = AFTERNOON;
        } else if(temporally == 3){
            moment = EVENING;
        }    
    } else {
        srand((unsigned) time(NULL));
        temporally = rand() % 3 + 1;
        moment = convert_moment(temporally);
    }
    return moment;
}

/**
 * @brief Sub-rotina que decide os valores para os parâmetros -d e -l de acordo com os valores de entrada
 *
 * Verifica se valores foram que inseridos para os parâmetros -d e -l, caso não, são definidos 
 * valores default. Se apenas um dos dois valores foi informado, o programa encontra 
 * um valor favorável para o outro
 *
 * @param parameter_d   variável que diz se algum valor foi inserido para o parâmetro -d
 * @param range         fator deslocamento 
 * @parameter_l         variável que diz se algum valor foi inserido para o parâmetro -l
 * @param length        tamanho da matriz que representa a imagem
*/
void verify_range_length(int parameter_d, int *range, int parameter_l, int *length){
    
    if(parameter_d == 0 && parameter_l == 0){
        *range = 100;
        *length = 513;
    } else if(parameter_d == 0){
        *range = (*length*100)/513;
    } else if(parameter_l == 0){
        *length = (*range*513)/100;
    }
}

/**
 * @brief Sub-rotina responsável por escrever a matriz num arquivo
 *
 * De acordo com o nome do arquivo que foi definido arteriormente,
 * ele é criado e recebe os valores da matriz e resulta na imagem
 *
 * @param column    número de colunas da matriz
 * @param line      número de linhas da matriz
 * @param malha[][] matriz de registros do tipo PIXEL, onde cada célula representa uma cor no formato RGB
 * @filename        nome do arquivo onde a matriz será escrita
*/
void save(int column, int line, PIXEL malha[line][column], char *filename){
    int i, j;
    FILE *img;
    img = fopen(filename, "w");

    fprintf(img, "%s\n", "P3");
    fprintf(img, "%i %i\n", line, column);
    fprintf(img, "%i\n", 255);

    for(i = 0; i < line; i++){
        for(j = 0; j < column; j++){
            fprintf(img, "%i %i %i ", malha[i][j].r, malha[i][j].g, malha[i][j].b);
        }
        fprintf(img, "\n");
    }
}