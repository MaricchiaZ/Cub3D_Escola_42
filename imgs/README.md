# 42-Cub3d

Este é o projeto Cub3d da Escola42, uma implementação do famoso jogo Wolfenstein 3D. O objetivo principal deste projeto é criar um ambiente gráfico usando a técnica de Raycasting, que é amplamente utilizada em jogos de primeira pessoa.

## Equipe
Projeto em dupla feito por Gabriel Issao (gissao-m) e Maria Clara (maclara-).

## Funcionalidades
- Ambiente gráfico 2D
- Movimentação em primeira pessoa
- Texturas e cores nas paredes
- Minimapa
- Colisões com paredes
- Sprites
- Arquivos de configuração personalizáveis

## Requisitos
- Sistema operacional: Linux (macOS também pode funcionar)
- GCC e Make instalados
- Biblioteca gráfica MinilibX

## Instalação
1. Clone este repositório em seu computador.
```bash
git clone https://github.com/seu-usuario/cub3d.git
``` 

2. Navegue até o diretório do projeto.
```bash
cd cub3d
``` 

3. Compile o projeto.
```bash
make
```

4. Execute o jogo.
```bash
./cub3D map/valid_maps/mini.cub
```

5. Configuração do Mapa

O mapa do jogo é definido em um arquivo .cub, que pode ser personalizado de acordo com suas preferências. O arquivo de exemplo map.cub incluído neste repositório demonstra a estrutura e as opções disponíveis.


## Controles
- W: mover para frente
- S: mover para trás
- A: mover para a esquerda
- D: mover para a direita
- Setas esquerda/direita: girar a câmera
- ESC: sair do jogo

## Contribuindo
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e enviar pull requests para melhorias, correções de bugs, etc.