# Relatório EP2 - MAC422 Sistemas Operacionais

Ricardo Kojo - 10295429
Tiago Nápoli - 9345384

## Parte 1:

Para esta parte, foram alterados os seguintes arquivos:

- `usr/src/servers/is/`**`proto.h`**

Foi adicionado o `_PROTOTYPE` para a função `priority_dmp()`.

- `usr/src/servers/is/`**`dmp.c`**

Substuída a função `privileges_dmp()` por `priority_dmp()` na _key F4_.

- `usr/src/servers/is/`**`dmp_kernel.c`**

Criada a função `priority_dmp()` que imprime os processos e suas respectivas prioridades, baseado em outras funções de _dump_ presentes na mesma pasta.

## Parte 2:

Para a segunda parte, foram alterados/criados os seguintes arquivos:

```
/usr/src/servers/pm/chpriority.c (criado)
/usr/src/servers/pm/table.c
/usr/src/servers/pm/proto.h

/usr/src/servers/fs/table.c

/usr/src/include/minix/callnr.h
/usr/src/include/minix/com.h
/usr/src/include/minix/syslib.h
/usr/src/include/minix/unistd.h

/usr/src/kernel/system/do_priority.c (criado)
/usr/src/kernel/system/Makefile
/usr/src/kernel/system.c
/usr/src/kernel/system.h

/usr/src/lib/posix/Makefile
/usr/src/lib/posix/_chpriority.c (criado)

/usr/src/lib/syslib/Makefile
/usr/src/lib/syslib/sys_priority.c (criado)

/usr/src/lib/syscall/Makefile
/usr/src/lib/syscall/chpriority.s (criado)
```

Em geral, as alterações foram simples, baseando-se na _system call_ **FORK**. As funções mais complicadas, em `/usr/src/servers/pm/chpriority.c` e `/usr/src/kernel/system/do_priority.c`` foram baseadas na _system call_ **NICE**. 

Foram criadas definições de `_PROTOTYPE` e adicionadas interfaces de funções nas pastas `/usr/src/src/pm/` e `/usr/src/servers/fs`, _process manager_ e _file system_ respectivamente.

Na pasta `/usr/src/include/minix` foram adicionadas definições para a nova chamada de sistema.

Na pasta do _kernel_ - `/usr/src/kernel` - foi criado o arquivo que realmente possui a função que altera a prioridade de um processo. Além disso, foram criadas definições da função em `system.c` e `system.h`.

Nas pastas dentro da `/usr/src/lib`: `posix`, `syslib` e `syscall`, foram criados mais arquivos para definir a nova chamada de sistema, novamente baseado nos arquivos referentes à chamada **FORK**. Os arquivos criados foram adicionados aos arquivos `Makefile` para serem compilados.
