/* soapStub.h
   Generated by gSOAP 2.8.17r from Markisa.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapStub_H
#define soapStub_H
#include <vector>
#include <list>
#include "stdsoap2.h"
#if GSOAP_VERSION != 20817
# error "GSOAP VERSION MISMATCH IN GENERATED CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


#ifndef SOAP_TYPE_Processing
#define SOAP_TYPE_Processing (9)
/* Processing */
enum Processing { hangpacs__Begin = 0, hangpacs__Processing = 1, hangpacs__end = 2 };
#endif

#ifndef SOAP_TYPE_CommandStation
#define SOAP_TYPE_CommandStation (63)
/* CommandStation */
enum CommandStation { hangpacs__Stop = 0, hangpacs__Start = 1 };
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_WriteRequest
#define SOAP_TYPE_WriteRequest (11)
/* WriteRequest */
struct WriteRequest
{
public:
	std::wstring strCallingAETtile;	/* required element of type xsd:string */
	std::wstring strCalledAETitle;	/* required element of type xsd:string */
	std::wstring strPatientID;	/* required element of type xsd:string */
	std::wstring strPatientName;	/* required element of type xsd:string */
	std::wstring strProtocol;	/* required element of type xsd:string */
	std::wstring strSOPClassName;	/* required element of type xsd:string */
	int nNumOfInstance;	/* required element of type xsd:int */
	enum Processing eStatus;	/* required element of type hangpacs:Processing */
public:
	int soap_type() const { return 11; } /* = unique type id SOAP_TYPE_WriteRequest */
};
#endif

#ifndef SOAP_TYPE_wreq__WriteRequest
#define SOAP_TYPE_wreq__WriteRequest (14)
/* wreq:WriteRequest */
struct wreq__WriteRequest
{
public:
	struct WriteRequest return_;	/* required element of type wreq:WriteRequest */
public:
	int soap_type() const { return 14; } /* = unique type id SOAP_TYPE_wreq__WriteRequest */
};
#endif

#ifndef SOAP_TYPE_WriteResponse
#define SOAP_TYPE_WriteResponse (15)
/* WriteResponse */
struct WriteResponse
{
public:
	bool bDummy;	/* required element of type xsd:boolean */
public:
	int soap_type() const { return 15; } /* = unique type id SOAP_TYPE_WriteResponse */
};
#endif

#ifndef SOAP_TYPE_wres__WriteResponse
#define SOAP_TYPE_wres__WriteResponse (18)
/* wres:WriteResponse */
struct wres__WriteResponse
{
public:
	struct WriteResponse return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type wres:WriteResponse */
public:
	int soap_type() const { return 18; } /* = unique type id SOAP_TYPE_wres__WriteResponse */
};
#endif

#ifndef SOAP_TYPE_ReadRequest
#define SOAP_TYPE_ReadRequest (19)
/* ReadRequest */
struct ReadRequest
{
public:
	bool bDummy;	/* required element of type xsd:boolean */
public:
	int soap_type() const { return 19; } /* = unique type id SOAP_TYPE_ReadRequest */
};
#endif

#ifndef SOAP_TYPE_rreq__ReadRequest
#define SOAP_TYPE_rreq__ReadRequest (21)
/* rreq:ReadRequest */
struct rreq__ReadRequest
{
public:
	struct ReadRequest return_;	/* required element of type rreq:ReadRequest */
public:
	int soap_type() const { return 21; } /* = unique type id SOAP_TYPE_rreq__ReadRequest */
};
#endif

#ifndef SOAP_TYPE_ReadResponse
#define SOAP_TYPE_ReadResponse (22)
/* ReadResponse */
struct ReadResponse
{
public:
	std::wstring strCallingAETtile;	/* required element of type xsd:string */
	std::wstring strCalledAETitle;	/* required element of type xsd:string */
	std::wstring strPatientID;	/* required element of type xsd:string */
	std::wstring strPatientName;	/* required element of type xsd:string */
	std::wstring strProtocol;	/* required element of type xsd:string */
	std::wstring strSOPClassName;	/* required element of type xsd:string */
	int nNumOfInstance;	/* required element of type xsd:int */
	enum Processing eStatus;	/* required element of type hangpacs:Processing */
public:
	int soap_type() const { return 22; } /* = unique type id SOAP_TYPE_ReadResponse */
};
#endif

