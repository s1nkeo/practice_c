// // --- int f(int x, int y) ---
// // edi = x
// // esi = y
// // return value = eax
//  .globl  foo
//  .type foo, @function
// foo:
//  mov eax, edi
//  imul  eax, edi
//  imul  eax, edi
//  test  eax, eax
//  js  .L4
//  ret
//.L4:
//  imul  esi, esi
//  add edi, edi
//  mov edx, 17
//  sub edx, edi
//  sub edx, esi
//  add eax, edx
//  ret


int foo(int x, int y) {
    int a = x * x * x;

    if (a < 0)
        a += 17 - 2 * x - y * y;

    return a;
}
