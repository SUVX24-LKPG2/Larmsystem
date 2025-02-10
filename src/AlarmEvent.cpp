#include "AlarmEvent.h"

#include <utility>

AlarmEvent::AlarmEvent() : alarmType(""), alarmMessage("")
{
    std::tm defaultTime = {};
    alarmDate           = defaultTime;
    alarmTime           = defaultTime;
}

AlarmEvent::AlarmEvent(std::string  type, const std::tm& date, const std::tm& time,
                       std::string  message)
    : alarmType(std::move(type)), alarmDate(date), alarmTime(time), alarmMessage(std::move(message))
{
}

std::string AlarmEvent::getAlarmType() const
{
    return alarmType;
}

void AlarmEvent::setAlarmType(const std::string& type)
{
    alarmType = type;
}

std::tm AlarmEvent::getAlarmDate() const
{
    return alarmDate;
}

void AlarmEvent::setAlarmDate(const std::tm& date)
{
    alarmDate = date;
}

std::tm AlarmEvent::getAlarmTime() const
{
    return alarmTime;
}

void AlarmEvent::setAlarmTime(const std::tm& time)
{
    alarmTime = time;
}

std::string AlarmEvent::getAlarmMessage() const
{
    return alarmMessage;
}

void AlarmEvent::setAlarmMessage(const std::string& message)
{
    alarmMessage = message;
}