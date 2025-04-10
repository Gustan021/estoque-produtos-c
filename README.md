# 📦 Sistema de Controle de Estoque em C

Este projeto é um sistema simples de controle de estoque feito em linguagem C. Foi desenvolvido com o objetivo de praticar o uso de `structs`, `vetores`, `ponteiros` e a organização de código em funções separadas, simulando um sistema de gestão de produtos com menu interativo no terminal.

---

## 🚀 Funcionalidades

- ✅ Cadastro de novos produtos com identificador único
- ✅ Listagem completa dos produtos cadastrados
- ✅ Busca de produtos por **código**
- ✅ Atualização da **quantidade** de um produto por identificador
- ✅ Exclusão de produtos do estoque por identificador
- ✅ Controle de limite de até 10 produtos

---

## 🧠 Conceitos abordados

- `struct` para representar produtos
- Vetores de structs
- Manipulação de strings com `fgets`
- Uso de `scanf`, `getchar` e limpeza de buffer
- Organização modular: cada funcionalidade em uma função separada
- Uso de ponteiros e passagem por referência

---

## 📦 Estrutura do Produto

```c
struct produto {
    char nome[15];
    int codigo;
    float preco;
    int quantidade;
    int identificador;
};
```

---

## 💻 Menu do Sistema

```
Digite 1 para cadastrar um novo produto
Digite 2 para mostrar todos os produtos
Digite 3 para buscar um produto pelo código
Digite 4 para atualizar a quantidade de um produto em estoque
Digite 5 para a exclusão de algum produto desejado
Digite 6 para sair
```

---

## 🛠️ Como compilar e executar

### No Windows:
```bash
gcc estoque.c -o estoque.exe
./estoque.exe
```

### No Linux/Mac:
```bash
gcc estoque.c -o estoque
./estoque
```

> Obs: Caso esteja em outro sistema, remova `#include <windows.h>` e o uso de `SetConsoleOutputCP`.

---

## 👨‍💻 Autor

**Gustavo Santos Pereira**  
📍 Estudante de Ciência da Computação  
🧠 Foco em C, lógica de programação e desenvolvimento de sistemas base  
🔗 GitHub: [@Gustan021](https://github.com/Gustan021)
