# 🎓 Sistema de Gerenciamento Escolar em C

Projeto desenvolvido para a disciplina **INF029 – Laboratório de Programação** do **IFBA (Instituto Federal da Bahia)**.

## 📌 Descrição

Este projeto consiste em um sistema em linguagem C para gerenciamento básico de uma escola, permitindo o controle de:

* Alunos
* Professores
* Disciplinas
* Matrículas
* Relatórios diversos

O foco principal é aplicar conceitos de **modularização**, **organização de código** e **manipulação de dados em arquivos**.

---

## ⚙️ Funcionalidades

### 👨‍🎓 Alunos

* Cadastro (inserir, atualizar, remover)
* Listagem geral
* Listagem por sexo
* Ordenação por nome
* Ordenação por data de nascimento

### 👨‍🏫 Professores

* Cadastro (inserir, atualizar, remover)
* Listagem geral
* Listagem por sexo
* Ordenação por nome
* Ordenação por data de nascimento

### 📚 Disciplinas

* Cadastro de disciplinas
* Associação de professor
* Inserir/remover alunos da disciplina
* Listagem de disciplinas
* Listagem detalhada com alunos

### 📊 Relatórios

* Aniversariantes do mês
* Busca por nome (mínimo 3 caracteres)
* Alunos matriculados em menos de 3 disciplinas
* Disciplinas com mais de 40 alunos

---

## 🧱 Estrutura do Projeto

```
PROJETOESCOLA/
│
├── aluno/
├── professor/
├── disciplina/
├── utils/
│
├── main.c
└── .gitignore
```

Cada módulo possui:

* `.c` → implementação
* `.h` → definições e protótipos

---

## 💾 Armazenamento de Dados

Os dados são armazenados em arquivos `.txt`, permitindo persistência simples sem uso de banco de dados.

---

## 🛠️ Tecnologias Utilizadas

* Linguagem C
* Compilador GCC
* Manipulação de arquivos (`stdio.h`)
* Modularização com múltiplos arquivos `.c` e `.h`

---

## ▶️ Como Compilar

No terminal, execute:

```bash
gcc main.c aluno/aluno.c professor/professor.c disciplina/disciplina.c utils/menu.c utils/utils.c -o main
```

---

## ▶️ Como Executar

```bash
./main
```

No Windows:

```bash
main.exe
```

---

## 📋 Requisitos

* GCC instalado
* Sistema operacional Windows ou Linux

---

## 🧠 Conceitos Aplicados

* Modularização em C
* Separação de responsabilidades
* Manipulação de arquivos
* Estruturas de dados
* Validação de entrada de dados

---

## 📈 Critérios de Avaliação (segundo a proposta)

* ✔️ Corretude das funcionalidades
* ✔️ Organização e modularização do código
* ✔️ Baixo número de bugs

---

## 🚀 Possíveis Melhorias

* Interface gráfica
* Uso de banco de dados
* Melhor tratamento de erros
* Testes automatizados

---

## 👨‍💻 Autor

Desenvolvido por: **Eduardo Filho**
Curso: Análise e Desenvolvimento de Sistemas – IFBA

---
