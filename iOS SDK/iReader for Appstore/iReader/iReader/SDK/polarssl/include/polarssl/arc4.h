/**
 * \file arc4.h
 *
 * \brief The ARCFOUR stream cipher
 *
 *  Copyright (C) 2006-2014, ARM Limited, All Rights Reserved
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef POLARSSL_ARC4_H
#define POLARSSL_ARC4_H

#if !defined(POLARSSL_CONFIG_FILE)
#include "config.h"
using namespace FT_POLARSSL;
#else
#include POLARSSL_CONFIG_FILE
#endif

#include <stddef.h>

#if !defined(POLARSSL_ARC4_ALT)
// Regular implementation
//
namespace FT_POLARSSL {

/**
 * \brief          ARC4 context structure
 */
typedef struct
{
    int x;                      /*!< permutation index */
    int y;                      /*!< permutation index */
    unsigned char m[256];       /*!< permutation table */
}
arc4_context;

/**
 * \brief          Initialize ARC4 context
 *
 * \param ctx      ARC4 context to be initialized
 */
void arc4_init( arc4_context *ctx );

/**
 * \brief          Clear ARC4 context
 *
 * \param ctx      ARC4 context to be cleared
 */
void arc4_free( arc4_context *ctx );

/**
 * \brief          ARC4 key schedule
 *
 * \param ctx      ARC4 context to be setup
 * \param key      the secret key
 * \param keylen   length of the key, in bytes
 */
void arc4_setup( arc4_context *ctx, const unsigned char *key,
                 unsigned int keylen );

/**
 * \brief          ARC4 cipher function
 *
 * \param ctx      ARC4 context
 * \param length   length of the input data
 * \param input    buffer holding the input data
 * \param output   buffer for the output data
 *
 * \return         0 if successful
 */
int arc4_crypt( arc4_context *ctx, size_t length, const unsigned char *input,
                unsigned char *output );

}

#else  /* POLARSSL_ARC4_ALT */
#include "arc4_alt.h"
#endif /* POLARSSL_ARC4_ALT */

namespace FT_POLARSSL {

/**
 * \brief          Checkup routine
 *
 * \return         0 if successful, or 1 if the test failed
 */
int arc4_self_test( int verbose );

}

#endif /* arc4.h */
