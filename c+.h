#include <stdlib.h>
#define PARENS ()

#define EXPAND(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__

#define FOR_EACH(macro, ...) __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...)                         \
  macro(a1)                                                     \
  __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER

#define classfm(funcbody) funcbody
#define classimpl(name, funcs...) FOR_EACH(classfm, funcs)
#define classfunc(cl, a, func, args...) _##cl##_##func(&a __VA_OPT__(,) args)
#define classnewf(cl, func, args...) _##cl##_##func(cl* this __VA_OPT__(,) args)
#define classtyp(name, in) typedef struct in name
#define class(name, in, funcs...) classtyp(Test, in); classimpl(name, funcs)
#define new(class, args...) _constructor_##class##_i_new(args)
#define constructor(class, args...) class _constructor_##class##_i_new(args)