#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define Test_DLLIMPORT __declspec(dllimport)
#  define Test_DLLEXPORT __declspec(dllexport)
#  define Test_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define Test_DLLIMPORT __attribute__((visibility("default")))
#    define Test_DLLEXPORT __attribute__((visibility("default")))
#    define Test_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define Test_DLLIMPORT
#    define Test_DLLEXPORT
#    define Test_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef Test_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define Test_DLLAPI
#  define Test_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef Test_EXPORTS
#    define Test_DLLAPI Test_DLLEXPORT
#  else
#    define Test_DLLAPI Test_DLLIMPORT
#  endif // Test_EXPORTS
#  define Test_LOCAL Test_DLLLOCAL
#endif // Test_STATIC