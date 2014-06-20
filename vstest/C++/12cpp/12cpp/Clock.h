//#pragma once
#ifndef _CLOCK_H_
#define _CLOCK_H_
class Clock{
public:
	Clock(int hour=0,int minute=0,int second=0);
	~Clock();
	void Display();
	void Init(int hour,int minute,int second);
	void Update();

	int GetHour();
	int GetMinute();
	int GetSecond();

	void SetHour(int hour);
	void SetMinute(int hour);
	void SetSecond(int second);
private:
	int hour_;
	int minute_;
	int second_;
};
#endif//_CLOCK_H