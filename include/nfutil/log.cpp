
#include "log.h"
#if ANDROID
#include "spdlog/sinks/android_sink.h"
#else
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/async.h"
#include <chrono>
#endif

using namespace nf;

logger logger::instance;

#if ANDROID
std::shared_ptr<spdlog::logger> logger::android_logger;
#else
std::shared_ptr<spdlog::logger> logger::file_info_logger;
std::shared_ptr<spdlog::logger> logger::file_error_logger;
std::shared_ptr<spdlog::logger> logger::console_logger;
#endif

logger::logger()
{
#if ANDROID
  std::string tag = "spdlog-android";
  android_logger = spdlog::android_logger_mt("android", tag);
#else
  file_info_logger= spdlog::basic_logger_mt<spdlog::async_factory>("file_log", "logs/log.txt", true);
  file_error_logger = spdlog::basic_logger_mt<spdlog::async_factory>("file_error", "logs/error.txt", true);
  console_logger = spdlog::stdout_logger_mt("log");
  spdlog::flush_every(std::chrono::seconds(1));
#endif
}

logger::~logger(){
  // file_info_logger->flush();
  // file_error_logger->flush();
}