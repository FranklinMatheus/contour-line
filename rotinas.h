/**
 * @file rotinas.h
 * @author Franklin Matheus e Leonardo Santos
 * @date 29/11/2016
 * @brief Arquivo que contém as assinaturas das sub-rotinas
 */

#ifndef __ROTINAS_H__
#define __ROTINAS_H__

    #include "pixel.h"
    #include "moment.h"
    
    void sky(int line, int column, PIXEL malha[line][column], enum Moment moment);
    void stars(int line, int column, PIXEL malha[line][column]);
    void shape(int begin, int end, int length, int range, float line_shape[length]);
    void mountain(int length, PIXEL malha[length][length], float line_shape[length], enum Moment moment, int *mountain_number);
    enum Moment convert_moment(int moment_input);
    void verify_range_length(int parameter_d, int *range, int parameter_l, int *length);
    void save(int column, int line, PIXEL malha[line][column], char *filename);

#endif