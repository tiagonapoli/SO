# Relatório EP4 - MAC422 Sistemas Operacionais

Ricardo Kojo - 10295429

Tiago Nápoli - 9345384

## Parte 1

Para esta parte, foi alterado apenas um arquivo:

> `usr/src/include/minix/`**`const.h`**
>
> Foi adicionado um novo tipode _i-node_: `I_TEMPORARY` de valor `0130000`

## Parte 2

Para a segunda parte, foram alterados/criados os seguintes arquivos:

> `/usr/src/include/minix/`**`callnr.h`**
>
> Criadas chamadas `OPENTMP`, `CREATTMP` e alterado o número de _calls_.

> `/usr/src/include/`**`stdio.h`**
>
> Declarado `PROTOTYPE` da função `FILE* open_tmp(const char *name, const char * mode)`.

> - `/usr/src/lib/stdio/`**`open_tmp.c`**
> - `/usr/src/lib/stdio/`**`Makefile.in`**
>
> Arquivo criado para implementar a função `open_tmp()` inspirada no `fopen()`

> - `/usr/src/servers/fs/`**`open.c`**
> - `/usr/src/servers/fs/`**`proto.h`**
> - `/usr/src/servers/fs/`**`table.c`**
> - `/usr/src/servers/fs/`**`read.c`**
>
> Criadas funções `do_open_tmp()`, `do_creat_tmp()`, `common_open_tmp()`.
>
> Adicionadas funções `do_open_tmp()` e `do_creat_tmp()` à tabela.
>
> Adicionada condição para ler arquivos temporários em `read.c`.

> `/usr/src/servers/pm/`**`table.c`**
>
> Adicionado valor `no_sys` à tabela de chamadas de sistemas no local que representa aS chamadaS criadas para o _file system_: `OPENTMP` e `CREATTMP`.

## Parte 3