#ifndef SOAP_TYPE_rres__ReadResponse
#define SOAP_TYPE_rres__ReadResponse (24)
/* rres:ReadResponse */
struct rres__ReadResponse
{
public:
	struct ReadResponse return_;	/* required element of type rres:ReadResponse */
public:
	int soap_type() const { return 24; } /* = unique type id SOAP_TYPE_rres__ReadResponse */
};
#endif

#ifndef SOAP_TYPE__rres__CReadResponse
#define SOAP_TYPE__rres__CReadResponse (25)
/* rres:CReadResponse */
class SOAP_CMAC _rres__CReadResponse
{
public:
	std::list<struct ReadResponse >m_listResponse;	/* optional element of type rres:ReadResponse */
public:
	virtual int soap_type() const { return 25; } /* = unique type id SOAP_TYPE__rres__CReadResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _rres__CReadResponse() { _rres__CReadResponse::soap_default(NULL); }
	virtual ~_rres__CReadResponse() { }
};
#endif

#ifndef SOAP_TYPE_rres__CReadResponse
#define SOAP_TYPE_rres__CReadResponse (27)
/* rres:CReadResponse */
struct rres__CReadResponse
{
public:
	_rres__CReadResponse return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type rres:CReadResponse */
public:
	int soap_type() const { return 27; } /* = unique type id SOAP_TYPE_rres__CReadResponse */
};
#endif

#ifndef SOAP_TYPE_RefresRequest
#define SOAP_TYPE_RefresRequest (28)
/* RefresRequest */
struct RefresRequest
{
public:
	int nInterval;	/* required element of type xsd:int */
public:
	int soap_type() const { return 28; } /* = unique type id SOAP_TYPE_RefresRequest */
};
#endif

#ifndef SOAP_TYPE_rreq__RefreshRequest
#define SOAP_TYPE_rreq__RefreshRequest (30)
/* rreq:RefreshRequest */
struct rreq__RefreshRequest
{
public:
	struct RefresRequest retrun_;	/* required element of type rreq-RefresRequest */
public:
	int soap_type() const { return 30; } /* = unique type id SOAP_TYPE_rreq__RefreshRequest */
};
#endif

#ifndef SOAP_TYPE_RefreshResponse
#define SOAP_TYPE_RefreshResponse (31)
/* RefreshResponse */
struct RefreshResponse
{
public:
	bool bDummy;	/* required element of type xsd:boolean */
public:
	int soap_type() const { return 31; } /* = unique type id SOAP_TYPE_RefreshResponse */
};
#endif

#ifndef SOAP_TYPE_rres__RefreshResponse
#define SOAP_TYPE_rres__RefreshResponse (33)
/* rres:RefreshResponse */
struct rres__RefreshResponse
{
public:
	struct RefreshResponse return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type rres-RefreshResponse */
public:
	int soap_type() const { return 33; } /* = unique type id SOAP_TYPE_rres__RefreshResponse */
};
#endif

#ifndef SOAP_TYPE_FindReceiverRequest
#define SOAP_TYPE_FindReceiverRequest (34)
/* FindReceiverRequest */
struct FindReceiverRequest
{
public:
	bool bDummy;	/* required element of type xsd:boolean */
public:
	int soap_type() const { return 34; } /* = unique type id SOAP_TYPE_FindReceiverRequest */
};
#endif

#ifndef SOAP_TYPE_frreq__FindReceiverRequest
#define SOAP_TYPE_frreq__FindReceiverRequest (36)
/* frreq:FindReceiverRequest */
struct frreq__FindReceiverRequest
{
public:
	struct FindReceiverRequest return_;	/* required element of type frreq-FindReceiverRequest */
public:
	int soap_type() const { return 36; } /* = unique type id SOAP_TYPE_frreq__FindReceiverRequest */
};
#endif

#ifndef SOAP_TYPE_FindReceiverResponse
#define SOAP_TYPE_FindReceiverResponse (37)
/* FindReceiverResponse */
struct FindReceiverResponse
{
public:
	std::list<std::wstring >lstResponse;	/* optional element of type xsd:string */
public:
	int soap_type() const { return 37; } /* = unique type id SOAP_TYPE_FindReceiverResponse */
};
#endif

#ifndef SOAP_TYPE_frres__FindReceiverResponse
#define SOAP_TYPE_frres__FindReceiverResponse (40)
/* frres:FindReceiverResponse */
struct frres__FindReceiverResponse
{
public:
	struct FindReceiverResponse return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type frres-FindReceiverResponse */
public:
	int soap_type() const { return 40; } /* = unique type id SOAP_TYPE_frres__FindReceiverResponse */
};
#endif

#ifndef SOAP_TYPE_WriteLogRequest
#define SOAP_TYPE_WriteLogRequest (41)
/* WriteLogRequest */
struct WriteLogRequest
{
public:
	std::wstring strAETitle;	/* required element of type xsd:string */
	std::wstring strLog;	/* required element of type xsd:string */
public:
	int soap_type() const { return 41; } /* = unique type id SOAP_TYPE_WriteLogRequest */
};
#endif

#ifndef SOAP_TYPE_wlreq__WriteLogRequest
#define SOAP_TYPE_wlreq__WriteLogRequest (43)
/* wlreq:WriteLogRequest */
struct wlreq__WriteLogRequest
{
public:
	struct WriteLogRequest return_;	/* required element of type wlreq-WriteLogRequest */
public:
	int soap_type() const { return 43; } /* = unique type id SOAP_TYPE_wlreq__WriteLogRequest */
};
#endif

#ifndef SOAP_TYPE_WriteLogResponse
#define SOAP_TYPE_WriteLogResponse (44)
/* WriteLogResponse */
struct WriteLogResponse
{
public:
	bool bDummy;	/* required element of type xsd:boolean */
public:
	int soap_type() const { return 44; } /* = unique type id SOAP_TYPE_WriteLogResponse */
};
#endif

#ifndef SOAP_TYPE_wlres__WriteLogResponse
#define SOAP_TYPE_wlres__WriteLogResponse (46)
/* wlres:WriteLogResponse */
struct wlres__WriteLogResponse
{
public:
	struct WriteLogResponse return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type wlres-WriteLogResponse */
public:
	int soap_type() const { return 46; } /* = unique type id SOAP_TYPE_wlres__WriteLogResponse */
};
#endif

#ifndef SOAP_TYPE_ReadLogRequest
#define SOAP_TYPE_ReadLogRequest (47)
/* ReadLogRequest */
struct ReadLogRequest
{
public:
	std::wstring strAETitle;	/* required element of type xsd:string */
public:
	int soap_type() const { return 47; } /* = unique type id SOAP_TYPE_ReadLogRequest */
};
#endif

#ifndef SOAP_TYPE_rlreq__ReadLogRequest
#define SOAP_TYPE_rlreq__ReadLogRequest (49)
/* rlreq:ReadLogRequest */
struct rlreq__ReadLogRequest
{
public:
	struct ReadLogRequest return_;	/* required element of type rlreq-ReadLogRequest */
public:
	int soap_type() const { return 49; } /* = unique type id SOAP_TYPE_rlreq__ReadLogRequest */
};
#endif

#ifndef SOAP_TYPE_ReadLogResponse
#define SOAP_TYPE_ReadLogResponse (50)
/* ReadLogResponse */
struct ReadLogResponse
{
public:
	std::wstring strDate;	/* required element of type xsd:string */
	std::wstring strTime;	/* required element of type xsd:string */
	std::wstring strLevel;	/* required element of type xsd:string */
	std::wstring strFuncName;	/* required element of type xsd:string */
	std::wstring strMessage;	/* required element of type xsd:string */
public:
	int soap_type() const { return 50; } /* = unique type id SOAP_TYPE_ReadLogResponse */
};
#endif

#ifndef SOAP_TYPE__rlres__CReadLogResponse
#define SOAP_TYPE__rlres__CReadLogResponse (52)
/* rlres:CReadLogResponse */
class SOAP_CMAC _rlres__CReadLogResponse
{
public:
	std::list<struct ReadLogResponse >m_listResponse;	/* optional element of type rlres-ReadLogResponse */
public:
	virtual int soap_type() const { return 52; } /* = unique type id SOAP_TYPE__rlres__CReadLogResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _rlres__CReadLogResponse() { _rlres__CReadLogResponse::soap_default(NULL); }
	virtual ~_rlres__CReadLogResponse() { }
};
#endif

#ifndef SOAP_TYPE_rlres__CReadLogResponse
#define SOAP_TYPE_rlres__CReadLogResponse (54)
/* rlres:CReadLogResponse */
struct rlres__CReadLogResponse
{
public:
	_rlres__CReadLogResponse return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type rlres:CReadLogResponse */
public:
	int soap_type() const { return 54; } /* = unique type id SOAP_TYPE_rlres__CReadLogResponse */
};
#endif

#ifndef SOAP_TYPE_FindStationRequest
#define SOAP_TYPE_FindStationRequest (55)
/* FindStationRequest */
struct FindStationRequest
{
public:
	bool bDummy;	/* required element of type xsd:boolean */
public:
	int soap_type() const { return 55; } /* = unique type id SOAP_TYPE_FindStationRequest */
};
#endif

#ifndef SOAP_TYPE_fsreq__FindStationRequest
#define SOAP_TYPE_fsreq__FindStationRequest (57)
/* fsreq:FindStationRequest */
struct fsreq__FindStationRequest
{
public:
	struct FindStationRequest return_;	/* required element of type fsreq-FindStationRequest */
public:
	int soap_type() const { return 57; } /* = unique type id SOAP_TYPE_fsreq__FindStationRequest */
};
#endif

#ifndef SOAP_TYPE_FindStationResponse
#define SOAP_TYPE_FindStationResponse (58)
/* FindStationResponse */
struct FindStationResponse
{
public:
	std::wstring strIPAddress;	/* required element of type xsd:string */
	std::wstring strStationName;	/* required element of type xsd:string */
	std::wstring strStatus;	/* required element of type xsd:string */
public:
	int soap_type() const { return 58; } /* = unique type id SOAP_TYPE_FindStationResponse */
};
#endif

#ifndef SOAP_TYPE__fsres__CFindStationResponse
#define SOAP_TYPE__fsres__CFindStationResponse (60)
/* fsres:CFindStationResponse */
class SOAP_CMAC _fsres__CFindStationResponse
{
public:
	std::list<struct FindStationResponse >m_listResponse;	/* optional element of type fsres-FindStationResponse */
public:
	virtual int soap_type() const { return 60; } /* = unique type id SOAP_TYPE__fsres__CFindStationResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _fsres__CFindStationResponse() { _fsres__CFindStationResponse::soap_default(NULL); }
	virtual ~_fsres__CFindStationResponse() { }
};
#endif

#ifndef SOAP_TYPE_fsres__CFindStationResponse
#define SOAP_TYPE_fsres__CFindStationResponse (62)
/* fsres:CFindStationResponse */
struct fsres__CFindStationResponse
{
public:
	_fsres__CFindStationResponse return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type fsres:CFindStationResponse */
public:
	int soap_type() const { return 62; } /* = unique type id SOAP_TYPE_fsres__CFindStationResponse */
};
#endif

#ifndef SOAP_TYPE_CommandStationRequest
#define SOAP_TYPE_CommandStationRequest (65)
/* CommandStationRequest */
struct CommandStationRequest
{
public:
	enum CommandStation eCommand;	/* required element of type hangpacs:CommandStation */
	std::wstring strStationName;	/* required element of type xsd:string */
public:
	int soap_type() const { return 65; } /* = unique type id SOAP_TYPE_CommandStationRequest */
};
#endif

#ifndef SOAP_TYPE_csreq__CommandStationRequest
#define SOAP_TYPE_csreq__CommandStationRequest (67)
/* csreq:CommandStationRequest */
struct csreq__CommandStationRequest
{
public:
	struct CommandStationRequest retrun_;	/* required element of type csreq-CommandStationRequest */
public:
	int soap_type() const { return 67; } /* = unique type id SOAP_TYPE_csreq__CommandStationRequest */
};
#endif

#ifndef SOAP_TYPE_CommandStationResponse
#define SOAP_TYPE_CommandStationResponse (68)
/* CommandStationResponse */
struct CommandStationResponse
{
public:
	bool bDummy;	/* required element of type xsd:boolean */
public:
	int soap_type() const { return 68; } /* = unique type id SOAP_TYPE_CommandStationResponse */
};
#endif

#ifndef SOAP_TYPE_csres__CommandStationResponse
#define SOAP_TYPE_csres__CommandStationResponse (70)
/* csres:CommandStationResponse */
struct csres__CommandStationResponse
{
public:
	struct CommandStationResponse return_;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type csres-CommandStationResponse */
public:
	int soap_type() const { return 70; } /* = unique type id SOAP_TYPE_csres__CommandStationResponse */
};
#endif

#ifndef SOAP_TYPE_hangpacs__WriteRequest
#define SOAP_TYPE_hangpacs__WriteRequest (73)
/* hangpacs:WriteRequest */
struct hangpacs__WriteRequest
{
public:
	struct wreq__WriteRequest stReqMsg;	/* required element of type wreq:WriteRequest */
public:
	int soap_type() const { return 73; } /* = unique type id SOAP_TYPE_hangpacs__WriteRequest */
};
#endif

#ifndef SOAP_TYPE_hangpacs__ReadRequest
#define SOAP_TYPE_hangpacs__ReadRequest (76)
/* hangpacs:ReadRequest */
struct hangpacs__ReadRequest
{
public:
	struct rreq__ReadRequest stReqMsg;	/* required element of type rreq:ReadRequest */
public:
	int soap_type() const { return 76; } /* = unique type id SOAP_TYPE_hangpacs__ReadRequest */
};
#endif

#ifndef SOAP_TYPE_hangpacs__RefreshRequest
#define SOAP_TYPE_hangpacs__RefreshRequest (79)
/* hangpacs:RefreshRequest */
struct hangpacs__RefreshRequest
{
public:
	struct rreq__RefreshRequest stReqMsg;	/* required element of type rreq:RefreshRequest */
public:
	int soap_type() const { return 79; } /* = unique type id SOAP_TYPE_hangpacs__RefreshRequest */
};
#endif

#ifndef SOAP_TYPE_hangpacs__FindReceiver
#define SOAP_TYPE_hangpacs__FindReceiver (82)
/* hangpacs:FindReceiver */
struct hangpacs__FindReceiver
{
public:
	struct frreq__FindReceiverRequest stReqMsg;	/* required element of type frreq:FindReceiverRequest */
public:
	int soap_type() const { return 82; } /* = unique type id SOAP_TYPE_hangpacs__FindReceiver */
};
#endif

#ifndef SOAP_TYPE_hangpacs__WriteLog
#define SOAP_TYPE_hangpacs__WriteLog (85)
/* hangpacs:WriteLog */
struct hangpacs__WriteLog
{
public:
	struct wlreq__WriteLogRequest stReqMsg;	/* required element of type wlreq:WriteLogRequest */
public:
	int soap_type() const { return 85; } /* = unique type id SOAP_TYPE_hangpacs__WriteLog */
};
#endif

#ifndef SOAP_TYPE_hangpacs__WriteLogAsync
#define SOAP_TYPE_hangpacs__WriteLogAsync (88)
/* hangpacs:WriteLogAsync */
struct hangpacs__WriteLogAsync
{
public:
	struct wlreq__WriteLogRequest stReqMsg;	/* required element of type wlreq:WriteLogRequest */
public:
	int soap_type() const { return 88; } /* = unique type id SOAP_TYPE_hangpacs__WriteLogAsync */
};
#endif

#ifndef SOAP_TYPE_hangpacs__ReadLog
#define SOAP_TYPE_hangpacs__ReadLog (91)
/* hangpacs:ReadLog */
struct hangpacs__ReadLog
{
public:
	struct rlreq__ReadLogRequest stReqMsg;	/* required element of type rlreq:ReadLogRequest */
public:
	int soap_type() const { return 91; } /* = unique type id SOAP_TYPE_hangpacs__ReadLog */
};
#endif

#ifndef SOAP_TYPE_hangpacs__FindStation
#define SOAP_TYPE_hangpacs__FindStation (94)
/* hangpacs:FindStation */
struct hangpacs__FindStation
{
public:
	struct fsreq__FindStationRequest stReqMsg;	/* required element of type fsreq:FindStationRequest */
public:
	int soap_type() const { return 94; } /* = unique type id SOAP_TYPE_hangpacs__FindStation */
};
#endif

#ifndef SOAP_TYPE_hangpacs__CommandStation
#define SOAP_TYPE_hangpacs__CommandStation (97)
/* hangpacs:CommandStation */
struct hangpacs__CommandStation
{
public:
	struct csreq__CommandStationRequest stReqMsg;	/* required element of type csreq:CommandStationRequest */
public:
	int soap_type() const { return 97; } /* = unique type id SOAP_TYPE_hangpacs__CommandStation */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (98)
/* SOAP Header: */
struct SOAP_ENV__Header
{
public:
	int soap_type() const { return 98; } /* = unique type id SOAP_TYPE_SOAP_ENV__Header */
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (99)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
public:
	int soap_type() const { return 99; } /* = unique type id SOAP_TYPE_SOAP_ENV__Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (101)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
public:
	int soap_type() const { return 101; } /* = unique type id SOAP_TYPE_SOAP_ENV__Detail */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (103)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
public:
	int soap_type() const { return 103; } /* = unique type id SOAP_TYPE_SOAP_ENV__Reason */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (104)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
public:
	int soap_type() const { return 104; } /* = unique type id SOAP_TYPE_SOAP_ENV__Fault */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE__hangpacs__Processing
#define SOAP_TYPE__hangpacs__Processing (10)
typedef enum Processing _hangpacs__Processing;
#endif

#ifndef SOAP_TYPE__wreq__WriteRequest
#define SOAP_TYPE__wreq__WriteRequest (13)
typedef struct WriteRequest _wreq__WriteRequest;
#endif

#ifndef SOAP_TYPE__wres__WriteResponse
#define SOAP_TYPE__wres__WriteResponse (17)
typedef struct WriteResponse _wres__WriteResponse;
#endif

#ifndef SOAP_TYPE__rreq__ReadRequest
#define SOAP_TYPE__rreq__ReadRequest (20)
typedef struct ReadRequest _rreq__ReadRequest;
#endif

#ifndef SOAP_TYPE__rres__ReadResponse
#define SOAP_TYPE__rres__ReadResponse (23)
typedef struct ReadResponse _rres__ReadResponse;
#endif

#ifndef SOAP_TYPE__rreq_RefresRequest
#define SOAP_TYPE__rreq_RefresRequest (29)
typedef struct RefresRequest _rreq_RefresRequest;
#endif

#ifndef SOAP_TYPE__rres_RefreshResponse
#define SOAP_TYPE__rres_RefreshResponse (32)
typedef struct RefreshResponse _rres_RefreshResponse;
#endif

#ifndef SOAP_TYPE__frreq_FindReceiverRequest
#define SOAP_TYPE__frreq_FindReceiverRequest (35)
typedef struct FindReceiverRequest _frreq_FindReceiverRequest;
#endif

#ifndef SOAP_TYPE__frres_FindReceiverResponse
#define SOAP_TYPE__frres_FindReceiverResponse (39)
typedef struct FindReceiverResponse _frres_FindReceiverResponse;
#endif

#ifndef SOAP_TYPE__wlreq_WriteLogRequest
#define SOAP_TYPE__wlreq_WriteLogRequest (42)
typedef struct WriteLogRequest _wlreq_WriteLogRequest;
#endif

#ifndef SOAP_TYPE__wlres_WriteLogResponse
#define SOAP_TYPE__wlres_WriteLogResponse (45)
typedef struct WriteLogResponse _wlres_WriteLogResponse;
#endif

#ifndef SOAP_TYPE__rlreq_ReadLogRequest
#define SOAP_TYPE__rlreq_ReadLogRequest (48)
typedef struct ReadLogRequest _rlreq_ReadLogRequest;
#endif

#ifndef SOAP_TYPE__rlres_ReadLogResponse
#define SOAP_TYPE__rlres_ReadLogResponse (51)
typedef struct ReadLogResponse _rlres_ReadLogResponse;
#endif

#ifndef SOAP_TYPE__fsreq_FindStationRequest
#define SOAP_TYPE__fsreq_FindStationRequest (56)
typedef struct FindStationRequest _fsreq_FindStationRequest;
#endif

#ifndef SOAP_TYPE__fsres_FindStationResponse
#define SOAP_TYPE__fsres_FindStationResponse (59)
typedef struct FindStationResponse _fsres_FindStationResponse;
#endif

#ifndef SOAP_TYPE__hangpacs__CommandStation
#define SOAP_TYPE__hangpacs__CommandStation (64)
typedef enum CommandStation _hangpacs__CommandStation;
#endif

#ifndef SOAP_TYPE__csreq_CommandStationRequest
#define SOAP_TYPE__csreq_CommandStationRequest (66)
typedef struct CommandStationRequest _csreq_CommandStationRequest;
#endif

#ifndef SOAP_TYPE__csres_CommandStationResponse
#define SOAP_TYPE__csres_CommandStationResponse (69)
typedef struct CommandStationResponse _csres_CommandStationResponse;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


#endif

/* End of soapStub.h */
