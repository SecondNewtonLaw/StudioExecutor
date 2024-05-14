//
// Created by Dottik on 13/5/2024.
//
#pragma once
#include <chrono>
#include <filesystem>
#include <string>

// TODO: Fix bug where data is NOT logged to the log file, rather pure strings.

#define LOG_TO_FILE_AND_CONSOLE(fname, msg, ...)                                                                       \
    (Log::get_singleton()->write_to_buffer(__FILE__, fname, msg));                                                     \
    (printf("[%s::%s] " msg "\r\n", __FILE__, fname, __VA_ARGS__))

/// Logger class.
class Log {
    static Log *sm_singleton;
    std::string m_szFileName;
    std::string m_szBuffer;
    Log() {
        char buf[0xffff];
        size_t readCount{0};
        getenv_s(&readCount, buf, sizeof(buf), "APPDATA");
        auto folder = std::format("{}\\RbxStu\\", buf);
        std::filesystem::create_directories(folder);
        this->m_szFileName = std::format("{}\\RbxStu\\RbxStuLog-{}.log", buf,
                                         (std::format("{:%d-%m-%Y_%H.%M.%S}", std::chrono::system_clock::now())));
    };

public:
    static Log *get_singleton();

    void write_to_buffer(const std::string &moduleName, const std::string &functionName, const std::string &logContent);

    std::string get_log_path();

    void flush_to_disk() const;
};
