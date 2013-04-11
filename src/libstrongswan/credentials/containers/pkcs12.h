/*
 * Copyright (C) 2013 Tobias Brunner
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup pkcs12 pkcs12
 * @{ @ingroup containers
 */

#ifndef PKCS12_H_
#define PKCS12_H_

#include <crypto/hashers/hasher.h>

typedef enum pkcs12_key_type_t pkcs12_key_type_t;

/**
 * The types of password based keys used by PKCS#12.
 */
enum pkcs12_key_type_t {
	PKCS12_KEY_ENCRYPTION = 1,
	PKCS12_KEY_IV = 2,
	PKCS12_KEY_MAC = 3,
};

/**
 * Derive the keys used in PKCS#12 for password integrity/privacy mode.
 *
 * @param hash			hash algorithm to use for key derivation
 * @param password		password (ASCII)
 * @param salt			salt value
 * @param iterations	number of iterations
 * @param type			type of key to derive
 * @param key			the returned key, must be allocated of desired length
 * @return				TRUE on success
 */
bool pkcs12_derive_key(hash_algorithm_t hash, chunk_t password, chunk_t salt,
					u_int64_t iterations, pkcs12_key_type_t type, chunk_t key);

#endif /** PKCS12_H_ @}*/
