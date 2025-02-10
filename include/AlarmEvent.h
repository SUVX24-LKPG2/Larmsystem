#ifndef ALARMEVENT_H
#define ALARMEVENT_H

#include <ctime>
#include <string>
using namespace std;

class AlarmEvent
{
    string alarmType;
    tm alarmDate;
    tm alarmTime;
    string alarmMessage;

public:
    AlarmEvent();
    AlarmEvent(string  type, const tm& date, const tm& time, string  message);
    string getAlarmType() const;
    void setAlarmType(const string& type);
    tm getAlarmDate() const;
    void setAlarmDate(const tm& date);
    tm getAlarmTime() const;
    void setAlarmTime(const tm& time);
    string getAlarmMessage() const;
    void setAlarmMessage(const string& Message);
};

#endif