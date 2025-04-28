# 📝 To-Do List em C  

🔹 Este é um projeto simples de uma lista de tarefas (To-Do List) desenvolvido em linguagem C. O programa permite ao usuário gerenciar suas tarefas diárias através de um menu interativo no terminal.

<p align="center">
  <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExZWE3a2tyNGpjeXFrcnpwOHNtYTlld3lyc2d6d2ZxMDV0enA0bnBsMiZlcD12MV9naWZzX3NlYXJjaCZjdD1n/RjDIwuXYPzrAEjb6HP/giphy.gif" alt="To-Do List Demo" width="300">
</p>

---

## 🚀 Funcionalidades
- 📝 Visualizar tarefas: Mostra todas as tarefas cadastradas com numeração.
- 🗑️ Limpar lista: Remove todas as tarefas existentes.
- ➕ Adicionar tarefas: Permite adicionar novas tarefas uma a uma.

---

## ⚙️ Como Executar  

### Pré-requisitos  
- Compilador **GCC** (ou similar).  
- Terminal (Linux/Mac) ou **CMD/PowerShell** (Windows).  

### Passos  
1. **Compile o código**:  
   ```bash
   gcc to-do-list.c -o to-do-list


2. **Execute**
```bash
./todo       # Linux/Mac 
todo.exe     # Windows 
```

---

## 📂 Estrutura do Projeto
```bash
to-do-list/
│── to-do-list.c     # Código fonte principal
│── filename.txt     # Arquivo de tarefas (criado automaticamente)
└── README.md        # Este arquivo
```

---

## 💻 Estrutura do código

O programa está organizado em várias funções:

- `menu_principal():` Exibe o menu e gerencia a navegação
- `mostrar_tarefas():` Lista todas as tarefas do arquivo
- `limpar_lista():` Apaga todas as tarefas
- `add_tarefa():` Adiciona novas tarefas
- `limpar_tela():` Limpa o terminal
- `limpar_buffer():` Limpa o buffer de entrada

---

<p align="center"> ⭐️ *Deixe uma estrela* se este projeto te ajudou! ⭐️ </p>

---
