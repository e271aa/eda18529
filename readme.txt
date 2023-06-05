bin/: pasta onde serão armazenados os arquivos executáveis após a compilação.

db/: pasta que contém o arquivo do banco de dados e o arquivo .c que contém as funções responsáveis por interagir com o banco de dados.

include/: pasta que contém os arquivos .h do projeto.

src/: pasta que contém os arquivos .c que implementam as funcionalidades do projeto.




*****regras de compilação*****

gcc -o programa arquivo.c

exemplo: gcc -o ..\bin\TESTE fase1.c cliente.c meio.c
gcc -o ..\bin\GreenGo main.c gestor.c meio.c cliente.c aluguer.c tools.c grafo.c