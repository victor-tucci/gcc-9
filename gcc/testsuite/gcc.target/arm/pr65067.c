/* { dg-do compile } */
/* { dg-require-effective-target arm_thumb2_ok } */
/* { dg-options "-mthumb -mcpu=cortex-m3 -O2" } */

struct tmp {
 unsigned int dummy;
 union {
  struct {
   unsigned int xyz : 1;
   unsigned int mode: 3;
   unsigned int res : 28;
  } bf;
  unsigned int wordval;
 } reg;
};

void set_mode(int mode)
{
 volatile struct tmp *t = (struct tmp *) 0x1000;
 t->reg.bf.mode = mode;
}

/* { dg-final { scan-assembler "bfi" } } */
