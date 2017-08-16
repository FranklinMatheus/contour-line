/**
 * @file moment.h
 * @author Franklin Matheus e Leonardo Santos
 * @date 29/11/2016
 * @brief Arquivo que define o enum Moment
 */

#ifndef __MOMENT_H__
#define __MOMENT_H__

    /**
     * @brief Enumeraçãoes que representam os momentos do dia que a imagem pode ser gerada
    */
    enum Moment {
        MORNING = 1, /**< Referente à manhã */
        AFTERNOON, /**< Referente à tarde */
        EVENING /**< Referente à noite */
    };
    
#endif