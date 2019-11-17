#ifndef log_h
#define log_h

#include "spdlog/spdlog.h"

#include <string>
#include <memory>

#define nf_log_info(...) nf::logger::instance.log_info(__VA_ARGS__)
#define nf_log_error(...) nf::logger::instance.log_error(__VA_ARGS__)

namespace nf
{

class logger
{
public:
  static logger instance;

  logger();
  ~logger();
  template <typename... Args>
  static void log_info(Args &&... args)
  {
#if ANDROID
    android_logger->info(std::forward<Args>(args)...);
#else
    file_info_logger->info(std::forward<Args>(args)...);
    console_logger->info(std::forward<Args>(args)...);
#endif
  }

  template <typename... Args>
  static void log_error(Args &&... args)
  {
#if ANDROID
    android_logger->error(std::forward<Args>(args)...);
#else
    file_info_logger->error(std::forward<Args>(args)...);
    file_error_logger->error(std::forward<Args>(args)...);
    console_logger->error(std::forward<Args>(args)...);
#endif
  }

private:
#if ANDROID
  static std::shared_ptr<spdlog::logger> android_logger;
#else
  static std::shared_ptr<spdlog::logger> file_info_logger;
  static std::shared_ptr<spdlog::logger> file_error_logger;
  static std::shared_ptr<spdlog::logger> console_logger;
#endif
};

} // namespace jf

#endif