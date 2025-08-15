#!/bin/bash

# 1. Inicializa git se não existir
if [ ! -d ".git" ]; then
  echo "Inicializando repositório git local..."
  git init
else
  echo "Repositório git já inicializado."
fi

# 2. Adiciona arquivos .cpp e .h (com cuidado para espaços)
echo "Adicionando arquivos .cpp e .h..."
find . -name "*.cpp" -print0 | xargs -0 git add
find . -name "*.h" -print0 | xargs -0 git add

# 3. Commit inicial se não existir commit
if git rev-parse HEAD >/dev/null 2>&1; then
  echo "Commit já existe, pulando commit inicial."
else
  echo "Fazendo commit inicial..."
  git commit -m "Commit inicial"
fi

# 4. Cria repositório remoto no GitHub e faz push inicial
echo "Criando repositório remoto no GitHub e fazendo push..."
gh repo create "$(basename "$PWD")" --public --source=. --remote=origin --push --confirm

echo "Processo finalizado com sucesso!"
