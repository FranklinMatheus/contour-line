/**
 * @file pixel.h
 * @author Franklin Matheus e Leonardo Santos
 * @date 29/11/2016
 * @brief Arquivo que define o registro do tipo PIXEL
 */

#ifndef __PIXEL_H__
#define __PIXEL_H__

    /**
     * @brief Registro que define a cor de um pixel no formato RGB
    */
    typedef struct{
        int r; /**< Variável referente ao valor da cor vermelha. */ 
        int g; /**< Variável referente ao valor da cor verde. */
        int b; /**< Variável referente ao valor da cor azul. */
    } PIXEL;

#endif