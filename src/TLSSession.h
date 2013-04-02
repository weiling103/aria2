/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2013 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef TLS_SESSION_H
#define TLS_SESSION_H

#include "common.h"

// To create another SSL/TLS backend, implement TLSSession class below.
//
// class TLSSession {
// public:
//   TLSSession(TLSContext* tlsContext);
//
//   // MUST deallocate all resources
//   ~TLSSession();
//
//   // Initializes SSL/TLS session. The |sockfd| is the underlying
//   // tranport socket. This function returns TLS_ERR_OK if it
//   // succeeds, or TLS_ERR_ERROR.
//   int init(sock_t sockfd);
//
//   // Sets |hostname| for TLS SNI extension. This is only meaningful for
//   // client side session. This function returns TLS_ERR_OK if it
//   // succeeds, or TLS_ERR_ERROR.
//   int setSNIHostname(const std::string& hostname);
//
//   // Closes the SSL/TLS session. Don't close underlying transport
//   // socket. This function returns TLS_ERR_OK if it succeeds, or
//   // TLS_ERR_ERROR.
//   int closeConnection();
//
//   // Returns TLS_WANT_READ if SSL/TLS session needs more data from
//   // remote endpoint to proceed, or TLS_WANT_WRITE if SSL/TLS session
//   // needs to write more data to proceed. If SSL/TLS session needs
//   // neither read nor write data at the moment, return value is
//   // undefined.
//   int checkDirection();
//
//   // Sends |data| with length |len|. This function returns the number
//   // of bytes sent if it succeeds, or TLS_ERR_WOULDBLOCK if the
//   // underlying tranport blocks, or TLS_ERR_ERROR.
//   ssize_t writeData(const void* data, size_t len);
//
//   // Receives data into |data| with length |len|. This function returns
//   // the number of bytes received if it succeeds, or TLS_ERR_WOULDBLOCK
//   // if the underlying tranport blocks, or TLS_ERR_ERROR.
//   ssize_t readData(void* data, size_t len);
//
//   // Performs client side handshake. The |hostname| is the hostname of
//   // the remote endpoint and is used to verify its certificate. This
//   // function returns TLS_ERR_OK if it succeeds, or TLS_ERR_WOULDBLOCK
//   // if the underlying transport blocks, or TLS_ERR_ERROR.
//   // When returning TLS_ERR_ERROR, provide certificate validation error
//   // in |handshakeErr|.
//   int tlsConnect(const std::string& hostname, std::string& handshakeErr);
//
//   // Performs server side handshake. This function returns TLS_ERR_OK
//   // if it succeeds, or TLS_ERR_WOULDBLOCK if the underlying transport
//   // blocks, or TLS_ERR_ERROR.
//   int tlsAccept();
//
//   // Returns last error string
//   std::string getLastErrorString();
// };

#ifdef HAVE_OPENSSL
# include "LibsslTLSSession.h"
#elif defined HAVE_LIBGNUTLS
# include "LibgnutlsTLSSession.h"
#endif

#endif // TLS_SESSION_H
