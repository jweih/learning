#ifndef _BANK_SESSION_H_
#define _BANK_SESSION_H_


#include "../Public/JUtil.h"
#include "../Public/Socket.h"
#include "../Public/MD5.h"
#include "../Public/Idea.h"
#include "TransDetail.h"
#include <memory>
#include <map>
#include <list>
using namespace PUBLIC;


#define CMD_LOGIN							0x01
#define CMD_OPEN_ACCOUNT					0x02
#define CMD_DEPOSIT							0x03
#define CMD_WITHDRAW						0x04
#define CMD_TRANSFER						0x05
#define CMD_BALANCE_INQUIRY					0x06
#define CMD_CHANGE_PASSWORD					0x07
#define CMD_DAY_BILL						0x08
#define CMD_HISTORY_BILL					0x09
#define CMD_ACCOUNT_HISTORY_BILL			0x0A
#define CMD_CLOSE_ACCOUNT					0x0B


struct RequestHead{
	unsigned short cmd;
	unsigned short len;
};

struct ResponseHead{
	unsigned short cmd;
	unsigned short len;
	unsigned short cnt;
	unsigned short seq;
	unsigned short error_code;
	char error_msg[30];
};

struct RequestPack{
	RequestHead head;
	char buf[1];
};

struct ResponsePack{
	ResponseHead head;
	char buf[1];
};

class BankSession
{
public:
	BankSession();
	~BankSession();

	void SetAttribute(const string& k,const string& v);
	const string& GetAttribute(const string& k);

	void Send(const char* buf, size_t len);
	void Recv();
	void Clear();

	void SetErrorCode(int16 errorCode){
		errorCode_ = errorCode;
	}
	int16 GetErrorCode()const{
		return errorCode_;
	}
	void SetErrorMsg(const string& errorMsg){
		errorMsg_ = errorMsg;
	}
	const string& GetErrorMsg()const{
		return errorMsg_;
	}
	uint16 GetCmd()const{
		return cmd_;
	}
	void SetCmd(uint16 cmd){
		cmd_ = cmd;
	}
	ResponsePack* GetResponsePack()const{
		return responsePack_;
	}
	void SetResponse(const string& k, const string& v);
	const string& GetResponse(const string& k);
	void AddDetail(const TransDetail& detail)
	{
		details_.push_back(detail);
	}
	list<TransDetail>& GetDetails()
	{
		return details_;
	}
private:
	std::auto_ptr<Socket> socket_;
	char buffer_[2048];
	ResponsePack* responsePack_;

	uint16 cmd_;
	map<string,string>request_;
	map<string,string>response_;
	int16 errorCode_;
	string errorMsg_;
	list<TransDetail> details_;
};


#endif //_BANK_SESSION_H_