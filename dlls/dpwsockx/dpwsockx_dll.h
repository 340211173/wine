/*
 * Copyright 2008 Ismael Barros Barros
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_DPWSOCKX_DLL_H
#define __WINE_DPWSOCKX_DLL_H

#include "windef.h"
#include "winbase.h"
#include "winsock2.h"
#include "winnt.h"
#include "wine/dplaysp.h"


#define DPWS_MAXQUEUESIZE             0
#define DPWS_HUNDREDBAUD              0
#define DPWS_LATENCY                  500
#define DPWS_MAXLOCALPLAYERS          65536
#define DPWS_TIMEOUT                  5000
#define DPWS_MAXBUFFERSIZE            65507
#define DPWS_MAXPLAYERS               65536
#define DPWS_GUARANTEED_MAXBUFFERSIZE 1048575
#define DPWS_GUARANTEED_MAXPLAYERS    64

#define DPWS_PORT_RANGE_START 2300
#define DPWS_PORT_RANGE_END   2400
#define DPWS_DPLAYSRV_PORT    47624



typedef struct tagDPWS_THREADDATA
{
    BOOL           is_running;
    SOCKET         sock;
    SOCKADDR_IN    addr;
    HANDLE         handle;
    LPDIRECTPLAYSP lpISP;
} DPWS_THREADDATA, *LPDPWS_THREADDATA;

typedef struct tagDPWS_DATA
{
    SOCKET          sock;
    DPWS_THREADDATA tcp_listener, udp_listener, dplaysrv;
    SOCKADDR_IN     nameserverAddr;
    LPDIRECTPLAYSP  lpISP;
} DPWS_DATA, *LPDPWS_DATA;

typedef struct tagDPWS_PLAYER_DATA
{
    SOCKADDR_IN tcpAddr;
    SOCKADDR_IN udpAddr;
} DPWS_PLAYER_DATA, *LPDPWS_PLAYER_DATA;

typedef struct tagDPSP_MSG_HEADER
{
    DWORD       size;           /* size & 0x000FFFFF, token & 0xFFF00000 */
    SOCKADDR_IN SockAddr;
} DPSP_MSG_HEADER, *LPDPSP_MSG_HEADER;
typedef const DPSP_MSG_HEADER* LPCDPSP_MSG_HEADER;

/* DPSP_MSG_HEADER->token */
#define DPSP_MSG_TOKEN_REMOTE    0xFAB00000
#define DPSP_MSG_TOKEN_FORWARDED 0xCAB00000
#define DPSP_MSG_TOKEN_SERVER    0xBAB00000


HRESULT WINAPI SPInit( LPSPINITDATA );

#endif	/* __WINE_DPWSOCKX_DLL_H */
