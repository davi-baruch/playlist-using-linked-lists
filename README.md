# 🎵 Playlist utilizando linked lists

Projeto desenvolvido em C que aplica conceitos de listas duplamente encadeadas da disciplina **Estrutura de Dados** para simular uma playlist de música.

## Sobre

Cada música é representada por um nó de uma lista duplamente encadeada, permitindo navegação nos dois sentidos (próxima ou anterior) simulando um player real.

## Funcionalidades

 **Criação** de músicas e playlist (`create_music`, `create_playlist`)
**Inserção** de músicas no fim da playlist (`insert_music`)
**Remoção** de músicas, tratando os casos de cabeça, cauda, meio e lista com um único elemento (`remove_music`)
**Impressão** da playlist (`print_playlist`)
 **Navegação circular** — próxima/anterior música, com retorno automático ao início/fim da lista (`play_next_music`, `play_previous_music`, `play_current_music`, `play`)
**Busca por posição** (`search_music`)
**Mover música de posição** dentro da playlist (`move_music`)

## Estrutura do projeto

```
.
├── music.h        # struct Music + protótipos relacionados à música
├── music.c        # implementação das funções de música
├── playlist.h      # struct Playlist + protótipos relacionados à playlist
├── playlist.c      # implementação das funções de playlist
└── main.c          # testes das funções implementadas
```
