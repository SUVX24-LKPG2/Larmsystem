#ifndef ALARMEVENT_H
#define ALARMEVENT_H
#include <string>
#include <ctime>
using namespace std;
class AlarmEvent
{
private: 
    string alarmType;
    tm alarmDate;
    tm alarmTime;
    string alarmMessage;

public:
    AlarmEvent();
    AlarmEvent(const string& type, tm& date, tm& time, string& message);
    string getAlarmType() const;
    void setAlarmType(const string& type);
    tm getAlarmDate() const;
    void setAlarmDate(const tm& date);
    tm getAlarmTime() const;
    void setAlarmTime(const tm& time);
    string getAlarmMessage() const;
    void setAlarmMessage(const string& Message);

}








#endif