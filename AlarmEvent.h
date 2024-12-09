#ifndef ALARMEVENT_H
#define ALARMEVENT_H
#include <string>
#include <ctime>
using namespace std;
class AlarmEvent
{
private: 
    string alarmtyp;
    tm alarmDate;
    tm alarmTime;
    string alarmMessage;

public:
    AlarmEvent(const string& type, tm& alarmDate, tm& alarmTime, string& alarmMessage);
}








#endif