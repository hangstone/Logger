/* soapProxy.cpp
   Generated by gSOAP 2.8.17r from Markisa.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "stdafx.h"
#include "soapProxy.h"

Proxy::Proxy()
{	Proxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

Proxy::Proxy(const struct soap &_soap) : soap(_soap)
{ }

Proxy::Proxy(const char *url)
{	Proxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

Proxy::Proxy(soap_mode iomode)
{	Proxy_init(iomode, iomode);
}

Proxy::Proxy(const char *url, soap_mode iomode)
{	Proxy_init(iomode, iomode);
	soap_endpoint = url;
}

Proxy::Proxy(soap_mode imode, soap_mode omode)
{	Proxy_init(imode, omode);
}

Proxy::~Proxy()
{ }

void Proxy::Proxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"wreq", "http://tempuri.org/wreq.xsd", NULL, NULL},
	{"wres", "http://tempuri.org/wres.xsd", NULL, NULL},
	{"rreq", "http://tempuri.org/rreq.xsd", NULL, NULL},
	{"rres", "http://tempuri.org/rres.xsd", NULL, NULL},
	{"frreq", "http://tempuri.org/frreq.xsd", NULL, NULL},
	{"frres", "http://tempuri.org/frres.xsd", NULL, NULL},
	{"wlreq", "http://tempuri.org/wlreq.xsd", NULL, NULL},
	{"wlres", "http://tempuri.org/wlres.xsd", NULL, NULL},
	{"rlreq", "http://tempuri.org/rlreq.xsd", NULL, NULL},
	{"rlres", "http://tempuri.org/rlres.xsd", NULL, NULL},
	{"fsreq", "http://tempuri.org/fsreq.xsd", NULL, NULL},
	{"fsres", "http://tempuri.org/fsres.xsd", NULL, NULL},
	{"csreq", "http://tempuri.org/csreq.xsd", NULL, NULL},
	{"csres", "http://tempuri.org/csres.xsd", NULL, NULL},
	{"hangpacs", "http://tempuri.org/hangpacs.xsd", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void Proxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void Proxy::reset()
{	destroy();
	soap_done(this);
	soap_initialize(this);
	Proxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void Proxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *Proxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *Proxy::soap_fault()
{	return this->fault;
}

const char *Proxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *Proxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int Proxy::soap_close_socket()
{	return soap_closesock(this);
}

int Proxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void Proxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void Proxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *Proxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int Proxy::WriteRequest(const char *endpoint, const char *soap_action, struct wreq__WriteRequest stReqMsg, struct wres__WriteResponse *stRspMsg)
{	struct soap *soap = this;
	struct hangpacs__WriteRequest soap_tmp_hangpacs__WriteRequest;
	if (endpoint)
		soap_endpoint = endpoint;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_hangpacs__WriteRequest.stReqMsg = stReqMsg;
	soap_serializeheader(soap);
	soap_serialize_hangpacs__WriteRequest(soap, &soap_tmp_hangpacs__WriteRequest);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_hangpacs__WriteRequest(soap, &soap_tmp_hangpacs__WriteRequest, "hangpacs:WriteRequest", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_hangpacs__WriteRequest(soap, &soap_tmp_hangpacs__WriteRequest, "hangpacs:WriteRequest", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!stRspMsg)
		return soap_closesock(soap);
	soap_default_wres__WriteResponse(soap, stRspMsg);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_wres__WriteResponse(soap, stRspMsg, "wres:WriteResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int Proxy::ReadRequest(const char *endpoint, const char *soap_action, struct rreq__ReadRequest stReqMsg, struct rres__CReadResponse *stRspMsg)
{	struct soap *soap = this;
	struct hangpacs__ReadRequest soap_tmp_hangpacs__ReadRequest;
	if (endpoint)
		soap_endpoint = endpoint;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_hangpacs__ReadRequest.stReqMsg = stReqMsg;
	soap_serializeheader(soap);
	soap_serialize_hangpacs__ReadRequest(soap, &soap_tmp_hangpacs__ReadRequest);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_hangpacs__ReadRequest(soap, &soap_tmp_hangpacs__ReadRequest, "hangpacs:ReadRequest", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_hangpacs__ReadRequest(soap, &soap_tmp_hangpacs__ReadRequest, "hangpacs:ReadRequest", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!stRspMsg)
		return soap_closesock(soap);
	soap_default_rres__CReadResponse(soap, stRspMsg);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_rres__CReadResponse(soap, stRspMsg, "rres:CReadResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int Proxy::RefreshRequest(const char *endpoint, const char *soap_action, struct rreq__RefreshRequest stReqMsg, struct rres__RefreshResponse *stRspMsg)
{	struct soap *soap = this;
	struct hangpacs__RefreshRequest soap_tmp_hangpacs__RefreshRequest;
	if (endpoint)
		soap_endpoint = endpoint;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_hangpacs__RefreshRequest.stReqMsg = stReqMsg;
	soap_serializeheader(soap);
	soap_serialize_hangpacs__RefreshRequest(soap, &soap_tmp_hangpacs__RefreshRequest);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_hangpacs__RefreshRequest(soap, &soap_tmp_hangpacs__RefreshRequest, "hangpacs:RefreshRequest", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_hangpacs__RefreshRequest(soap, &soap_tmp_hangpacs__RefreshRequest, "hangpacs:RefreshRequest", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!stRspMsg)
		return soap_closesock(soap);
	soap_default_rres__RefreshResponse(soap, stRspMsg);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_rres__RefreshResponse(soap, stRspMsg, "rres:RefreshResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int Proxy::FindReceiver(const char *endpoint, const char *soap_action, struct frreq__FindReceiverRequest stReqMsg, struct frres__FindReceiverResponse *stRspMsg)
{	struct soap *soap = this;
	struct hangpacs__FindReceiver soap_tmp_hangpacs__FindReceiver;
	if (endpoint)
		soap_endpoint = endpoint;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_hangpacs__FindReceiver.stReqMsg = stReqMsg;
	soap_serializeheader(soap);
	soap_serialize_hangpacs__FindReceiver(soap, &soap_tmp_hangpacs__FindReceiver);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_hangpacs__FindReceiver(soap, &soap_tmp_hangpacs__FindReceiver, "hangpacs:FindReceiver", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_hangpacs__FindReceiver(soap, &soap_tmp_hangpacs__FindReceiver, "hangpacs:FindReceiver", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!stRspMsg)
		return soap_closesock(soap);
	soap_default_frres__FindReceiverResponse(soap, stRspMsg);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_frres__FindReceiverResponse(soap, stRspMsg, "frres:FindReceiverResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int Proxy::WriteLog(const char *endpoint, const char *soap_action, struct wlreq__WriteLogRequest stReqMsg, struct wlres__WriteLogResponse *stRspMsg)
{	struct soap *soap = this;
	struct hangpacs__WriteLog soap_tmp_hangpacs__WriteLog;
	if (endpoint)
		soap_endpoint = endpoint;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_hangpacs__WriteLog.stReqMsg = stReqMsg;
	soap_serializeheader(soap);
	soap_serialize_hangpacs__WriteLog(soap, &soap_tmp_hangpacs__WriteLog);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_hangpacs__WriteLog(soap, &soap_tmp_hangpacs__WriteLog, "hangpacs:WriteLog", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_hangpacs__WriteLog(soap, &soap_tmp_hangpacs__WriteLog, "hangpacs:WriteLog", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!stRspMsg)
		return soap_closesock(soap);
	soap_default_wlres__WriteLogResponse(soap, stRspMsg);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_wlres__WriteLogResponse(soap, stRspMsg, "wlres:WriteLogResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int Proxy::send_WriteLogAsync(const char *endpoint, const char *soap_action, struct wlreq__WriteLogRequest stReqMsg)
{	struct soap *soap = this;
	struct hangpacs__WriteLogAsync soap_tmp_hangpacs__WriteLogAsync;
	if (endpoint)
		soap_endpoint = endpoint;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_hangpacs__WriteLogAsync.stReqMsg = stReqMsg;
	soap_serializeheader(soap);
	soap_serialize_hangpacs__WriteLogAsync(soap, &soap_tmp_hangpacs__WriteLogAsync);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_hangpacs__WriteLogAsync(soap, &soap_tmp_hangpacs__WriteLogAsync, "hangpacs:WriteLogAsync", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_hangpacs__WriteLogAsync(soap, &soap_tmp_hangpacs__WriteLogAsync, "hangpacs:WriteLogAsync", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

int Proxy::recv_WriteLogAsync(struct hangpacs__WriteLogAsync& tmp)
{	struct soap *soap = this;

	struct hangpacs__WriteLogAsync *_param_1 = &tmp;
	soap_default_hangpacs__WriteLogAsync(soap, _param_1);
	soap_begin(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_hangpacs__WriteLogAsync(soap, _param_1, "hangpacs:WriteLogAsync", NULL);
	if (soap->error == SOAP_TAG_MISMATCH && soap->level == 2)
		soap->error = SOAP_OK;
	if (soap->error
	 || soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int Proxy::ReadLog(const char *endpoint, const char *soap_action, struct rlreq__ReadLogRequest stReqMsg, struct rlres__CReadLogResponse *stRspMsg)
{	struct soap *soap = this;
	struct hangpacs__ReadLog soap_tmp_hangpacs__ReadLog;
	if (endpoint)
		soap_endpoint = endpoint;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_hangpacs__ReadLog.stReqMsg = stReqMsg;
	soap_serializeheader(soap);
	soap_serialize_hangpacs__ReadLog(soap, &soap_tmp_hangpacs__ReadLog);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_hangpacs__ReadLog(soap, &soap_tmp_hangpacs__ReadLog, "hangpacs:ReadLog", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_hangpacs__ReadLog(soap, &soap_tmp_hangpacs__ReadLog, "hangpacs:ReadLog", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!stRspMsg)
		return soap_closesock(soap);
	soap_default_rlres__CReadLogResponse(soap, stRspMsg);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_rlres__CReadLogResponse(soap, stRspMsg, "rlres:CReadLogResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int Proxy::FindStation(const char *endpoint, const char *soap_action, struct fsreq__FindStationRequest stReqMsg, struct fsres__CFindStationResponse *stRspMsg)
{	struct soap *soap = this;
	struct hangpacs__FindStation soap_tmp_hangpacs__FindStation;
	if (endpoint)
		soap_endpoint = endpoint;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_hangpacs__FindStation.stReqMsg = stReqMsg;
	soap_serializeheader(soap);
	soap_serialize_hangpacs__FindStation(soap, &soap_tmp_hangpacs__FindStation);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_hangpacs__FindStation(soap, &soap_tmp_hangpacs__FindStation, "hangpacs:FindStation", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_hangpacs__FindStation(soap, &soap_tmp_hangpacs__FindStation, "hangpacs:FindStation", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!stRspMsg)
		return soap_closesock(soap);
	soap_default_fsres__CFindStationResponse(soap, stRspMsg);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_fsres__CFindStationResponse(soap, stRspMsg, "fsres:CFindStationResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int Proxy::CommandStation(const char *endpoint, const char *soap_action, struct csreq__CommandStationRequest stReqMsg, struct csres__CommandStationResponse *stRspMsg)
{	struct soap *soap = this;
	struct hangpacs__CommandStation soap_tmp_hangpacs__CommandStation;
	if (endpoint)
		soap_endpoint = endpoint;
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_hangpacs__CommandStation.stReqMsg = stReqMsg;
	soap_serializeheader(soap);
	soap_serialize_hangpacs__CommandStation(soap, &soap_tmp_hangpacs__CommandStation);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_hangpacs__CommandStation(soap, &soap_tmp_hangpacs__CommandStation, "hangpacs:CommandStation", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_hangpacs__CommandStation(soap, &soap_tmp_hangpacs__CommandStation, "hangpacs:CommandStation", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!stRspMsg)
		return soap_closesock(soap);
	soap_default_csres__CommandStationResponse(soap, stRspMsg);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_csres__CommandStationResponse(soap, stRspMsg, "csres:CommandStationResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
