# 🔺 Batalha Naval com Habilidades Especiais — Simulação em C

Este projeto apresenta uma simulação em linguagem C de um sistema de habilidades especiais aplicadas sobre um tabuleiro estilo Batalha Naval. Ele demonstra lógica de matrizes, sobreposição de áreas de efeito e manipulação de estruturas bidimensionais com validação de limites.

## 📌 Descrição

O programa simula três tipos de habilidades que afetam múltiplas posições em um tabuleiro 10x10:

- **Cone**: efeito em forma triangular apontando para baixo.
- **Cruz**: efeito nas linhas e colunas centrais.
- **Octaedro**: efeito em formato de losango (baseado em distância de Manhattan).

As habilidades são representadas por matrizes 5x5 com valores binários (`0` = não afetado, `1` = afetado). Essas matrizes são sobrepostas ao tabuleiro principal, e a área afetada é marcada com o valor `5`.

## 🧠 Conceitos aplicados

- Manipulação de **matrizes bidimensionais**
- Criação de **formas geométricas** via lógica condicional
- **Loops aninhados** e controle de borda
- Simulação de sobreposição de estruturas em memória
- Uso eficiente de estruturas básicas da linguagem C

## 📦 Como executar

```bash
gcc batalha_naval.c -o batalha
./batalha
