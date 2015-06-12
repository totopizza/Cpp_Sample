
#pragma once
#pragma warning (disable:4373)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include <iostream>
#include <streambuf>


namespace app_common {

  // デバッグコンソールに std::cout で出力できるようにする
  class DbgStreambuf : public std::streambuf {
  public:
    int_type overflow(const int_type c = EOF) {
      str_.push_back(c);
      return c;
    }

    int sync() {
      str_.push_back('\0');
      OutputDebugString(&str_[0]);
      str_.clear();
      return 0;
    }

  private:
    std::vector<TCHAR> str_;
  };


  class DbgOutput {
  public:
    // デバッグ出力を有効にする
    // NOTICE: 必ずアプリの setup() で実行する
    static void enableConsoleOutput() { static DbgOutput s_dbg_output; }

  private:
    DbgStreambuf    dbg_stream_;
    std::streambuf* stream_;

    DbgOutput() {
      _set_error_mode(_OUT_TO_MSGBOX);
      stream_ = std::cout.rdbuf(&dbg_stream_);
    }

    ~DbgOutput() { std::cout.rdbuf(stream_); }
  };
}

typedef app_common::DbgOutput  Dbg;
