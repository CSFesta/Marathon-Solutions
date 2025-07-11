import os
import urllib.parse

BASE_DIR = "SBC - fase zero"
PHASES = {
    "Fase0-22": 12,
    "Fase0-25": 12,
}

def format_line(phase, letter, name, solved):
    # Usa UTF-8 para nomes de pastas
    folder_name = f"{letter.lower()} - {name.lower()}"
    folder_path = os.path.join(BASE_DIR, phase, folder_name)
    github_url = f"https://github.com/CSFesta/Marathon-Solutions/tree/main/{urllib.parse.quote(folder_path, safe='/:')}"
    
    print(f"Verificando pasta: {folder_path}")
    if not os.path.isdir(folder_path):
        print(f"Pasta não encontrada: {folder_path}")
        return f"- ⬜ **{letter} - {name}** (Pasta não encontrada)"
    
    is_solved = any(f.endswith(('.cpp', '.py')) for f in os.listdir(folder_path))
    print(f"Arquivos .cpp/.py encontrados em {folder_path}: {is_solved}")
    
    if is_solved:
        solved.append(1)
        return f"- ✅ [**{letter} - {name}**]({github_url})"
    return f"- ⬜ **{letter} - {name}**"

def generate_readme():
    content = [
        "## ⚙️ Organização\n",
        "Cada pasta contém:",
        "- Códigos em **C++** (principalmente) e **Python** (em casos específicos)",
        "- Comentários explicativos sempre que necessário",
        "- Nome do problema + link oficial + breve explicação/resumo",
        "- Nível de dificuldade (com base em frequência de resolução: ex. 1/12 se for o problema mais resolvido em uma prova com 12 questões)\n",
        "### 🔗 Clicando nas questões resolvidas, você será direcionado para a pasta de resolução daquela questão!",
        "### ✅ Resolvido  ⬜ Não resolvido\n",
        "---\n"
    ]

    for phase, total in PHASES.items():
        solved_counter = []
        phase_path = os.path.join(BASE_DIR, phase)
        print(f"Processando fase: {phase_path}")
        try:
            folders = sorted(os.listdir(phase_path))
        except FileNotFoundError:
            print(f"Diretório não encontrado: {phase_path}")
            content.append(f"## 🚀 [**{phase.replace('-', ' - ')} (0 / {total})**](https://github.com/CSFesta/Marathon-Solutions/tree/main/{urllib.parse.quote(phase_path, safe='/:')}) \n")
            content.append(f"- ⚠️ **Diretório da fase não encontrado**\n")
            continue

        content.append(f"## 🚀 [**{phase.replace('-', ' - ')} ({len(solved_counter)} / {total})**](https://github.com/CSFesta/Marathon-Solutions/tree/main/{urllib.parse.quote(phase_path, safe='/:')}) \n")

        lines = []
        for folder in folders:
            if " - " in folder:
                try:
                    letter, name = folder.split(" - ", 1)
                    line = format_line(phase, letter, name, solved_counter)
                    lines.append(line)
                except ValueError:
                    print(f"Formato inválido para a pasta: {folder}")
                    lines.append(f"- ⚠️ **Formato inválido: {folder}**")
            else:
                print(f"Pasta ignorada (sem ' - '): {folder}")

        content[-len(lines) - 1] = content[-len(lines) - 1].replace(f"(0 / {total})", f"({len(solved_counter)} / {total})")
        content.extend(lines)
        content.append("")  # Quebra de linha entre fases

    with open("README.md", "w", encoding="utf-8") as f:
        f.write("\n".join(content))

if __name__ == "__main__":
    generate_readme()