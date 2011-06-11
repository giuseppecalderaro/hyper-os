#ifndef __COMPILER_H__
#define __COMPILER_H__

#define __asmlinkage __attribute__((__regparm__(0)))
#define __fastcall __attribute__((__regparm__(3)))

#define __init __attribute__((__section__(".init")))
#define __inline __inline__ __attribute__((__always_inline__))
#define __noreturn __attribute__((__noreturn__))
#define __packed __attribute__((packed))

#endif /* __COMPILER_H__  */
