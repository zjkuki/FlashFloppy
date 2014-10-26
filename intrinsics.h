/*
 * intrinsics.h
 * 
 * Compiler intrinsics for ARMv7-M core.
 * 
 * Written & released by Keir Fraser <keir.xen@gmail.com>
 * 
 * This is free and unencumbered software released into the public domain.
 * See the file COPYING for more details, or visit <http://unlicense.org>.
 */

#ifndef __INTRINSICS_H__
#define __INTRINSICS_H__

#include <stdint.h>

struct exception_frame {
    uint32_t r0, r1, r2, r3, r12, lr, pc, psr;
};

#define illegal() asm volatile (".short 0xde00");

#define cpu_relax() asm volatile ("nop" ::: "memory")

#define read_special(reg) ({                        \
    uint32_t __x;                                   \
    asm volatile ("mrs %0,"#reg : "=r" (__x) ::);   \
    __x;                                            \
})

#define IRQ_global_disable() asm volatile ("cpsid i" ::: "memory")
#define IRQ_global_enable() asm volatile ("cpsie i" ::: "memory")

#endif /* __INTRINSICS_H__ */

/*
 * Local variables:
 * mode: C
 * c-file-style: "Linux"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
