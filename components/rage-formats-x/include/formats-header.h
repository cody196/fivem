#define RAGE_FORMATS_GAME ny
#define RAGE_FORMATS_GAME_NY

#ifdef COMPILING_RAGE_FORMATS_X
#define FORMATS_EXPORT __declspec(dllexport)
#else
#define FORMATS_EXPORT __declspec(dllimport)
#endif

#define DEFAULT_IMPL __declspec(selectany)

#ifndef RAGE_FORMATS_GAME
#error "RAGE_FORMATS_GAME must be specified when including header files from rage-formats-x."
#endif

#define IS_RAGE_DEFINED_(game, file) RAGE_FORMATS_##game##_##file
#define IS_RAGE_DEFINED(game, file) IS_RAGE_DEFINED_(game, file)
#define IS_RAGE_GAME_DEFINED IS_RAGE_DEFINED(RAGE_FORMATS_GAME, RAGE_FORMATS_FILE)

#ifdef RAGE_FORMATS_OK
#undef RAGE_FORMATS_OK
#endif

#if !IS_RAGE_GAME_DEFINED
#define RAGE_FORMATS_OK
#endif

#ifdef RAGE_FORMATS_OK
#include <formats-namespace-header.h>
#endif