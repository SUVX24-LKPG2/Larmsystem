#ifndef SETTINGS_H
#define SETTINGS_H

#include <map>
#include <string>
#include <string_view>

class Settings
{
private:
    std::map<std::string, std::string> m_settings;

public:
    Settings();
    ~Settings() = default;

    bool loadSettings(const std::string& filename);
    void saveSettings(const std::string& filename);

    std::string getSetting(std::string_view key) const;
    void setSetting(std::string_view key, std::string_view value);
};

#endif  // SETTINGS_H
