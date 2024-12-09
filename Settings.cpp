#include "Settings.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

Settings::Settings() {}

bool Settings::loadSettings(const std::string& filename)
{
    std::ifstream file{filename};
    if (!file)
    {
        return false;
    }

    nlohmann::json j;
    file >> j;

    for (const auto& [key, value] : j.items())
    {
        m_settings[key] = value;
    }

    return true;
}

void Settings::saveSettings(const std::string& filename)
{
    nlohmann::json j;
    for (const auto& [key, value] : m_settings)
    {
        j[key] = value;
    }

    std::ofstream file{filename};
    file << j.dump(4);
}

std::string Settings::getSetting(std::string_view key) const
{
    auto it = m_settings.find(key.data());
    if (it != m_settings.end())
    {
        return it->second;
    }

    return "";
}

void Settings::setSetting(std::string_view key, std::string_view value)
{
    m_settings[std::string{key}] = std::string{value};
}